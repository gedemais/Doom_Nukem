#include "main.h"

static void	switch_current_weapon(t_env *env, t_events *e)
{
	t_map	*map;
	int		index;

	map = &env->edit_env.map;
	index = env->player.current->index;
	if (e->buttons[BUTTON_SCROLL_UP])
	{
		index = (index == W_MAX - 1) ? 0 : index + 1;
		env->player.current = dyacc(&env->player.weapons, index);
	}
	else if (e->buttons[BUTTON_SCROLL_DOWN])
	{
		index = (index == 0) ? W_MAX - 1 : index - 1;
		env->player.current = dyacc(&env->player.weapons, index);
	}
}

static void	handle_ready(t_env *env, t_weapon *w)
{
	static float	since = 0;

	if (w->reloading > 0)
	{
		reload_animation(env, w);
		w->ready = false;
		return ;
	}
	if (w->shoot_mode == SMODE_FULL_AUTO)
	{
		w->ready = (60 / since) < w->cadency; // Cap with time
		since = w->ready ? env->data.spent : since + env->data.spent;
	}
	else if (w->shoot_mode == SMODE_SINGLE)
		w->ready = !env->events.buttons[BUTTON_LCLIC];
	else if (w->shoot_mode == SMODE_SBS)
		w->ready = !env->events.buttons[BUTTON_LCLIC]; // Cap with animation time
}

static void	weapons_events(t_env *env, t_events *e)
{
	t_weapon	*w;
	bool		r;
	bool		scroll;

	w = env->player.current;
	scroll = (e->buttons[BUTTON_SCROLL_UP] || e->buttons[BUTTON_SCROLL_DOWN]);
	if (scroll && w)
	{
		switch_current_weapon(env, &env->events);
		return ;
	}
	r = e->keys[KEY_R];
	if (((r && w->loaded < w->magazine) || w->loaded == 0) && w->ammos > 0)
		reload_current_weapon(env);
	else if (e->buttons[BUTTON_LCLIC] && w->ready && w->loaded > 0)
		shoot_current_weapon(env);
	if (w->shooting > 0)
		shoot_animation(env, w);
	handle_ready(env, w);
}

int			handle_weapons(t_env *env)
{
	raster_weapon(env, env->player.current->w_map);
	weapons_events(env, &env->events);
	weapons_hud(env);
	return (0);
}
