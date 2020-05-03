#include "main.h"

static void		replace_with_face(int *pos, char face)
{
	if (face == FACE_OUEST)
		pos[0]--;
	else if (face == FACE_EST)
		pos[0]++;
	else if (face == FACE_UP)
		pos[1]--;
	else if (face == FACE_BOTTOM)
		pos[1]++;
	else if (face == FACE_NORD)
		pos[2]++;
	else if (face == FACE_SUD)
		pos[2]--;
}

static t_mesh	*get_blockindex(t_map *map, int *pos)
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
			break ;
    }
    return (mesh);
}

int			put_block(t_env *env)
{
	t_mesh		*new;
	t_triangle	*t;
	int			pos[3];
	int			i;

	i = 0;
	ft_memcpy(pos, &env->mid.mesh->m_pos, sizeof(int) * 3);
	replace_with_face(pos, env->mid.face_i);
	new = get_blockindex(&env->edit_env.map, pos);
	new->type = BTXT_IRON;
	while (i < new->tris.nb_cells)
	{
		t = dyacc(&new->tris, i);
		t->sp = new->type;
		i++;
	}
	return (0);
}
