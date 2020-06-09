#include "main.h"

static void	stop_n_play(t_sample *s)
{
	play_ambience(s, false, true, false);
	play_ambience(s, true, false, false);
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
		if (w->shoot)
			stop_n_play(w->shoot);
	}
	w->shooting = 60.0f / w->cadency;
	return (0);
}

int			reload_current_weapon(t_env *env)
{
	t_weapon	*w;
	int			need;

	w = env->player.current;
	if (w->loaded == 0 && w->ammos >= w->magazine) // Chargeur vide
	{
		w->loaded += w->magazine;
		w->ammos -= w->magazine;
	}
	else if ((need = w->magazine - w->loaded) <= w->ammos) // R
	{
		w->loaded += need;
		w->ammos -= need;
	}
	else // Last
	{
		w->loaded += w->ammos;
		w->ammos = 0;
	}
	if (w->reload)
		stop_n_play(w->reload);
	w->reloading = RELOAD_TIME;
	w->start = w->w_map->spawn;
	return (0);
}
