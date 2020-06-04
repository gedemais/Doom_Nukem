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

static int		spawn_mob(t_env *env)
{
	t_vec3d		pos;

	pos.x = rand() % (env->astar.width - 1);
	pos.y = rand() % (env->astar.height - 1);
	pos.z = rand() % (env->astar.depth - 1);
	pos.w = 0;

	pos.x = ((int)pos.x % 2) ? pos.x + 1 : pos.x;
	pos.y = ((int)pos.y % 2) ? pos.y + 1 : pos.y;
	pos.z = ((int)pos.z % 2) ? pos.z + 1 : pos.z;

	//t_vec3d pos = (t_vec3d){ 0, 2, 0, 0 };
	if (create_mob(env, &env->edit_env.map, ENEMY_CUBE, pos))
		return (-1);
	return (0);
}

int				handle_enemies(t_env *env)
{
	int 	nb_mobs = 10;

	while (env->mobs.nb_cells < nb_mobs)
	{	
		if (spawn_mob(env))
			return (-1);
	}
	enemies_movements(env);
	enemies_to_scene(env, &env->edit_env.map);
	return (0);
}
