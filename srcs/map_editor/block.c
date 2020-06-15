#include "main.h"

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
	if (env->mid.mesh && env->mid.mesh->type == BTXT_OBSIDIENNE)
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

	if (!env->mid.mesh)
		return (0);
	mesh = env->mid.mesh;
	ft_memcpy(pos, mesh->m_pos, sizeof(int) * 3);
	mesh->type = BTXT_NONE;
	env->edit_env.new_map.map[pos[0]][pos[1]][pos[2]] = BTXT_NONE;
	return (0);
}

int			replace_block(t_env *env)
{
	int		pos[3];
	t_mesh	*mesh;
	int		i;
	char	bt;

	i = -1;
	if (!env->mid.mesh)
		return (0);
	mesh = env->mid.mesh;
	bt = (env->edit_env.current_bt == 0) ? 1 : env->edit_env.current_bt;
	ft_memcpy(pos, mesh->m_pos, sizeof(int) * 3);
	if (env->events.buttons[BUTTON_SCLIC])
		if (env->events.buttons[BUTTON_SCROLL_UP]
			|| env->events.buttons[BUTTON_SCROLL_DOWN])
		{
			mesh->type = bt;
			env->edit_env.new_map.map[pos[0]][pos[1]][pos[2]] = bt;
			while (++i < mesh->tris.nb_cells)
				((t_triangle*)dyacc(&mesh->tris, i))->sp = mesh->type;
		}
	return (0);
}

int			put_block(t_env *env)
{
	t_mesh		*new;
	int			pos[3];
	int			m_index;
	char		bc;

	bc = env->edit_env.current_bc;
	ft_memcpy(pos, &env->mid.mesh->m_pos, sizeof(int) * 3);
	if (replace_by_face(env, pos, env->mid.face_i, env->edit_env.new_map.map[pos[0]][pos[1]][pos[2]]))
		return (0);
	new = get_blockindex(&env->edit_env.map, pos, &m_index);
	new->type = env->edit_env.current_bt + 1;
	env->edit_env.new_map.map[pos[0]][pos[1]][pos[2]] = new->type;

	free_dynarray(&new->tris);

	if(bc == BC_CUBE || bc == BC_OBJ)
		create_cube(env, new, new->type);
	else if (ft_inbounds(bc, BC_SLOPE_NORD, BC_SLOPE_EST))
		create_slope(env, new, new->type);
	attribute_mesh(&env->edit_env.map, m_index);
	return (0);
}
