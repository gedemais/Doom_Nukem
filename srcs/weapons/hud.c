#include "main.h"

int		weapons_hud(t_env *env)
{
	// hitmarker
	if (env->player.current)
		draw_reticule(env);
	if (print_ammos(env, env->player.current))
		return (-1);
	return (0);
}
