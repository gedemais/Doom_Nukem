#include "main.h"

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
