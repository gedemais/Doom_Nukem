#include "main.h"

static int		print_moulaga(t_env *env)
{
	t_ttf_config	*conf;
	char			*moulaga;

	conf = ttf_config();
	if (!(moulaga = ft_itoa(env->custom_env.game.moula)))
		return (-1);
	ft_strcpy((char*)conf->s, moulaga);
	conf->size = 18;
	my_string_put(env, env->mlx.img_data, (t_point){930, 60}, FONT_COOLVETICA);
	return (0);
}

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
	if (print_ammos(env, env->player.current)
		|| print_moulaga(env))
		return (-1);
	if (env->player.hitmarker > 0)
		hitmarker(env);
	return (0);
}
