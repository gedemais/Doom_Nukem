#include "main.h"

static float	enemies_xz_angle(t_vec3d a, t_vec3d b)
{
	float	cross;
	float	dot;

	cross = a.x * b.z - a.z * b.x;
	dot = a.x * b.x + a.z * b.z;
	return (atan2(cross, dot));
}

static void		enemies_moves_yaw(t_enemy *mob)
{
	float	angle;
	t_vec3d	goal;

	goal = vec_add(mob->goal->pos, mob->goal->pos);
	goal = vec_sub(goal, mob->pos);
	angle = enemies_xz_angle(mob->head, goal);
	if (angle)
	{
		mob->yaw = angle * mob->speed;
	}
}

static void		enemies_moves_pitch(t_enemy *mob)
{
	t_vec3d	goal;

	goal = vec_add(mob->goal->pos, mob->goal->pos);
	mob->pitch.x = (goal.x - mob->pos.x) * mob->speed;
	mob->pitch.y = (goal.y - mob->pos.y) * mob->speed;
	mob->pitch.z = (goal.z - mob->pos.z) * mob->speed;	
}

void			enemies_goals(t_enemy *mob)
{
	enemies_moves_pitch(mob);
	enemies_moves_yaw(mob);
}
