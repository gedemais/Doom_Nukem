#include "main.h"

int			create_cube(t_env *env, t_mesh *new, char type)
{
	t_mesh		*mesh;
	int			*pos;
	t_triangle	t;
	int			i;

	i = 0;
	new->type = get_block_type(env, new, type);
	mesh = dyacc(&env->maps[SCENE_CUBE].meshs, 0);
	pos = new->m_pos;
	if (init_dynarray(&new->tris, sizeof(t_triangle), 0))
		return (-1);
	while (i < mesh->tris.nb_cells)
	{
		ft_memcpy(&t, dyacc(&mesh->tris, i), sizeof(t_triangle));
		translate_triangle(new, &t);
		t.textured = true;
		t.voxel = true;
		t.sp = new->type;
		if (push_dynarray(&new->tris, &t, false))
			return (-1);
		i++;
	}
	((t_triangle*)dyacc(&new->tris, 5))->face_i = FACE_NORD;
	((t_triangle*)dyacc(&new->tris, 11))->face_i = FACE_NORD;
	((t_triangle*)dyacc(&new->tris, 1))->face_i = FACE_SUD;
	((t_triangle*)dyacc(&new->tris, 7))->face_i = FACE_SUD;
	((t_triangle*)dyacc(&new->tris, 2))->face_i = FACE_BOTTOM;
	((t_triangle*)dyacc(&new->tris, 8))->face_i = FACE_BOTTOM;
	((t_triangle*)dyacc(&new->tris, 3))->face_i = FACE_OUEST;
	((t_triangle*)dyacc(&new->tris, 9))->face_i = FACE_OUEST;
	((t_triangle*)dyacc(&new->tris, 4))->face_i = FACE_UP;
	((t_triangle*)dyacc(&new->tris, 10))->face_i = FACE_UP;
	((t_triangle*)dyacc(&new->tris, 0))->face_i = FACE_EST;
	((t_triangle*)dyacc(&new->tris, 6))->face_i = FACE_EST;
	return (0);
}

static int	get_slope_obj(char type)
{
	if (ft_inbounds((int)type, 32, 63))
		return (SCENE_PENTE_NORD);
	else if (ft_inbounds((int)type, 64, 95))
		return (SCENE_PENTE_SUD);
	else if (ft_inbounds((int)type, 96, 127))
		return (SCENE_PENTE_OUEST);
	else if (ft_inbounds((int)type, 128, 159))
		return (SCENE_PENTE_EST);
	return (-1);
}

int		create_slope(t_env *env, t_mesh *new, char type)
{
	t_mesh		*mesh;
	t_triangle	t;
	int			obj;
	int			i;

	i = 0;
	new->type = get_block_type(env, new, type);
	if ((obj = get_slope_obj(type)))
		return (-1);
	mesh = dyacc(&env->maps[obj].meshs, 0);
	if (init_dynarray(&new->tris, sizeof(t_triangle), 0))
		return (-1);
	while (i < mesh->tris.nb_cells)
	{
		ft_memcpy(&t, dyacc(&mesh->tris, i), sizeof(t_triangle));
		translate_triangle(new, &t);
		t.textured = true;
		t.voxel = true;
		t.sp = new->type;
		if (push_dynarray(&new->tris, &t, false))
			return (-1);
		i++;
	}
	return (0);
}
