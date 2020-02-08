/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_triangle_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:50:11 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/08 04:49:47 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	swap_floats(float *a, float *b)
{
	float	c;

	c = *a;
	*a = *b;
	*b = c;
}

static void	starting_swap(t_triangle *t)
{
	if (t->points[1].y < t->points[0].y)
	{
		swap_floats(&t->points[0].y, &t->points[1].y);
		swap_floats(&t->points[0].x, &t->points[1].x);
		swap_floats(&t->txt[0].u, &t->txt[1].u);
		swap_floats(&t->txt[0].v, &t->txt[1].v);
		swap_floats(&t->txt[0].w, &t->txt[1].w);
	}
	if (t->points[2].y < t->points[0].y)
	{
		swap_floats(&t->points[2].y, &t->points[0].y);
		swap_floats(&t->points[2].x, &t->points[0].x);
		swap_floats(&t->txt[2].u, &t->txt[0].u);
		swap_floats(&t->txt[2].v, &t->txt[0].v);
		swap_floats(&t->txt[2].w, &t->txt[0].w);
	}
	if (t->points[2].y < t->points[1].y)
	{
		swap_floats(&t->points[2].y, &t->points[1].y);
		swap_floats(&t->points[2].x, &t->points[1].x);
		swap_floats(&t->txt[2].u, &t->txt[1].u);
		swap_floats(&t->txt[2].v, &t->txt[1].v);
		swap_floats(&t->txt[2].w, &t->txt[1].w);
	}
}

static void	compute_gradients(t_texturizer *txt, t_triangle t)
{
	txt->dx1 = t.points[1].x - t.points[0].x; // *
	txt->dy1 = t.points[1].y - t.points[0].y;
	txt->du1 = t.txt[1].u - t.txt[0].u;
	txt->dv1 = t.txt[1].v - t.txt[0].v;
	txt->dw1 = t.txt[1].w - t.txt[0].w;

	txt->dx2 = t.points[2].x - t.points[0].x;
	txt->dy2 = t.points[2].y - t.points[0].y;
	txt->du2 = t.txt[2].u - t.txt[0].u;
	txt->dv2 = t.txt[2].v - t.txt[0].v;
	txt->dw2 = t.txt[2].w - t.txt[0].w;

	if (txt->dy1)
		txt->ax_step = txt->dx1 / fabs((float)txt->dy1);
	if (txt->dy2)
		txt->bx_step = txt->dx2 / fabs((float)txt->dy2);

	if (txt->dy1)
		txt->u1_step = txt->du1 / fabs((float)txt->dy1);
	if (txt->dy1)
		txt->v1_step = txt->dv1 / fabs((float)txt->dy1);
	if (txt->dy1)
		txt->w1_step = txt->dw1 / fabs((float)txt->dy1);

	if (txt->dy2)
		txt->u2_step = txt->du2 / fabs((float)txt->dy2);
	if (txt->dy2)
		txt->v2_step = txt->dv2 / fabs((float)txt->dy2);
	if (txt->dy2)
		txt->w2_step = txt->dw2 / fabs((float)txt->dy2);
}
/*
static void	flatbot(t_env *env, t_texturizer *txt, t_triangle t)
{
	
}*/

static void	flattop(t_env *env, t_texturizer *txt, t_triangle t)
{
	unsigned int	i;
	unsigned int	j;
	float			tx;
	int				color;

	i = t.points[0].y;
	while (i <= t.points[1].y)
	{
		txt->ax = t.points[0].x + (float)(i - t.points[0].y) * txt->ax_step;
		txt->bx = t.points[0].x + (float)(i - t.points[0].y) * txt->bx_step;

		txt->txt_su = t.txt[0].u + (float)(i - t.points[0].y) * txt->u1_step;
		txt->txt_sv = t.txt[0].v + (float)(i - t.points[0].y) * txt->v1_step;
		txt->txt_sw = t.txt[0].w + (float)(i - t.points[0].y) * txt->w1_step;

		txt->txt_eu = t.txt[0].u + (float)(i - t.points[0].y) * txt->u2_step;
		txt->txt_ev = t.txt[0].v + (float)(i - t.points[0].y) * txt->v2_step;
		txt->txt_ew = t.txt[0].w + (float)(i - t.points[0].y) * txt->w2_step;

		if (txt->ax > txt->bx)
		{
			ft_swap(&txt->ax, &txt->bx);
			swap_floats(&txt->txt_su, &txt->txt_eu);
			swap_floats(&txt->txt_sv, &txt->txt_ev);
		}
		txt->txt_u = txt->txt_su;
		txt->txt_v = txt->txt_sv;
		txt->txt_w = txt->txt_sw;

		txt->t_step = 1.0f / (float)(txt->bx - txt->ax);
		tx = 0.0f;
		j = txt->ax;
		while (j < (unsigned)txt->bx)
		{
			txt->txt_u = (1.0f - tx) * txt->txt_su + tx * txt->txt_eu;
			txt->txt_v = (1.0f - tx) * txt->txt_sv + tx * txt->txt_ev;
			txt->txt_w = (1.0f - tx) * txt->txt_sw + tx * txt->txt_ew;

			color = sample_pixel(env->sprites[TXT_WOOD].img_data,
			(t_point){env->sprites[TXT_WOOD].hgt, env->sprites[TXT_WOOD].wdt},
			(t_vec2d){txt->txt_u / txt->txt_w, txt->txt_v / txt->txt_w, 1.0f});
			color = shade_color(color, t.illum);
			draw_pixel(env->mlx.img_data, j, i, color);
			tx += txt->t_step;
			j++;
		}
		i++;
	}
}


static void	blit_texture(t_env *env, t_texturizer *txt, t_triangle t)
{
	unsigned int	i;
	unsigned int	j;
	float			tx;
	int				color;

	flattop(env, txt, t);

	txt->dy1 = t.points[2].y - t.points[1].y; // *
	txt->dx1 = t.points[2].x - t.points[1].x;
	txt->du1 = t.txt[2].u - t.txt[1].u;
	txt->dv1 = t.txt[2].v - t.txt[1].v;
	txt->dw1 = t.txt[2].w - t.txt[1].w;

	if (txt->dy1)
		txt->ax_step = txt->dx1 / fabs((float)txt->dy1);
	if (txt->dy2)
		txt->bx_step = txt->dx2 / fabs((float)txt->dy2);

	if (txt->dy1)
		txt->u1_step = txt->du1 / fabs((float)txt->dy1);
	if (txt->dy1)
		txt->v1_step = txt->dv1 / fabs((float)txt->dy1);
	if (txt->dy1)
		txt->w1_step = txt->dw1 / fabs((float)txt->dy1);
	
	i = t.points[1].y;
	while (i <= t.points[2].y)
	{
		txt->ax = t.points[1].x + (float)(i - t.points[1].y) * txt->ax_step;
		txt->bx = t.points[0].x + (float)(i - t.points[0].y) * txt->bx_step;

		txt->txt_su = t.txt[1].u + (float)(i - t.points[1].y) * txt->u1_step;
		txt->txt_sv = t.txt[1].v + (float)(i - t.points[1].y) * txt->v1_step;
		txt->txt_sw = t.txt[0].w + (float)(i - t.points[0].y) * txt->w1_step;

		txt->txt_eu = t.txt[0].u + (float)(i - t.points[0].y) * txt->u2_step;
		txt->txt_ev = t.txt[0].v + (float)(i - t.points[0].y) * txt->v2_step;
		txt->txt_ew = t.txt[0].w + (float)(i - t.points[0].y) * txt->w2_step;

		if (txt->ax > txt->bx)
		{
			ft_swap(&txt->ax, &txt->bx);
			swap_floats(&txt->txt_su, &txt->txt_eu);
			swap_floats(&txt->txt_sv, &txt->txt_ev);
		}
		txt->txt_u = txt->txt_su;
		txt->txt_v = txt->txt_sv;
		txt->txt_w = txt->txt_sw;

		txt->t_step = 1.0f / (float)(txt->bx - txt->ax);
		tx = 0.0f;
		j = txt->ax;
		while (j < (unsigned)txt->bx)
		{
			txt->txt_u = (1.0f - tx) * txt->txt_su + tx * txt->txt_eu;
			txt->txt_v = (1.0f - tx) * txt->txt_sv + tx * txt->txt_ev;
			txt->txt_w = (1.0f - tx) * txt->txt_sw + tx * txt->txt_ew;

			color = sample_pixel(env->sprites[TXT_WOOD].img_data,
			(t_point){env->sprites[TXT_WOOD].wdt, env->sprites[TXT_WOOD].hgt},
			(t_vec2d){txt->txt_u / txt->txt_w, txt->txt_v / txt->txt_w, 1.0f});
			color = shade_color(color, t.illum);
			draw_pixel(env->mlx.img_data, j, i, color);
			tx += txt->t_step;
			j++;
		}
		i++;
	}

}

void		fill_triangle_texture(t_env *env, t_triangle t)
{
	t_texturizer	txt;

	txt = (t_texturizer){};
	(void)env;
	starting_swap(&t);
	compute_gradients(&txt, t);
	blit_texture(env, &txt, t);
}
