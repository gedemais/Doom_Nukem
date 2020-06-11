#include "main.h"

static bool		enemies_infinite_loop(t_enemy *mob)
{
	return (mob->end->parent->parent
		&& mob->end->parent->parent->i == mob->end->i);
}

void			enemies_goals(t_enemy *mob)
{
	t_vec3d	goal;

	goal = vec_add(mob->goal->pos, mob->goal->pos);
	mob->pitch.x = (goal.x - mob->pos.x) * mob->speed;
	mob->pitch.y = (goal.y - mob->pos.y) * mob->speed;
	mob->pitch.z = (goal.z - mob->pos.z) * mob->speed;
	goal = vec_add(mob->end->pos, mob->end->pos);
	goal = vec_sub(goal, mob->pos);
	mob->yaw = enemies_xz_angle(mob->head, goal) * mob->speed;
}

static void		enemies_get_goal(t_enemy *mob)
{
	while (mob->end && mob->end->i != mob->goal->i)
	{
		if (mob->end->parent == NULL)
			return ;
		if (mob->end->parent->i == mob->goal->i)
		{
			mob->goal = mob->end;
			enemies_goals(mob);
			return ;
		}
		if (enemies_infinite_loop(mob))
		{
			mob->end = NULL;
			return ;
		}
		mob->end = mob->end->parent;
	}
}

static void		enemies_smooth_movement(t_enemy *mob)
{
	float	fcos;
	float	fsin;

	if (mob->i == mob->goal->i)
		return ;
	mob->pos = vec_add(mob->pos, mob->pitch);
	fcos = cos(mob->yaw);
	fsin = sin(mob->yaw);
	enemies_rotate_mob(mob, fcos, fsin, enemies_rotate_y);
}

void			enemies_do_movement(t_enemy *mob)
{
	t_vec3d	goal;

	mob->goal->bobstacle = 0;
	if (mob->i == mob->goal->i)
		enemies_get_goal(mob);
	if (mob->end == NULL)
		return ;
	enemies_smooth_movement(mob);
	goal = vec_add(mob->goal->pos, mob->goal->pos);
	if (astar_distance(goal, mob->pos) < 0.1f)
		mob->i = mob->goal->i;
	mob->goal->bobstacle = 1;
}
