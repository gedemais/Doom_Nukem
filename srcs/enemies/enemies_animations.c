#include "main.h"

bool			enemies_down(t_enemy *mob)
{
	if (mob->pos.y <= mob->down)
		return (true);
	mob->pos.y -= mob->speed / 2;
	return (false);
}

bool			enemies_up(t_enemy *mob)
{
	if (mob->pos.y >= mob->up)
		return (true);
	mob->pos.y += mob->speed / 2;
	return (false);
}

void			enemies_animations(t_env *env, t_enemy *mob)
{
	if (mob->end)
	{
		mob->down = 0;
		mob->up = 0;
		return ;
	}
	if (mob->noise++ == ENEMIES_NOISE_DELAY)
	{
		sound_system(env, SA_RING, sp_fork(0.005f, 0.2f, mob->pos));
		mob->noise = 0;
	}
	if(mob->down == 0)
		mob->down = mob->pos.y - MOB_ANIMATION_DOWN;
	if (mob->up == 0)
		mob->up = mob->pos.y + MOB_ANIMATION_UP;
	if (mob->up_token == false && enemies_up(mob))
		mob->up_token = true;
	if (mob->up_token == true && enemies_down(mob))
		mob->up_token = false;
}
