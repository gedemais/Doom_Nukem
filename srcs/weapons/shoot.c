#include "main.h"

int		shoot_current_weapon(t_env *env)
{
	t_weapon	*w;
	bool		sbs;
	bool		single;
	bool		full_auto;

	w = env->player.current;
	sbs = (w->animated && w->shoot_mode == SMODE_SBS);
	single = (w->ready && w->shoot_mode == SMODE_SINGLE);
	full_auto = (w->shoot_mode == SMODE_FULL_AUTO);
	if (sbs || single || full_auto)
	{
		w->ready = false;
		w->animated = false;
		w->loaded--;
	}
	// Jouer le son
	// Animation
	return (0);
}

int		reload_current_weapon(t_env *env)
{
	t_weapon	*w;
	int		inmag;
	int		tmp;

	w = env->player.current;
	inmag = (w->ammos >= w->magazine) ? w->magazine : w->ammos;
	tmp = w->loaded;
	w->loaded = inmag;
	w->ammos -= inmag - tmp;
	return (0);
}
