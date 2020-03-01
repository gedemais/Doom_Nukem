#include "main.h"

static float	vec3d_edge(t_vec3d a, t_vec3d b, t_vec3d c)
{
	return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}

static t_vec3d	calc_w(t_triangle t, t_point px)
{
	float	area;
	t_vec3d	ret;
	t_vec3d	pixel;

	area = vec3d_edge(t.points[0], t.points[1], t.points[2]);
	pixel = (t_vec3d){px.x, px.y, 0, 0};
	ret = (t_vec3d){
		vec3d_edge(t.points[1], t.points[2], pixel) / area,
		vec3d_edge(t.points[2], t.points[0], pixel) / area,
		vec3d_edge(t.points[0], t.points[1], pixel) / area, 0};
	return (ret);
}

static void	write_pixel(t_env *env, t_triangle t, t_point px, t_filler *fill)
{
	t_vec3d	w;
	int		p;

	w = calc_w(t, px);
	p = (px.y - 1) * WDT + px.x;
	fill->w = 1.0f / ((t.txt[0].w * w.x) + (t.txt[1].w * w.y) + (t.txt[2].w * w.z));
	if (fill->w <= env->cam.z_buffer[p])
	{
		env->cam.z_buffer[p] = fill->w;
		draw_pixel(env->mlx.img_data, px.x, px.y, t.color);
	}
	fill->tx += fill->xstep;
}

static void	draw_triangle_line_unit(t_env *env, int y, t_triangle t, t_filler *fill)
{
	int		x;

	x = fill->xstart > 0 ? fill->xstart : 1;
	fill->tx = 0.0f;
	fill->xstep = 1.0f / (fill->xstart - fill->xend);
	while (x < fill->xend)
	{
		write_pixel(env, t, (t_point){x, y}, fill);
		x++;
	}
}

static void	flatbot(t_env *env, t_vec3d v[3], t_triangle t)
{
	t_filler	fill;
	float		txt;
	int			y;

	fill.m0 = (v[1].x - v[0].x) / (v[1].y - v[0].y);
	fill.m1 = (v[2].x - v[0].x) / (v[2].y - v[0].y);
	fill.ystart = (int)ceil(v[0].y - 0.5f);
	fill.yend = (int)ceil(v[2].y - 0.5f);
	y = fill.ystart > 0 ? fill.ystart : 1;
	txt = y + 0.5f - v[0].y;

	fill.ty = 0.0f;
	fill.ystep = 1.0f / (fill.ystart - fill.yend);
	while (y < fill.yend)
	{
		fill.xstart = (int)((fill.m0 * txt + v[0].x) - 0.5f);
		fill.xend = (int)((fill.m1 * txt + v[0].x) - 0.5f);
		draw_triangle_line_unit(env, y, t, &fill);
		fill.ty += fill.ystep;
		txt += 1.0f;
		y++;
	}
}

static void		flattop(t_env *env, t_vec3d v[3], t_triangle t)
{
	t_filler	fill;
	float		txta;
	float		txtb;
	int			y;

	fill.m0 = (v[2].x - v[0].x) / (v[2].y - v[0].y);
	fill.m1 = (v[2].x - v[1].x) / (v[2].y - v[1].y);
	fill.ystart = (int)ceil(v[0].y - 0.5f);
	fill.yend = (int)ceil(v[2].y - 0.5f);
	y = fill.ystart > 0 ? fill.ystart : 1;
	txta = (y + 0.5f - v[0].y);
	txtb = (y + 0.5f - v[1].y);

	fill.ty = 0.0f;
	fill.ystep = 1.0f / (fill.ystart - fill.yend);
	while (y < fill.yend)
	{
		fill.xstart = (int)((fill.m0 * txta + v[0].x) - 0.5f);
		fill.xend = (int)((fill.m1 * txtb + v[1].x) - 0.5f);
		draw_triangle_line_unit(env, y, t, &fill);
		fill.ty += fill.ystep;
		txta += 1.0f;
		txtb += 1.0f;
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
