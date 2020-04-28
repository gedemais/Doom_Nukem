#include "main.h"

static void	background(t_env *env)
{
	char		*img;
	char		*b;
	int			color;
	int			x;
	int			y;

	y = 0;
	color = 0x444444;
	b = (char*)&color;
	img = env->mlx.img_data;
	while (y < HGT)
	{
		if (y % 4 == 0)
			b[0]++;
		x = 0;
		while (x < WDT)
		{
			draw_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

int			maped_new_map(t_env *env)
{
	background(env);
	map_sprite(env->mlx.img_data, env->sprites[SP_ME_NM_TITLE], (t_point){420, 60});
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
