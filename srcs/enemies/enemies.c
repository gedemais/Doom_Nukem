#include "main.h"

static void		enemies_to_scene(t_env *env, t_map *map)
{
	int		i;
	t_mesh	*m;
	t_enemy	*mob;

	i = -1;
	while (++i < env->mobs.nb_cells)
	{
		mob = dyacc(&env->mobs, i);
		m = dyacc(&map->meshs, mob->map_start);
		translate_mesh(map, m, vec_sub(mob->pos, m->corp.pos));
	}
}

static int		test_mob(t_env *env)
{
	t_vec3d	pos;

	pos = (t_vec3d){0, 2, 0, 0};
	if (env->mobs.nb_cells == 0)
	{
		if (create_mob(env, &env->edit_env.map, ENEMY_CUBE, pos))
			return (-1);
	}
	return (0);
}

int				handle_enemies(t_env *env)
{
	if (test_mob(env))
		return (-1);
	enemies_movements(env);
	enemies_to_scene(env, &env->edit_env.map);
	return (0);
}
