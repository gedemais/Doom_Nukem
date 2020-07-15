#include "main.h"

static void		enemies_check_neighbours(t_pf *a, t_enemy *mob)
{
	int 	i;
	t_node	*node;

	i = -1;
	while (++i < NEIGHBOURG)
	{
		node = dyacc(&a->d_nodes, mob->end->nghbr[i]);
		if (node && node->bobstacle == 0)
			mob->end = node;
	}
}

static int		enemies_get_closer_end(t_pf *a, t_enemy *mob)
{
	t_vec3d	end;

	while (vec3d_dist(mob->goal->pos, mob->end->pos) > 3)
	{
		end.x = (int)(mob->end->pos.x / 2 + mob->goal->pos.x / 2);
		end.y = (int)(mob->end->pos.y / 2 + mob->goal->pos.y / 2);
		end.z = (int)(mob->end->pos.z / 2 + mob->goal->pos.z / 2);
		if (vec_outrange(a->dim, end))
			return (-1);
		mob->end = dyacc(&a->d_nodes, nodes_3d_1d(a->dim, end));
		if (mob->end == NULL)
			return (-1);
	}
	if (mob->end->bobstacle == 1)
		enemies_check_neighbours(a, mob);
	return (mob->end->bobstacle);
}

static void		enemies_get_end(t_pf *a, t_enemy *mob, t_vec3d cam)
{
	a->end = NULL;
	mob->end = NULL;
	if (mob->goal == NULL)
		return ;
	cam.x = (int)cam.x / 2;
	cam.y = (int)cam.y / 2;
	cam.z = (int)cam.z / 2;
	if (vec_outrange(a->dim, cam))
		return ;
	if (vec3d_dist(a->start->pos, cam) < DIST_TO_PLAYER)
		return ;
	mob->end = dyacc(&a->d_nodes, nodes_3d_1d(a->dim, cam));
	if (mob->end == NULL)
		return ;
	if (enemies_get_closer_end(a, mob))
		mob->end = NULL;
	a->end = mob->end;
}

void			enemies_movements(t_env *env, t_pf *a)
{
	int		i;
	t_enemy	*mob;

	i = -1;
	while (++i < env->custom_env.mobs.nb_cells)
	{
		mob = dyacc(&env->custom_env.mobs, i);
		if (mob->hp < 1)
			continue ;
		a->start = dyacc(&a->d_nodes, mob->i);
		if (mob->end == NULL || mob->i == mob->end->i)
		{
			mob->goal = a->start;
			enemies_get_end(a, mob, env->cam.stats.pos);
			astar(a);
			if (a->end == NULL || mob->end == NULL || mob->goal == NULL)
			{
				enemies_last_rotation(mob, env->cam.stats.pos);
				mob->end = NULL;
				continue ;
			}
		}
		enemies_do_movement(env, mob);
	}
}
