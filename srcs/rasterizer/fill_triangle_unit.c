#include "main.h"

static void	write_pixel(t_env *env, t_triangle t, t_point px, t_filler fill)
{
	float	w;

	
}

static void	flatbot(t_env *env, t_vec3d v[3], t_triangle t)
{
	t_filler	fill;
	int			x;
	int			y;

	fill.m0 = (v[1].x - v[0].x) / (v[1].y - v[0].y);
	fill.m1 = (v[2].x - v[0].x) / (v[2].y - v[0].y);
	fill.ystart = (int)ceil(v[0].y - 0.5f);
	fill.yend = (int)ceil(v[2].y - 0.5f);
	y = fill.ystart > 0 ? fill.ystart : 1;
	while (y < fill.yend)
	{
		fill.x0 = fill.m0 * (y + 0.5f - v[0].y) + v[0].x;
		fill.x1 = fill.m1 * (y + 0.5f - v[0].y) + v[0].x;
		fill.xstart = (int)(fill.x0 - 0.5f);
		fill.xend = (int)(fill.x1 - 0.5f);
		x = fill.xstart > 0 ? fill.xstart : 1 ;
		while (x < fill.xend)
		{
			draw_pixel(env->mlx.img_data, x, y, shade_color(t.color, t.illum));
			x++;
		}
		y++;
	}
}

static void		flattop(t_env *env, t_vec3d v[3], t_triangle t)
{
	t_filler	fill;
	int			x;
	int			y;

	fill.m0 = (v[2].x - v[0].x) / (v[2].y - v[0].y);
	fill.m1 = (v[2].x - v[1].x) / (v[2].y - v[1].y);
	fill.ystart = (int)ceil(v[0].y - 0.5f);
	fill.yend = (int)ceil(v[2].y - 0.5f);
	y = fill.ystart > 0 ? fill.ystart : 1;
	while (y < fill.yend)
	{
		fill.x0 = fill.m0 * (y + 0.5f - v[0].y) + v[0].x;
		fill.x1 = fill.m1 * (y + 0.5f - v[1].y) + v[1].x;
		fill.xstart = (int)(fill.x0 - 0.5f);
		fill.xend = (int)(fill.x1 - 0.5f);
		x = fill.xstart > 0 ? fill.xstart : 1;

		fill.tx = 0.0f;
		step = 1.0f / (fill.xend - fill.xstart);
		while (x < fill.xend)
		{
			w = (1.0f - fill.tx) * fill.xstart + fill.tx * fill.xend;
			if (w > env->cam.z_buffer[(y - 1) * WDT + x])
			{
				env->cam.z_buffer[(y - 1) * WDT + x] = w;
				draw_pixel(env->mlx.img_data, x, y, shade_color(t.color, t.illum));
			}
			fill.tx += step;
			x++;
		}
		y++;
	}
}

static void	classic(t_env *env, t_vec3d v[3], t_triangle t)
{
	t_vec3d	vi;
	float	alpha;

	alpha = (v[1].y - v[0].y) / (v[2].y - v[0].y);
	vi.x = v[0].x + (v[2].x - v[0].x) * alpha;
    vi.y = v[0].y + (v[2].y - v[0].y) * alpha;
    vi.z = v[0].z + (v[2].z - v[0].z) * alpha;
	if (v[1].x < vi.x)
	{
		flatbot(env, (t_vec3d[3]){v[0], v[1], vi}, t);
		flattop(env, (t_vec3d[3]){v[1], vi, v[2]}, t);
	}
	else
	{
		flatbot(env, (t_vec3d[3]){v[0], vi, v[1]}, t);
		flattop(env, (t_vec3d[3]){vi, v[1], v[2]}, t);
	}
}

void	fill_triangle_unit(t_env *env, t_triangle t)
{
	t_vec3d	v[3];

	ft_memcpy(&v[0], &t.points[0], sizeof(t_vec3d) * 3);
	v[1].y < v[0].y ? vec3d_swap(&v[0], &v[1]) : 0;
	v[2].y < v[1].y ? vec3d_swap(&v[1], &v[2]) : 0;
	v[1].y < v[0].y ? vec3d_swap(&v[0], &v[1]) : 0;

	if (v[0].y == v[1].y)
	{
		v[1].x < v[0].x ? vec3d_swap(&v[0], &v[1]) : 0;
		flattop(env, v, t);
	}
	else if (v[1].y == v[2].y)
	{
		v[2].x < v[1].x ? vec3d_swap(&v[1], &v[2]) : 0;
		flatbot(env, v, t);
	}
	else
		classic(env, v, t);
}
