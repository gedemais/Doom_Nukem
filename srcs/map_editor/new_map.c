#include "main.h"

static void	background(t_env *env, t_sprite sprite)
{
	int		x;
	int		y;
	int		xmax;
	int		ymax;

	y = 0;
	xmax = WDT / sprite.wdt + 1;
	ymax = HGT / sprite.hgt + 1;
	while (y < ymax)
	{
		x = 0;
		while (x < xmax)
		{
			map_sprite(env->mlx.img_data, sprite, (t_point){x * sprite.wdt, y * sprite.hgt});
			x++;
		}
		y++;
	}
}

static void	render_fields(t_env *env)
{
	t_ttf_config	*conf;

	conf = ttf_config();
	conf->size = 24;
	my_string_put(env, (t_point){100, 80}, FONT_ARIAL, (unsigned char*)"Width");
	input_field(env, (t_point){100, 100}, FIELD_MAP_WIDTH, NULL);

	my_string_put(env, (t_point){100, 180}, FONT_ARIAL, (unsigned char*)"Height");
	input_field(env, (t_point){100, 200}, FIELD_MAP_HEIGHT, NULL);
}

int			maped_new_map(t_env *env)
{
	background(env, env->sprites[SP_ME_NEW_MAP_BACKGROUND]);
	render_fields(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
