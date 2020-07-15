#include "main.h"

static void	stop_n_play(t_env *env, int source)
{
	sound_system(env, source, sp_stop());
	sound_system(env, source,
		sp_play(env->sound.volume, PITCH, env->cam.stats.pos));
}

int			shoot_current_weapon(t_env *env)
{
	t_weapon	*w;
	bool		sbs;
	bool		single;
	bool		full_auto;

	w = env->player.current;
	sbs = w->shoot_mode == SMODE_SBS;
	single = w->shoot_mode == SMODE_SINGLE;
	full_auto = w->shoot_mode == SMODE_FULL_AUTO;
	if (sbs || single || full_auto)
	{
		w->ready = false;
		w->loaded--;
		stop_n_play(env, w->shoot);
	}
	w->shooting = 60.0f / w->cadency;
	w->shot = true;
	return (0);
}

int			reload_current_weapon(t_env *env)
{
	t_weapon	*w;
	int			need;

	w = env->player.current;
	if (w->loaded == 0 && w->ammos >= w->magazine)
	{
		w->loaded += w->magazine;
		w->ammos -= w->magazine;
	}
	else if ((need = w->magazine - w->loaded) <= w->ammos)
	{
		w->loaded += need;
		w->ammos -= need;
	}
	else
	{
		w->loaded += w->ammos;
		w->ammos = 0;
	}
	stop_n_play(env, w->reload);
	w->reloading = RELOAD_TIME;
	w->start = w->w_map->spawn;
	return (0);
}
