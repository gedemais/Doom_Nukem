#include "main.h"

void	assign_enemys_stats(t_enemy *enemy, char type)
{
	static int		hps[ENEMY_MAX] = {
		[ENEMY_CORONA] = 100
	};
	static int		damages[ENEMY_MAX] = {
		[ENEMY_CORONA] = 10
	};
	static float	speeds[ENEMY_MAX] = {
		[ENEMY_CORONA] = 0.05f
	};

	enemy->hp = hps[(int)type];
	enemy->damages = damages[(int)type];
	enemy->speed = speeds[(int)type];
}

int		enemy_map_mapper(char type)
{
	static int		map[ENEMY_MAX] = {
		[ENEMY_CORONA] = SCENE_MAGE
		//[ENEMY_MAGE] = SCENE_MAGE
	};

	return (map[(int)type]);
}

static bool		handle_texture(t_map *map, t_sprite *sprite, t_triangle *new)
{
	int			i;

	i = -1;
	if (!map->txts.byte_size)
		return (false);
	while (++i < map->txts.nb_cells)
		if (!ft_memcmp(sprite, dyacc(&map->txts, i), sizeof(t_sprite)))
		{
			new->sp = i;
			return (true);
		}
	return (false);
}

int			copy_triangles(t_map *map, t_map *mob, t_mesh *m, t_mesh *new)
{
	t_sprite	*sprite;
	t_triangle	t;
	int			i;

	i = 0;
	if (!map->txts.byte_size && init_dynarray(&map->txts, sizeof(t_sprite), 0))
		return (-1);
	while (i < m->tris.nb_cells)
	{
		ft_memcpy(&t, dyacc(&m->tris, i), sizeof(t_triangle));
		t.voxel = false;
		if (t.textured && !handle_texture(map, dyacc(&mob->txts, t.sp), &t))
		{
			sprite = dyacc(&mob->txts, t.sp);
			if (push_dynarray(&map->txts, sprite, false))
				return (-1);
			t.sp = map->txts.nb_cells - 1;
		}
		if (push_dynarray(&new->tris, &t, false))
			return (-1);
		i++;
	}
	return (0);
}

static int		copy_mob_to_scene(t_map *map, t_map *mob, t_enemy *enemy)
{
	t_mesh		new;
	t_mesh		*m;
	int			i;

	i = 0;
	enemy->map_start = map->meshs.nb_cells;
	enemy->map_end = enemy->map_start + mob->meshs.nb_cells;
	while (i < mob->meshs.nb_cells)
	{
		ft_memset(&new, 0, sizeof(t_mesh));
		m = dyacc(&mob->meshs, i);
		new.type = 1;
		new.index = map->nmesh;
		if (init_dynarray(&new.tris, sizeof(t_triangle), 12)
			|| copy_triangles(map, mob, m, &new)
			|| push_dynarray(&map->meshs, &new, false))
			return (-1);
		assign_meshs(dyacc(&map->meshs, map->nmesh));
		translate_mesh(map, dyacc(&map->meshs, map->nmesh), enemy->pos);
		map->nmesh++;
		i++;
	}
	return (0);
}

static int 		enemy_offset(t_enemy *mob)
{
	int			i;
	int			j;
	t_mesh 		*mesh;
	t_triangle	*tri;

	i = mob->map_start - 1;
	while (++i < mob->map_end)
	{
		mesh = dyacc(&mob->map->meshs, i);
		j = -1;
		while (++j < mesh->tris.nb_cells)
		{
			tri = dyacc(&mesh->tris, j);
			tri->points[0] = vec_add(tri->points[0], mob->offset);
			tri->points[1] = vec_add(tri->points[1], mob->offset);
			tri->points[2] = vec_add(tri->points[2], mob->offset);
		}
	}
	return (0);
}

int		create_mob(t_env *env, t_map *map, char type, t_vec3d pos)
{
	t_enemy	enemy;

	ft_memset((void *)&enemy, 0, sizeof(t_enemy));
	assign_enemys_stats(&enemy, type);

	enemy.head = (t_vec3d){ 0, 0, 1, 0 };
	enemy.offset = (t_vec3d){ 0, 1, 0, 0 };
	enemy.peace = MOB_PEACE_TIME;
	enemy.pos = pos;
	enemy.i = nodes_3d_1d(env->astar.dim, vec_fdiv(pos, 2));
	enemy.map = map;

	if (copy_mob_to_scene(map, &env->maps[enemy_map_mapper(type)], &enemy)
		|| enemy_offset(&enemy)
		|| push_dynarray(&env->custom_env.mobs, &enemy, false))
		return (-1);
	return (0);
}
