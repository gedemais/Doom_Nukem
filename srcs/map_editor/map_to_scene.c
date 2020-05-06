#include "main.h"

void	translate_triangle(t_mesh *new, t_triangle *t)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		t->points[i].x += new->m_pos[0] * 2;
		t->points[i].y += new->m_pos[1] * 2;
		t->points[i].z += new->m_pos[2] * 2;
		i++;
	}
}

static int      test_neighbours(t_ed_map *map, int x, int y , int z)
{
	if (x < 0 || x > map->width - 1
		|| y < 0 || y > map->height - 1
		|| z < 0 || z > map->depth - 1)
		return (0);
	return (map->map[x][y][z] > BTXT_NONE);
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
}


int		get_block_type(t_env *env, t_mesh *new, char type)
{
	int		ret;

	if (ft_inbounds(type, 0, 160))
		ret = (int)type % 32;
	else
		ret = 0;
	if (env->context == C_CUSTOM)
		if (full_neighbours(&env->edit_env.new_map, new->m_pos))
			ret = BTXT_NONE;
	return (ret);
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
	if (ft_inbounds(type, 0, 31) && create_slope_north(env, &new, type))
		return (-1);
//	else if (ft_inbounds(type, 32, 63) && create_slope_north(env, &new, type))
//		return (-1);
	/*	else if (ft_inbounds(type, 64, 95))
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
				if (create_block(env, scene,
					edit_env->new_map.map[x][y][z], (int[3]){x, y, z}))
					return (-1);
		}
	}
	scene->spawn = (t_vec3d){0, 0, 0, 0};
	return (0);
}
