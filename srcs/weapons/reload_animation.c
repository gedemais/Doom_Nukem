#include "main.h"

static void	up_n_down(t_weapon *w, float progress, bool reset)
{
	if (progress < 0.5f)
	{
		w->w_map->spawn.y -= RELOAD_SPEED;
		w->w_map->spawn.z -= RELOAD_SPEED;
	}
	else
	{
		w->w_map->spawn.y += RELOAD_SPEED;
		w->w_map->spawn.z += RELOAD_SPEED;
	}
	if (reset || w->w_map->spawn.y < w->start.y)
		w->w_map->spawn = w->start;
}

void	reload_animation(t_env *env, t_weapon *w)
{
	float	progress;

	w->reloading -= env->data.spent;
	if (!ft_inbounds(env->scene, W_FAMAS, W_MAX - 1)) // Protection
		return ;
	progress = w->reloading / RELOAD_TIME;
	up_n_down(w, progress, progress < 0.01f);
}
