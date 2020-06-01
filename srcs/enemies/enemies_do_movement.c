#include "main.h"

static void		enemies_get_pas(t_enemy *mob)
{
	float	speed = 0.1f;
	t_vec3d	goal;

	goal = vec_add(mob->goal->pos, mob->goal->pos);
	mob->pas.x = (goal.x - mob->pos.x) * speed;
	mob->pas.y = (goal.y - mob->pos.y) * speed;
	mob->pas.z = (goal.z - mob->pos.z) * speed;	
}

static void		enemies_get_goal(t_pf *a, t_enemy *mob)
{
	t_node	*current;

	current = a->end;
	while (current && current != a->start)
	{
		if (current->parent == a->start)
		{
			mob->goal = current;
			enemies_get_pas(mob);
			return ;
		}
		current = current->parent;
	}
}

static void		enemies_smooth_movement(t_enemy *mob)
{
	t_vec3d	goal;

	goal = vec_add(mob->goal->pos, mob->goal->pos);
	if (mob->pos.x == goal.x
		&& mob->pos.y == goal.y
		&& mob->pos.z == goal.z)
		return ;
	mob->pos.x += mob->pas.x;
	mob->pos.y += mob->pas.y;
	mob->pos.z += mob->pas.z;
}

void			enemies_do_movement(t_pf *a, t_enemy *mob)
{
	t_vec3d	start;

	start = vec_add(a->start->pos, a->start->pos);
	if (mob->pos.x == start.x
		&& mob->pos.y == start.y
		&& mob->pos.z == start.z)
		enemies_get_goal(a, mob);
	enemies_smooth_movement(mob);
	start = vec_add(mob->goal->pos, mob->goal->pos);
	if (astar_distance(start, mob->pos) < 0.1f)
		mob->pos = start;
}
