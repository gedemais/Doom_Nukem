#include "main.h"

void	assign_enemys_stats(t_enemy *enemy, char type)
{
	static int		pvs[ENEMY_MAX] = {
		[ENEMY_CUBE] = 100
	};
	static int		damages[ENEMY_MAX] = {
		[ENEMY_CUBE] = 10
	};
	static float	speeds[ENEMY_MAX] = {
		[ENEMY_CUBE] = 1.0f
	};

	enemy->pv = pvs[(int)type];
	enemy->damages = damages[(int)type];
	enemy->speed = speeds[(int)type];
}

int		enemy_map_mapper(char type)
{
	static int		map[ENEMY_MAX] = {
		[ENEMY_CUBE] = SCENE_CUBE
	};

	return (map[(int)type]);
}

static int		copy_mob_to_scene(t_map *map, t_enemy *enemy)
{
	t_mesh		*m;
	t_triangle	*t;
	int			i;
	int			j;

	i = 0;
	enemy->map_start = map->meshs.nb_cells;
	enemy->map_end = enemy->map_start + enemy->map->meshs.nb_cells;
	while (i < enemy->map->meshs.nb_cells)
	{
		j = 0;
		m = dyacc(&enemy->map->meshs, i);
		m->type = BTXT_LIGHT;
		while (j < m->tris.nb_cells)
		{
			t = dyacc(&m->tris, j);
			t->voxel = true;
			t->sp = BTXT_LIGHT;
			j++;
		}
		if (push_dynarray(&map->meshs, m, false))
			return (-1);
		map->nmesh++;
		i++;
	}
	translate_mesh(map, enemy->mesh, enemy->pos);
	return (0);
}

int		create_mob(t_env *env, t_map *map, char type, t_vec3d pos)
{
	t_enemy	enemy;

	enemy.pos = pos;
	enemy.map = &env->maps[enemy_map_mapper(type)];
	enemy.mesh = dyacc(&enemy.map->meshs, 0);
	if (copy_mob_to_scene(map, &enemy)
		|| push_dynarray(&env->mobs, &enemy, false))
		return (-1);
	return (0);
}
