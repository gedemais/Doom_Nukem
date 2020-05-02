#include "main.h"

static void	translate_triangle(t_env *env, t_mesh *new, t_triangle *t)
{
	int		i;
	int		scale;

	i = 0;
	scale = env->edit_env.new_map.scale / 50;
	while (i < 3)
	{
		// modifier la taille des cubes
		t->points[i].x += new->m_pos[0] * scale;
		t->points[i].y += new->m_pos[1] * scale;
		t->points[i].z += new->m_pos[2] * scale;
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
	mesh = dyacc(&env->maps[SCENE_CUBE].meshs, 0);
	if (init_dynarray(&new->tris, sizeof(t_triangle), 0))
		return (-1);
	while (i < mesh->tris.nb_cells)
	{
		ft_memcpy(&t, dyacc(&mesh->tris, i), sizeof(t_triangle));
		translate_triangle(env, new, &t);
		t.sp = get_type(env, new, type);
		t.textured = true;
		t.voxel = true;
		if (push_dynarray(&new->tris, &t, false))
			return (-1);
		i++;
	}
	return (0);
}

int			create_block(t_env *env, t_map *scene, char type, int *pos)
{
	t_mesh	new;

	new.type = type;
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
	if (init_dynarray(&scene->meshs, sizeof(t_mesh), 0))
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
	scene->nmesh = scene->meshs.nb_cells;
	return (0);
}
