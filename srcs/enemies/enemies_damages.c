#include "main.h"

static void		enemies_sound_damages(t_env *env)
{
	(void)env;
}

static void		enemies_sound_death(t_env *env)
{
	(void)env;
}

static void		enemies_do_damages(t_env *env, t_enemy *mob)
{
	mob->hp -= env->player.current->damages;
	if (mob->hp < 1)
	{
		mob->dead = 1;
		++env->custom_env.game.kill_count;
		enemies_sound_death(env);
		if (env->custom_env.game.kill_delay == 0)
			env->custom_env.game.kill_delay = 120;
	}
	else
		enemies_sound_damages(env);
	env->custom_env.game.moula += mob->dead ? KILL_REWARD : HIT_REWARD;
	env->player.hitmarker = HITMARKER_T;
}

void			enemies_damages(t_env *env)
{
	int			i;
	int			index;
	t_enemy		*mob;

	index = env->mid.mesh->index;
	i = -1;
	while (++i < env->custom_env.mobs.nb_cells)
	{
		mob = dyacc(&env->custom_env.mobs, i);
		if (index >= mob->map_start && index < mob->map_end)
		{
			env->player.hover = true;
			if (env->player.current->shot && !mob->dead)
				enemies_do_damages(env, mob);
			return ;
		}
	}
}
