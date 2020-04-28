#include "main.h"

static void	background(t_env *env)
{
	char	*img;
	int		x;
	int		y;

	y = 0;
	img = env->mlx.img_data;
	while (y < HGT)
	{
		x = 0;
		while (x < WDT)
		{
			draw_pixel(img, x, y, 0x444466);
			x++;
		}
		y++;
	}
}
/*
static void	render_champ(t_env *env, t_point h, t_point o, char s[MAX_STR_CHARS])
{
	
}*/

static void	render_fields(t_env *env)
{
	t_ttf_config	*conf;

	conf = ttf_config();
	conf->size = 20;
	ft_strcpy((char*)conf->s, "Width");
	my_string_put(env, env->mlx.img_data, (t_point){100, 80}, FONT_ARIAL);
	input_field(env, (t_point){100, 100}, FIELD_MAP_WIDTH, NULL);
	ft_memset((char*)conf->s, 0, MAX_STR_CHARS);
}

int			maped_new_map(t_env *env)
{
	background(env);
	render_fields(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
