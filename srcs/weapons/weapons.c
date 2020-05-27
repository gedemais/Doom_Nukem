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
	bool	exp;

	exp = (e->buttons[BUTTON_SCROLL_UP] || e->buttons[BUTTON_SCROLL_DOWN]);
	if (exp && env->player.current)
		switch_current_weapon(env, &env->events);
}

int			handle_weapons(t_env *env)
{
	raster_weapon(env, env->player.current->w_map);
	weapons_events(env, &env->events);
	weapons_hud(env);
	return (0);
}
