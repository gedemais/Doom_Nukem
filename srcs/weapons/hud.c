#include "main.h"

static void	hitmarker(t_env *env)
{
	t_sprite	hm;
	t_point		o;

	hm = env->sprites[SP_HITMARKER];
	o.x = env->data.half_wdt - (hm.wdt / 2);
	o.y = env->data.half_hgt - (hm.hgt / 2);
	map_sprite(env->mlx.img_data, hm, o);
}

int			weapons_hud(t_env *env)
{
	// hitmarker
	if (env->player.current)
		draw_reticule(env);
	if (print_ammos(env, env->player.current))
		return (-1);
	if (env->player.hitmarker > 0)
		hitmarker(env);
	return (0);
}
