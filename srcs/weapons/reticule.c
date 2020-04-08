#include "main.h"

static void	draw_vertical(t_data *data, t_mlx *mlx, int size)
{
	int		x;
	int		y;
	float	pre_bound;
	int		bound;

	pre_bound = (size * ACC_SPREAD);
	bound = data->half_hgt + size;
	x = data->half_wdt;
	y = data->half_hgt - size - 1;
	while (++y < bound)
		if (fabsf(y - data->half_hgt) >= pre_bound)
		{
			draw_pixel(mlx->img_data, x, y, 0x00ff00);
			draw_pixel(mlx->img_data, x - 1, y, 0x00ff00);
		}
}

static void	draw_horizontal(t_data *data, t_mlx *mlx, int size)
{
	int		x;
	int		y;
	float	pre_bound;
	int		bound;

	pre_bound = (size * ACC_SPREAD);
	bound = data->half_wdt + size;
	x = data->half_wdt - size - 1;
	y = data->half_hgt;
	while (++x < bound)
		if (fabsf(x - data->half_wdt) >= pre_bound)
		{
			draw_pixel(mlx->img_data, x, y, 0x00ff00);
			draw_pixel(mlx->img_data, x, y - 1, 0x00ff00);
		}
}

void	draw_reticule(t_env *env)
{
	static float	size = 1.0f;
	t_data			*data;
	t_mlx			*mlx;
	int				lines_size;

	data = &env->data;
	mlx = &env->mlx;
	lines_size = size * ACC_START;
	draw_pixel(mlx->img_data, data->half_wdt, data->half_hgt, 0x00ff00);
	draw_pixel(mlx->img_data, data->half_wdt - 1, data->half_hgt, 0x00ff00);
	draw_pixel(mlx->img_data, data->half_wdt, data->half_hgt - 1, 0x00ff00);
	draw_pixel(mlx->img_data, data->half_wdt - 1, data->half_hgt - 1, 0x00ff00);

	draw_vertical(data, mlx, lines_size);
	draw_horizontal(data, mlx, lines_size);
}
