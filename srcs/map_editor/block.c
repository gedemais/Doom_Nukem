#include "main.h"

static int	replace_with_face(t_env *env, int *pos, char face)
{
	int		i;

	i = -1;
	if (face == FACE_OUEST)
		pos[0]++;
	else if (face == FACE_EST)
		pos[0]--;
	else if (face == FACE_UP)
		pos[1]++;
	else if (face == FACE_BOTTOM)
		pos[1]--;
	else if (face == FACE_NORD)
		pos[2]--;
	else if (face == FACE_SUD)
		pos[2]++;
	if (!ft_inbounds(pos[0], 0, env->edit_env.new_map.width - 1)
			|| !ft_inbounds(pos[1], 0, env->edit_env.new_map.height - 1)
			|| !ft_inbounds(pos[2], 0, env->edit_env.new_map.depth - 1))
		return (1);
	return (0);
}

static t_mesh	*get_blockindex(t_map *map, int *pos, int *m_index)
{
	t_mesh	*mesh;
	int    i;

	i = -1;
	while (++i < map->meshs.nb_cells)
	{
		mesh = dyacc(&map->meshs, i);
		if (mesh->m_pos[0] == pos[0]
				&& mesh->m_pos[1] == pos[1]
				&& mesh->m_pos[2] == pos[2])
		{
			*m_index = i;
			break ;
		}
	}
	return (mesh);
}

static void			del_recursif(t_env *env, int x, int y, int z)
{
	t_mesh	*m;
	int    i;

	if (x < 0 || x > env->edit_env.new_map.width - 1
		|| y < 0 || y > env->edit_env.new_map.height - 1
		|| z < 0 || z > env->edit_env.new_map.depth - 1)
		return ;
	m = get_blockindex(&env->edit_env.map, (int[3]){x, y, z}, &i);
	if (m->type == BTXT_OBSIDIENNE)
	{
		m->type = BTXT_NONE;
		del_recursif(env, x - 1, y, z);
		del_recursif(env, x + 1, y, z);
		del_recursif(env, x, y + 1, z);
		del_recursif(env, x, y - 1, z);
		del_recursif(env, x, y, z + 1);
		del_recursif(env, x, y, z - 1);
	}
}

void				del_door(t_env *env)
{
	if (env->mid.mesh->type == BTXT_OBSIDIENNE)
	{
		del_recursif(env,
			env->mid.mesh->m_pos[0],
			env->mid.mesh->m_pos[1],
			env->mid.mesh->m_pos[2]);
	}
}

int			del_block(t_env *env)
{
	t_mesh	*mesh;
	int		pos[3];

	ft_memcpy(pos, &env->mid.mesh->m_pos, sizeof(int) * 3);
	mesh = env->mid.mesh;
	mesh->type = BTXT_NONE;
	env->edit_env.new_map.map[pos[0]][pos[1]][pos[2]] = BTXT_NONE;
	return (0);
}

int			put_block(t_env *env)
{
	t_mesh		*new;
	//t_triangle	*t;
	int			pos[3];
	int			m_index;
	int			i;

	i = 0;
	ft_memcpy(pos, &env->mid.mesh->m_pos, sizeof(int) * 3);
	if (replace_with_face(env, pos, env->mid.face_i))
		return (0);
	new = get_blockindex(&env->edit_env.map, pos, &m_index);
	new->type = env->edit_env.current_bt + 1;
	env->edit_env.new_map.map[pos[0]][pos[1]][pos[2]] = new->type;

	free_dynarray(&new->tris);
	if (env->edit_env.current_bc == BC_CUBE)
		create_cube(env, new, new->type);

	attribute_mesh(&env->edit_env.map, m_index);
	return (0);
}
