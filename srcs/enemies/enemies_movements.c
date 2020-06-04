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
	int 	pos;
	t_vec3d	end;


	end.x = a->width - 1;
	end.y = a->height - 1;
	end.z = a->depth - 1;
	pos = nodes_3d_1d((t_vec3d){a->width, a->height, a->depth, 0}, end);
	mob->end = dyacc(&a->d_nodes, pos);
	while (astar_distance(a->start->pos, mob->end->pos) > 5)
	{
		end.x = mob->end->pos.x / 2 + a->start->pos.x / 2;
		end.y = mob->end->pos.y / 2 + a->start->pos.y / 2;
		end.z = mob->end->pos.z / 2 + a->start->pos.z / 2;
		pos = nodes_3d_1d((t_vec3d){a->width, a->height, a->depth, 0}, end);
		mob->end = dyacc(&a->d_nodes, pos);
		if (mob->end->bobstacle == 1)
			enemies_check_neighbourgs(a, mob);
	}
	a->end = mob->end;
}

static int		enemies_astar_detection(t_enemy *mob)
{
	t_vec3d	end;

	if (mob->end == NULL)
		return (-1);
	end = vec_add(mob->end->pos, mob->end->pos);
	return (mob->pos.x == end.x
		&& mob->pos.y == end.y
		&& mob->pos.z == end.z);
}

void			enemies_movements(t_env *env)
{
	int		i;
	int 	pos;
	t_enemy	*mob;
	t_pf	*a;

	a = &env->astar;
	i = -1;
	while (++i < env->mobs.nb_cells)
	{
		mob = dyacc(&env->mobs, i);
		pos = nodes_3d_1d((t_vec3d){ a->width,
			a->height, a->depth, 0 }, vec_fdiv(mob->pos, 2));
		a->start = dyacc(&a->d_nodes, pos);
		if (enemies_astar_detection(mob))
		{
			enemies_get_end(a, mob);
			astar(a);
		}
		enemies_do_movement(a, mob);
	}
}
