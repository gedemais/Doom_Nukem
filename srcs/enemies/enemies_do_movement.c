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
	mob->yaw = xz_angle(mob->head, goal) * mob->speed;
	mob->yaw = mob->yaw < -0.1f ? -0.1f : mob->yaw;
	mob->yaw = mob->yaw > 0.1f ? 0.1f : mob->yaw;
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

static int		enemies_actions(t_env *env, t_enemy *mob)
{
	float	fcos;
	float	fsin;

	if (mob->i == mob->goal->i)
		return (0);
	mob->pos = vec_add(mob->pos, mob->pitch);
	fcos = cos(mob->yaw);
	fsin = sin(mob->yaw);
	enemies_rotate_mob(mob, fcos, fsin, rotate_y);
	if (mob->noise++ == ENEMIES_NOISE_DELAY)
	{
		if (sound_system(env, SA_LEVITATION, sp_fork(0.1f, 1, mob->pos)))
			return (-1);
		mob->noise = 0;
	}
	return (0);
}

int			enemies_do_movement(t_env *env, t_enemy *mob)
{
	t_vec3d	goal;

	mob->goal->bobstacle = 0;
	if (mob->i == mob->goal->i)
		enemies_get_goal(mob);
	if (mob->end == NULL)
		return (0);
	if (enemies_actions(env, mob))
		return (-1);
	goal = vec_add(mob->goal->pos, mob->goal->pos);
	if (vec3d_dist(goal, mob->pos) < 0.1f)
		mob->i = mob->goal->i;
	mob->goal->bobstacle = 1;
	return (0);
}
