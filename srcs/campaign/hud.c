#include "main.h"

int		cmp_hud(t_env *env, t_camp_env *cmp_env)
{
	if (cmp_env->player.current)
		draw_reticule(env);
	if (print_ammos(env, env->cmp_env.player.current))
		return (-1);
	check_doors(env, cmp_env);
	return (0);
}
