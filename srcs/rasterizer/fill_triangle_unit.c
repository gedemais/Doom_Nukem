#include "main.h"

static void	flatbot(t_env *env, t_vec3d v[3], int color)
{
	t_filler	fill;
	int			x;
	int			y;

	fill.m0 = (v[1].x - v[0].x) / (v[1].y - v[0].y);
	fill.m1 = (v[2].x - v[0].x) / (v[2].y - v[0].y);
	fill.ystart = (int)ceil(v[0].y - 0.5f);
	fill.yend = (int)ceil(v[2].y - 0.5f);
	y = fill.ystart;
	while (y < fill.yend)
	{
		fill.x0 = fill.m0 * (y + 0.5f - v[0].y) + v[0].x;
		fill.x1 = fill.m1 * (y + 0.5f - v[0].y) + v[0].x;
		fill.xstart = (int)(fill.x0 - 0.5f);
		fill.xend = (int)(fill.x1 - 0.5f);
		x = fill.xstart;
		while (x < fill.xend)
		{
			draw_pixel(env->mlx.img_data, x, y, color);
			x++;
		}
		y++;
	}
}

static void		flattop(t_env *env, t_vec3d v[3], int color)
{
	t_filler	fill;
	int			x;
	int			y;

	fill.m0 = (v[2].x - v[0].x) / (v[2].y - v[0].y);
	fill.m1 = (v[2].x - v[1].x) / (v[2].y - v[1].y);
	fill.ystart = (int)ceil(v[0].y - 0.5f);
	fill.yend = (int)ceil(v[2].y - 0.5f);
	y = fill.ystart;
	while (y < fill.yend)
	{
		fill.x0 = fill.m0 * (y + 0.5f - v[0].y) + v[0].x;
		fill.x1 = fill.m1 * (y + 0.5f - v[1].y) + v[1].x;
		fill.xstart = (int)(fill.x0 - 0.5f);
		fill.xend = (int)(fill.x1 - 0.5f);
		x = fill.xstart;
		while (x < fill.xend)
		{
			draw_pixel(env->mlx.img_data, x, y, color);
			x++;
		}
		y++;
	}
}

static void	classic(t_env *env, t_vec3d v[3], int color)
{
	t_vec3d	vi;
	float	alpha;

	alpha = (v[1].y - v[0].y) / (v[2].y - v[0].y);
	vi.x = v[0].x + (v[2].x - v[0].x) * alpha;
    vi.y = v[0].y + (v[2].y - v[0].y) * alpha;
    vi.z = v[0].z + (v[2].z - v[0].z) * alpha;
	if (v[1].x < vi.x)
	{
		flatbot(env, (t_vec3d[3]){v[0], v[1], vi}, color);
		flattop(env, (t_vec3d[3]){v[1], vi, v[2]}, color);
	}
	else
	{
		flatbot(env, (t_vec3d[3]){v[0], vi, v[1]}, color);
		flattop(env, (t_vec3d[3]){vi, v[1], v[2]}, color);
	}
}

void	fill_triangle_unit(t_env *env, t_triangle t, int color)
{
	t_vec3d	v[3];

	ft_memcpy(&v[0], &t.points[0], sizeof(t_vec3d) * 3);
	v[1].y < v[0].y ? vec_swap(&v[0], &v[1]) : 0;
	v[2].y < v[1].y ? vec_swap(&v[1], &v[2]) : 0;
	v[1].y < v[0].y ? vec_swap(&v[0], &v[1]) : 0;
	if (v[0].y == v[1].y)
	{
		v[1].x < v[0].x ? vec_swap(&v[0], &v[1]) : 0;
		flattop(env, v, color);
	}
	else if (v[1].y == v[2].y)
	{
		v[2].x < v[1].x ? vec_swap(&v[1], &v[2]) : 0;
		flatbot(env, v, color);
	}
	else
	{
		classic(env, v, color);
	}
}
