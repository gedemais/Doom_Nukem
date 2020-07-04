#include "main.h"

static void	start_game(t_env *env)
{
	t_custom_game	*game;

	env->player.hp = START_HP;

	game = &env->custom_env.game;
	game->wave++;
	game->mobs_pv = MOB_START_HP;
	game->lmob = MOB_LSTART;
	game->current_lmob = MOB_LSTART;
	game->moula = START_MOULA;

	env->weapons[W_GLOCK_18].ammos = 80;
	push_dynarray(&env->player.weapons, &env->weapons[W_GLOCK_18], false);

	env->player.current_w = 0;
	env->player.current = dyacc(&env->player.weapons, 0);
	env->player.current->ammos = env->player.current->max_ammos;

}

void		handle_waves(t_env *env)
{
	t_custom_game	*game;

	game = &env->custom_env.game;
	if (wave == 0)
	{
		start_game(env);
		return ;
	}
	if (env->custom_env.game.current_lmob == 0)
		next_wave(env, game);
}
