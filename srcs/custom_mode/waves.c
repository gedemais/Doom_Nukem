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
	game->spawn_speed = RESPAWN_DELAY;

	env->weapons[W_GLOCK_18].ammos = 80;
	push_dynarray(&env->player.weapons, &env->weapons[W_GLOCK_18], false);

	env->player.current_w = 0;
	env->player.current = dyacc(&env->player.weapons, 0);
	env->player.current->ammos = env->player.current->max_ammos;

}

static bool	next_wave(t_env *env)
{
	static float	time = INTER_WAVE;

	time -= env->data.spent;
	if (time < 0)
	{
		time = INTER_WAVE;
		// sound
		return (true);
	}
	return (false);
}

void		handle_waves(t_env *env)
{
	t_custom_game	*game;

	game = &env->custom_env.game;
	printf("lmob : %d | amob : %d\n", game->current_lmob, game->amob);
	if (game->wave == 0)
	{
		start_game(env);
		return ;
	}
	if (game->current_lmob == 0 && game->amob == 0)
		if (next_wave(env))
		{
			game->wave++;
			game->mobs_pv *= MOB_PV_COEFF;
			game->lmob += MOB_NB_ADD;
			game->current_lmob = game->lmob;
			game->spawn_speed -= SPAWN_SPEED_SUB;
		}
}
