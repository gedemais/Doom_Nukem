#include "main.h"

int		loot_nuke(t_env *env)
{
	t_enemy	*mob;
	int		i;

	i = 0;
	while (i < env->custom_env.mobs.nb_cells)
	{
		mob = dyacc(&env->custom_env.mobs, i);
		mob->hp = 0;
		i++;
	}
	sound_system(env, SA_LNUKE, (t_sparam){ 0, 0, 1, 0 });
	return (0);
}

int		loot_money(t_env *env)
{
	int		bonus;
	int		cumul;

	cumul = env->custom_env.game.wave * 42;
	bonus = (rand() % (MAX_CASH + cumul)) + MIN_CASH;
	env->custom_env.game.moula += bonus;
	while (env->custom_env.game.moula % 10)
		env->custom_env.game.moula++;
	sound_system(env, SA_LCASH, (t_sparam){ 0, 0, 1, 0 });
	return (0);
}

int		loot_shield(t_env *env)
{
	env->player.god = GOD_TIME;
	sound_system(env, SA_LGODSTART, (t_sparam){ 0, 0, 1, 0 });
	return (0);
}

int		loot_ammos(t_env *env)
{
	t_weapon	*w;
	int			i;

	i = 0;
	while (i < env->player.weapons.nb_cells)
	{
		w = dyacc(&env->player.weapons, i);
		w->ammos = w->max_ammos;
		i++;
	}
	sound_system(env, SA_LAMMOS, (t_sparam){ 0, 0, 1, 0 });
	return (0);
}
