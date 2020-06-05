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

static void		enemies_get_end(t_pf *a, t_enemy *mob)
{
	t_vec3d	end;

	mob->end = dyacc(&a->d_nodes, a->d_nodes.nb_cells - 1);
	while (astar_distance(a->start->pos, mob->end->pos) > 5)
	{
		end.x = mob->end->pos.x / 2 + a->start->pos.x / 2;
		end.y = mob->end->pos.y / 2 + a->start->pos.y / 2;
		end.z = mob->end->pos.z / 2 + a->start->pos.z / 2;
		mob->end = nodes_get_closest(&a->d_nodes, end);
		if (mob->end->bobstacle == 1)
			enemies_check_neighbourgs(a, mob);
	}
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
			enemies_get_end(a, mob);
			astar(a);
		}
		enemies_do_movement(a, mob);
	}
}
