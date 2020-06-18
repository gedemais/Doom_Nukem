#include "main.h"
/*
static void	check_wounds(t_env *env)
{
	t_enemy	*mob;
	int		i;

	i = 0;
	while (i < env->custom_env.mobs.nb_cells)
	{
		mob = dyacc(&env->custom_env.mobs, i);
		if (vec3d_dist(env->cam->stats.pos, mob->pos) > EVENT_DIST)
		{
			mob->peace--;
			if (mob->peace <= 0)
			{
				mob->peace = MOB_PEACE_TIME;
			}
		}
		i++;
	}
}*/

void	handle_player(t_env *env)
{
	static int	heal = HEAL_SPEED;
	int			i;

	i = 0;
	heal--;
	if (heal <= 0)
	{
		if (env->player.hp < START_HP)
			env->player.hp++;
		heal = HEAL_SPEED;
	}
//	check_wounds(env);
}

