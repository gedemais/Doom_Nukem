#include "main.h"

void	assign_enemys_stats(t_enemy *enemy, char type)
{
	static int		hps[ENEMY_MAX] = {
		[ENEMY_CUBE] = 100
	};
	static int		damages[ENEMY_MAX] = {
		[ENEMY_CUBE] = 10
	};
	static float	speeds[ENEMY_MAX] = {
		[ENEMY_CUBE] = 0.1f
	};

	enemy->hp = hps[(int)type];
	enemy->damages = damages[(int)type];
	enemy->speed = speeds[(int)type];
}

int		enemy_map_mapper(char type)
{
	static int		map[ENEMY_MAX] = {
		[ENEMY_CUBE] = SCENE_UGLY
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

static int		copy_triangles(t_map *map, t_map *mob_map, t_mesh *m, t_mesh *new)
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
		t.textured = true;
		t.voxel = false;
		if (!handle_texture(map, dyacc(&mob_map->txts, t.sp), &t))
		{
			sprite = dyacc(&mob_map->txts, t.sp);
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

static int		copy_mob_to_scene(t_map *map, t_enemy *enemy)
{
	t_mesh		new;
	t_mesh		*m;
	int			i;

	i = 0;
	enemy->map_start = map->meshs.nb_cells;
	enemy->map_end = enemy->map_start + enemy->map->meshs.nb_cells;
	while (i < enemy->map->meshs.nb_cells)
	{
		ft_memset(&new, 0, sizeof(t_mesh));
		m = dyacc(&enemy->map->meshs, i);
		new.type = BTXT_LIGHT;
		if (init_dynarray(&new.tris, sizeof(t_triangle), 12)
			|| copy_triangles(map, enemy->map, m, &new)
			|| push_dynarray(&map->meshs, &new, false))
			return (-1);
		translate_mesh(map, dyacc(&map->meshs, map->nmesh), enemy->pos);
		map->nmesh++;
		i++;
	}
	return (0);
}

int		create_mob(t_env *env, t_map *map, char type, t_vec3d pos)
{
	t_enemy	enemy;

	ft_memset((void *)&enemy, 0, sizeof(t_enemy));
	assign_enemys_stats(&enemy, type);
	enemy.pos = pos;
	enemy.i = nodes_3d_1d(env->astar.dim, vec_fdiv(pos, 2));
	enemy.map = &env->maps[enemy_map_mapper(type)];
	if (copy_mob_to_scene(map, &enemy)
		|| push_dynarray(&env->mobs, &enemy, false))
		return (-1);
	return (0);
}
