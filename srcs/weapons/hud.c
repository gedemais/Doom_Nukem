#include "main.h"

static void	print_moulaga(t_env *env)
{
	t_ttf_config	*conf;
	char			*moulaga;
	t_point			o;

	conf = ttf_config();
	if (!(moulaga = ft_itoa(env->custom_env.game.moula)))
		return ;
	ft_strcpy((char*)conf->s, moulaga);
	free(moulaga);
	conf->size = 16;
	o = (t_point){1000 - conf->size / 2, 200};
	draw_rectangle(env->mlx.img_data, o,
		(t_point){conf->size * ft_strlen(moulaga), conf->size}, 0x770000);
	o.x += conf->size / 2;
	o.y += conf->size;
	my_string_put(env, env->mlx.img_data, o, FONT_COOLVETICA);
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
	if (print_ammos(env, env->player.current))
		return (-1);
	if (env->player.hitmarker > 0)
		hitmarker(env);
	print_moulaga(env);
	return (0);
}
