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
		unlink_weapon(map, env->player.current);
		env->player.current = dyacc(&env->player.weapons, index);
		link_weapon_to_cam(map, env->player.current);
	}
	else if (e->buttons[BUTTON_SCROLL_DOWN])
	{
		index = (index == 0) ? W_MAX - 1 : index - 1;
		unlink_weapon(map, env->player.current);
		env->player.current = dyacc(&env->player.weapons, index);
		link_weapon_to_cam(map, env->player.current);
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
	// Deplacer l'arme avec le joueur

	// Dessiner le reticule

	weapons_events(env, &env->events);
	// Si nb_bullets_loaded == 0 && nb_bullets_tot > 0
	// Recharger
	// Si le clic gauche est appuye, tirer
	weapons_hud(env);
	return (0);
}
