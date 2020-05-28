#include "main.h"

int		shoot_current_weapon(t_env *env)
{
	t_weapon	*w;
	bool		sbs;
	bool		single;
	bool		full_auto;

	w = env->player.current;
	sbs = (w->ready && w->shoot_mode == SMODE_SBS);
	single = (w->ready && w->shoot_mode == SMODE_SINGLE);
	full_auto = (w->ready && w->shoot_mode == SMODE_FULL_AUTO);
	if (sbs || single || full_auto)
	{
		w->ready = false;
		w->loaded--;
		if (w->shoot)
			play_ambience(w->shoot, true, false, false);
	}
	// Animation
	return (0);
}

int		reload_current_weapon(t_env *env)
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
	{
		play_ambience(w->reload, false, true, false);
		play_ambience(w->reload, true, false, false);
	}
	return (0);
}
