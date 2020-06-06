#include "main.h"

static void		enemies_check_neighbourgs(t_pf *a, t_enemy *mob)
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

static bool		enemies_vec_outrange(t_vec3d dim, t_vec3d pos)
{
	return (pos.x < 0 || pos.x > dim.x - 1
		|| pos.y < 0 || pos.y > dim.y - 1
		|| pos.z < 0 || pos.z > dim.z - 1);
}

static int		enemies_get_closer_end(t_pf *a, t_enemy *mob)
{
	t_vec3d	end;

	while (astar_distance(mob->goal->pos, mob->end->pos) > 3)
	{
		end.x = (int)(mob->end->pos.x / 2 + mob->goal->pos.x / 2);
		end.y = (int)(mob->end->pos.y / 2 + mob->goal->pos.y / 2);
		end.z = (int)(mob->end->pos.z / 2 + mob->goal->pos.z / 2);
		if (enemies_vec_outrange(a->dim, end))
			return (-1);
		mob->end = dyacc(&a->d_nodes, nodes_3d_1d(a->dim, end));
		if (mob->end == NULL)
			return (-1);
	}
	if (mob->end->bobstacle == 1)
		enemies_check_neighbourgs(a, mob);
	return (0);
}

static void		enemies_get_end(t_pf *a, t_enemy *mob, t_vec3d cam)
{
	mob->end = NULL;
	if (mob->goal == NULL)
		return ;
	cam.x = (int)cam.x / 2;
	cam.y = (int)cam.y / 2;
	cam.z = (int)cam.z / 2;
	if (enemies_vec_outrange(a->dim, cam))
		return ;
	if (astar_distance(a->start->pos, cam) < 3)
		return ;
	mob->end = dyacc(&a->d_nodes, nodes_3d_1d(a->dim, cam));
	if (mob->end == NULL)
		return ;
	if (enemies_get_closer_end(a, mob))
		mob->end = NULL;
	if (mob->end && mob->end->bobstacle == 1)
		mob->end = NULL;
	a->end = mob->end;
}

void			enemies_movements(t_env *env)
{
	int		i;
	t_enemy	*mob;
	t_pf	*a;

	a = &env->astar;
	i = -1;
	while (++i < env->mobs.nb_cells)
	{
		mob = dyacc(&env->mobs, i);
		a->start = dyacc(&a->d_nodes, mob->i);
		if (mob->end == NULL || mob->i == mob->end->i)
		{
			mob->goal = a->start;
			enemies_get_end(a, mob, env->cam.stats.pos);
			astar(a);
			if (a->end == NULL || mob->end == NULL || mob->goal == NULL)
			{
				mob->end = NULL;
				continue ;
			}
		}
		mob->goal->bobstacle = 0;
		enemies_do_movement(mob);
	}
}
