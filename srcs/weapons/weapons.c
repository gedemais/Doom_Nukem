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
	else if (e->buttons[BUTTON_LCLIC] && w->loaded > 0)
		shoot_current_weapon(env);
	w->ready = !e->buttons[BUTTON_LCLIC];
}

int			handle_weapons(t_env *env)
{
	raster_weapon(env, env->player.current->w_map);
	weapons_events(env, &env->events);
	//animations();
	weapons_hud(env);
	return (0);
}
