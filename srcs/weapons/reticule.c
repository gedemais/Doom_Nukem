#include "main.h"

static void	draw_vertical(t_data *data, t_mlx *mlx, float size, float spread)
{
	int		x;
	int		y;
	int		bound;

	bound = size * ACC_START;
	x = data->half_wdt;
	y = data->half_hgt - bound - 1;
	bound *= spread;
	while (y < data->half_hgt - bound)
	{
		draw_pixel(mlx->img_data, x, y, 0x00ff00);
		draw_pixel(mlx->img_data, x - 1, y, 0x00ff00);
		y++;
	}
	y = data->half_hgt + bound - 1;
	bound /= spread;
	while (y < data->half_hgt + bound)
	{
		draw_pixel(mlx->img_data, x, y, 0x00ff00);
		draw_pixel(mlx->img_data, x - 1, y, 0x00ff00);
		y++;
	}
}

static void	draw_horizontal(t_data *data, t_mlx *mlx, float size, float spread)
{
	int		x;
	int		y;
	int		bound;

	bound = size * ACC_START;
	x = data->half_wdt - bound;
	y = data->half_hgt - 1;
	bound *= spread;
	while (x < data->half_wdt - bound)
	{
		draw_pixel(mlx->img_data, x, y, 0x00ff00);
		draw_pixel(mlx->img_data, x, y - 1, 0x00ff00);
		x++;
	}
	x = data->half_wdt + bound - 1;
	bound /= spread;
	while (x < data->half_wdt + bound + 1)
	{
		draw_pixel(mlx->img_data, x, y, 0x00ff00);
		draw_pixel(mlx->img_data, x, y - 1, 0x00ff00);
		x++;
	}
}

static void	draw(t_data *data, t_mlx *mlx, float size, float spread)
{
	draw_pixel(mlx->img_data, data->half_wdt, data->half_hgt - 1, 0x00ff00);
	draw_pixel(mlx->img_data, data->half_wdt - 1, data->half_hgt - 1, 0x00ff00);
	draw_pixel(mlx->img_data, data->half_wdt, data->half_hgt - 2, 0x00ff00);
	draw_pixel(mlx->img_data, data->half_wdt - 1, data->half_hgt - 2, 0x00ff00);

	draw_vertical(data, mlx, size, spread);
	draw_horizontal(data, mlx, size, spread);
}

void	draw_reticule(t_env *env)
{
	float	size;

	size = 1.0f;
	draw(&env->data, &env->mlx, size, 0.5f);
}
