#include "main.h"

static void	draw_vertical(t_data *data, t_mlx *mlx, float size)
{
	int		x;
	int		y;
	int		ybound;
	int		ratio;

	ratio = (size * ACC_START);
	ybound = data->half_hgt - ratio / 3.0f;
	x = data->half_wdt;
	y = data->half_hgt - ratio - 1;
	while (++y < ybound)
	{
		draw_pixel(mlx->img_data, x, y, 0x0ff00);
		draw_pixel(mlx->img_data, x - 1, y, 0x0ff00);
	}
	y = data->half_hgt + ratio / 3.0f;
	ybound = data->half_hgt + ratio - 1;
	while (++y < ybound)
	{
		draw_pixel(mlx->img_data, x, y, 0x0ff00);
		draw_pixel(mlx->img_data, x - 1, y, 0x0ff00);
	}
}

static void	draw_horizontal(t_data *data, t_mlx *mlx, float size)
{
	int		x;
	int		y;
	int		xbound;
	int		ratio;

	ratio = (size * ACC_START);
	xbound = data->half_wdt - ratio / 3.0f;
	x = data->half_wdt - ratio - 1;
	y = data->half_hgt;
	while (++x < xbound)
	{
		draw_pixel(mlx->img_data, x, y, 0x0ff00);
		draw_pixel(mlx->img_data, x, y - 1, 0x0ff00);
	}
	x = data->half_wdt + ratio / 3.0f;
	xbound = data->half_wdt + ratio - 1;
	while (++x < xbound)
	{
		draw_pixel(mlx->img_data, x, y, 0x0ff00);
		draw_pixel(mlx->img_data, x, y - 1, 0x0ff00);
	}
}

void	draw_reticule(t_env *env)
{
	static float	size = 1.0f;
	t_data			*data;
	t_mlx			*mlx;

	data = &env->data;
	mlx = &env->mlx;
	draw_pixel(mlx->img_data, data->half_wdt, data->half_hgt, 0x00ff00);
	draw_pixel(mlx->img_data, data->half_wdt - 1, data->half_hgt, 0x00ff00);
	draw_pixel(mlx->img_data, data->half_wdt, data->half_hgt - 1, 0x00ff00);
	draw_pixel(mlx->img_data, data->half_wdt - 1, data->half_hgt - 1, 0x00ff00);

	draw_vertical(data, mlx, size);
	draw_horizontal(data, mlx, size);
}
