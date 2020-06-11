#include "main.h"

static void		enemies_to_scene(t_dynarray *mobs)
{
	int		i;
	int		j;
	t_mesh	*m;
	t_enemy	*mob;

	i = -1;
	while (++i < mobs->nb_cells)
	{
		mob = dyacc(mobs, i);
		j = mob->map_start - 1;
		while (++j < mob->map_end)
		{
			m = dyacc(&mob->map->meshs, j);
			translate_mesh(mob->map, m, vec_sub(mob->pos, m->corp.pos));
		}
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

	//pos = (t_vec3d){ 0, 2, 0, 0 };

	return (create_mob(env, &env->edit_env.map, ENEMY_CUBE, pos));
}

int				handle_enemies(t_env *env)
{
	int 		nb_mobs = 10;
	static int	i = -1;

	while (++i < nb_mobs)
	{	
		if (spawn_mob(env))
			return (-1);
	}
	enemies_movements(env, &env->astar);
	enemies_death(&env->mobs);
	if (env->mobs.nb_cells)
		enemies_to_scene(&env->mobs);
	return (0);
}
