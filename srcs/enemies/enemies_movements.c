#include "main.h"

static void		enemies_get_end(t_pf *a)
{
	int		i;
	t_vec3d	end;

	end.x = a->width - 1;
	end.y = a->height - 1;
	end.z = a->depth - 1;
	a->end = nodes_get_closest(a, end);
	while (astar_distance(a->start->pos, a->end->pos) > 5)
	{
		end.x = a->end->pos.x / 2 + a->start->pos.x / 2;
		end.y = a->end->pos.y / 2 + a->start->pos.y / 2;
		end.z = a->end->pos.z / 2 + a->start->pos.z / 2;
		a->end = nodes_get_closest(a, end);
		if (a->end->bobstacle == 1)
		{
			i = -1;
			while (++i < NEIGHBOURG)
				if (a->end->nghbr[i]->bobstacle == 0)
					a->end = a->end->nghbr[i];
		}
	}
}

static int		enemies_astar_detection(t_pf *a, t_enemy *mob)
{
	t_vec3d	v;

	if (a->end == NULL)
		return (-1);
	v = vec_add(a->end->pos, a->end->pos);
	return (mob->pos.x == v.x
		&& mob->pos.y == v.y
		&& mob->pos.z == v.z);
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
		a->start = nodes_get_closest(a, vec_fdiv(mob->pos, 2));
		if (enemies_astar_detection(a, mob))
		{
			enemies_get_end(a);
			astar(a);
		}
		enemies_do_movement(a, mob);
	}
}
