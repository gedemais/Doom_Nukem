#include "main.h"

static void	draw_vertical(t_data *data, t_mlx *mlx, int size, float spread, bool hover)
{
	int		x;
	int		y;
	float	pre_bound;
	int		bound;

	pre_bound = (size * (1.2f - spread));
	bound = data->half_hgt + size;
	x = data->half_wdt;
	y = data->half_hgt - size - 1;
	while (++y < bound)
		if (fabsf(y - data->half_hgt) >= pre_bound)
		{
			draw_pixel(mlx->img_data, x, y, hover ? 0xff0000 : 0x00ff00);
			draw_pixel(mlx->img_data, x - 1, y, hover ? 0xff0000 : 0x00ff00);
		}
}

static void	draw_horizontal(t_data *data, t_mlx *mlx, int size, float spread, bool hover)
{
	int		x;
	int		y;
	float	pre_bound;
	int		bound;

	pre_bound = (size * (1.2f - spread));
	bound = data->half_wdt + size;
	x = data->half_wdt - size - 1;
	y = data->half_hgt;
	while (++x < bound)
		if (fabsf(x - data->half_wdt) >= pre_bound)
		{
			draw_pixel(mlx->img_data, x, y, hover ? 0xff0000 : 0x00ff00);
			draw_pixel(mlx->img_data, x, y - 1, hover ? 0xff0000 : 0x00ff00);
		}
}

void	draw_reticule(t_env *env)
{
	t_data			*data;
	t_mlx			*mlx;
	t_player		*pl;
	int				line_size;

	data = &env->data;
	mlx = &env->mlx;
	pl = &env->player;
	line_size = env->player.current->reticle;
	// Askip c'est moche
//	draw_pixel(mlx->img_data, data->half_wdt, data->half_hgt, 0x00ff00);
//	draw_pixel(mlx->img_data, data->half_wdt - 1, data->half_hgt, 0x00ff00);
//	draw_pixel(mlx->img_data, data->half_wdt, data->half_hgt - 1, 0x00ff00);
//	draw_pixel(mlx->img_data, data->half_wdt - 1, data->half_hgt - 1, 0x00ff00);

	draw_vertical(data, mlx, line_size, pl->current->accuracy, pl->hover);
	draw_horizontal(data, mlx, line_size, pl->current->accuracy, pl->hover);
}
