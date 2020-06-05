#include "main.h"

static void		enemies_get_pas(t_enemy *mob)
{
	t_vec3d	goal;

	goal = vec_add(mob->goal->pos, mob->goal->pos);
	mob->pas.x = (goal.x - mob->pos.x) * mob->speed;
	mob->pas.y = (goal.y - mob->pos.y) * mob->speed;
	mob->pas.z = (goal.z - mob->pos.z) * mob->speed;	
}

static void		enemies_get_goal(t_enemy *mob)
{
	while (mob->end && mob->end != mob->goal)
	{
		if (mob->end->parent == NULL)
			return ;
		if (mob->end->parent == mob->goal)
		{
			mob->goal = mob->end;
			enemies_get_pas(mob);
			return ;
		}
		mob->end = mob->end->parent;
	}
}

static void		enemies_smooth_movement(t_enemy *mob)
{
	if (mob->i == mob->goal->i)
		return ;
	mob->pos = vec_add(mob->pos, mob->pas);
}

void			enemies_do_movement(t_enemy *mob)
{
	t_vec3d	goal;

	if (mob->i == mob->goal->i)
		enemies_get_goal(mob);
	enemies_smooth_movement(mob);
	goal = vec_add(mob->goal->pos, mob->goal->pos);
	if (astar_distance(goal, mob->pos) < 0.1f)
		mob->i = mob->goal->i;
}
