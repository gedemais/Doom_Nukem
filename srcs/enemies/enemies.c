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
	int			i;
	t_vec3d		pos;

	i = rand() % (env->astar.d_nodes.nb_cells - 1);
	while (((t_node *)dyacc(&env->astar.d_nodes, i))->bobstacle == 1)
		i = rand() % (env->astar.d_nodes.nb_cells - 1);
	pos = ((t_node *)dyacc(&env->astar.d_nodes, i))->pos;
	return (create_mob(env, &env->edit_env.map, ENEMY_CUBE, pos));
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
