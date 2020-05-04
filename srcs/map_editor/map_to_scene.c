#include "main.h"

static void	translate_triangle(t_mesh *new, t_triangle *t)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		// modifier la taille des cubes
		t->points[i].x += new->m_pos[0] * 2;
		t->points[i].y += new->m_pos[1] * 2;
		t->points[i].z += new->m_pos[2] * 2;
		i++;
	}
}
/*
static int      test_neighbours(t_ed_map *map, int x, int y , int z)
{
	if (x < 0 || x > map->width - 1
		|| y < 0 || y > map->height - 1
		|| z < 0 || z > map->depth - 1)
		return (0);
	return (map->map[x][y][z] > BTXT_NONE ? 1 : 0);
}

static bool		full_neighbours(t_ed_map *map, int *pos)
{
	int     neighbours;

	neighbours = 0;
	neighbours += test_neighbours(map, pos[0] - 1, pos[1], pos[2]);
	neighbours += test_neighbours(map, pos[0] + 1, pos[1], pos[2]);
	neighbours += test_neighbours(map, pos[0], pos[1] - 1, pos[2]);
	neighbours += test_neighbours(map, pos[0], pos[1] + 1, pos[2]);
	neighbours += test_neighbours(map, pos[0], pos[1], pos[2] - 1);
	neighbours += test_neighbours(map, pos[0], pos[1], pos[2] + 1);
	return (neighbours == 6);
}*/


static int	get_type(t_env *env, t_mesh *new, char type)
{
	int		ret;

	(void)env;
	(void)new;
	(void)type;
	ret = (int)type % 32;
	printf("%d\n", ret);
//	if (env->context == C_CUSTOM)
//		if (full_neighbours(&env->edit_env.new_map, new->m_pos))
//			ret = BTXT_NONE;
	return (ret);
}

int			create_cube(t_env *env, t_mesh *new, char type)
{
	t_mesh		*mesh;
	t_triangle	t;
	int			i;

	i = 0;
	new->type = get_type(env, new, type);
	mesh = dyacc(&env->maps[SCENE_CUBE].meshs, 0);
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
	((t_triangle*)dyacc(&new->tris, 1))->face_i = FACE_SUD;
	((t_triangle*)dyacc(&new->tris, 7))->face_i = FACE_SUD;
	((t_triangle*)dyacc(&new->tris, 5))->face_i = FACE_NORD;
	((t_triangle*)dyacc(&new->tris, 11))->face_i = FACE_NORD;
	((t_triangle*)dyacc(&new->tris, 3))->face_i = FACE_BOTTOM;
	((t_triangle*)dyacc(&new->tris, 9))->face_i = FACE_BOTTOM;
	((t_triangle*)dyacc(&new->tris, 4))->face_i = FACE_OUEST;
	((t_triangle*)dyacc(&new->tris, 10))->face_i = FACE_OUEST;
	((t_triangle*)dyacc(&new->tris, 0))->face_i = FACE_UP;
	((t_triangle*)dyacc(&new->tris, 6))->face_i = FACE_UP;
	((t_triangle*)dyacc(&new->tris, 2))->face_i = FACE_EST;
	((t_triangle*)dyacc(&new->tris, 8))->face_i = FACE_EST;
	return (0);
}

void	attribute_mesh(t_map *scene, int index)
{
	t_mesh		*mesh;
	t_triangle	*t;
	int		i;

	i = 0;
	mesh = dyacc(&scene->meshs, index);
	while (i < mesh->tris.nb_cells)
	{
		t = dyacc(&mesh->tris, i);
		t->mesh = mesh;
		i++;
	}
}

static int	create_block(t_env *env, t_map *scene, char type, int *pos)
{
	t_mesh	new;
	int		i;

	i = 0;
	new.pitch = 0;
	new.yaw = 0;
	new.roll = 0;
	ft_memcpy(new.m_pos, pos, sizeof(int) * 3);
	if (ft_inbounds(type, 0, 31) && create_cube(env, &new, type))
		return (-1);
	/*	else if (ft_inbounds(type, 32, 63))
		return (create_slope_north(env, &new, type));
		else if (ft_inbounds(type, 64, 95))
		return (create_slope_south(env, &new, type));
		else if (ft_inbounds(type, 96, 127))
		return (create_slope_west(env, &new, type));
		else if (ft_inbounds(type, 128, 159))
		return (create_slope_est(env, &new, type));*/
	if (push_dynarray(&scene->meshs, &new, false))
		return (-1);
	attribute_mesh(scene, scene->nmesh);
	scene->nmesh = scene->meshs.nb_cells;
	return (0);
}

int			map_to_scene(t_env *env)
{
	t_edit_env	*edit_env;
	t_map		*scene;
	int			x;
	int			y;
	int			z;

	x = -1;
	edit_env = &env->edit_env;
	scene = &edit_env->map;
	if (init_dynarray(&scene->meshs, sizeof(t_mesh), MAX_CHUNKS))
		return (-1);
	while (++x < edit_env->new_map.width)
	{
		y = -1;
		while (++y < edit_env->new_map.height)
		{
			z = -1;
			while (++z < edit_env->new_map.depth)
				if (create_block(env, scene, edit_env->new_map.map[x][y][z],
						(int[3]){x, y, z}))
					return (-1);
		}
	}
	scene->spawn = (t_vec3d){0, 0, 0, 0};
	return (0);
}
