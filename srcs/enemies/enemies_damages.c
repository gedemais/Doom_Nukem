#include "main.h"

static int	enemies_do_damages(t_env *env, t_enemy *mob)
{
	mob->hp -= env->player.current->damages;
	if (mob->hp < 1)
	{
		mob->dead = true;
		++env->custom_env.game.kill_count;
		sound_system(env, SA_DEATHMONSTER, sp_fork(env->volume));
		if (env->custom_env.game.kill_delay == 0)
			env->custom_env.game.kill_delay = KILL_DELAY;
	}
	env->custom_env.game.moula += mob->dead ? KILL_REWARD : HIT_REWARD;
	env->player.hitmarker = HITMARKER_T;
	return (0);
}

int			enemies_damages(t_env *env)
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
				return (enemies_do_damages(env, mob));
			return (0);
		}
	}
	return (0);
}
