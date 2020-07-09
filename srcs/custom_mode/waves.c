#include "main.h"

static void	start_game(t_env *env)
{
	t_custom_game	*game;

	env->player.hp = START_HP;

	game = &env->custom_env.game;
	game->wave = 1;
	game->mobs_pv = MOB_START_HP;
	game->mobs_speed = MOB_START_SPEED;
	game->lmob = MOB_LSTART;
	game->current_lmob = MOB_LSTART;
	game->moula = START_MOULA;
	game->spawn_speed = RESPAWN_DELAY;
}

static bool	next_wave(t_env *env)
{
	static bool		first = true;

	if (first)
		env->custom_env.game.countdown = INTER_WAVE;
	first = false;
	env->custom_env.game.countdown -= env->data.spent;
	if (env->custom_env.game.countdown < 0)
	{
		env->custom_env.game.countdown = INTER_WAVE;
		// sound
		return (true);
	}
	return (false);
}

void		handle_waves(t_env *env)
{
	t_custom_game	*game;

	game = &env->custom_env.game;
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
			game->mobs_speed *= MOB_SPEED_COEFF;
			game->lmob += MOB_NB_ADD;
			game->current_lmob = game->lmob;
			game->spawn_speed -= SPAWN_SPEED_SUB;
		}
}
