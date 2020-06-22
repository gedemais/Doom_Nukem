#include "main.h"

static bool		check_type(int type)
{
	return (ft_inbounds(type, 1, 31)
		|| (ft_inbounds(type, 160, 191) && type != 163));
}

static char		check_face(t_ed_map *map, char type, int *pos)
{
	if (pos[0] < 0 || pos[0] > map->width - 1
		|| pos[1] < 0 || pos[1] > map->height - 1
		|| pos[2] < 0 || pos[2] > map->depth - 1)
		return (0);
	return (check_type(map->map[pos[0]][pos[1]][pos[2]]) ? 0 : type);
}

void			cull_faces(t_env *env, t_mesh *new, t_triangle *tri)
{
	int		*pos;

	pos = new->m_pos;
	if (tri->face_i == FACE_NORD)
		tri->sp = check_face(&env->edit_env.new_map, new->type,
			(int[3]){ pos[0], pos[1], pos[2] - 1});
	else if (tri->face_i == FACE_SUD)
		tri->sp = check_face(&env->edit_env.new_map, new->type,
			(int[3]){ pos[0], pos[1], pos[2] + 1});
	else if (tri->face_i == FACE_EST)
		tri->sp = check_face(&env->edit_env.new_map, new->type,
			(int[3]){ pos[0] - 1, pos[1], pos[2] });
	else if (tri->face_i == FACE_OUEST)
		tri->sp = check_face(&env->edit_env.new_map, new->type,
			(int[3]){ pos[0] + 1, pos[1], pos[2] });
	else if (tri->face_i == FACE_UP)
		tri->sp = check_face(&env->edit_env.new_map, new->type,
			(int[3]){ pos[0], pos[1] + 1, pos[2] });
	else if (tri->face_i == FACE_BOTTOM)
		tri->sp = check_face(&env->edit_env.new_map, new->type,
			(int[3]){ pos[0], pos[1] - 1, pos[2] });
}

void			culling(t_env *env, t_mesh *new)
{
	int			i;
	t_triangle	*tri;

	//add slopes culling

	if ((!ft_inbounds(new->type, 1, 31) && !ft_inbounds(new->type, 160, 191))
		|| new->type == BTXT_NONE)
		return ;
	i = -1;
	while (++i < new->tris.nb_cells)
	{
		tri = dyacc(&new->tris, i);
		cull_faces(env, new, tri);
	}
}
