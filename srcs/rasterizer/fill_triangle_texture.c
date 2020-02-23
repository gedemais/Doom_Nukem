/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_triangle_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:50:11 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/22 20:54:07 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	write_pixel(t_env *env, t_texturizer *txt, t_triangle t, int pos[2])
{
	float	cu;
	float	cv;
	int		color;
	int		px;

	px = abs(pos[0] - 1) * WDT + pos[1];
	if (txt->txt_w > env->cam.z_buffer[px])
	{
		cu = t.textured ? txt->txt_u / txt->txt_w : txt->txt_u;
		cv = t.textured ? txt->txt_v / txt->txt_w : txt->txt_v;
		env->cam.z_buffer[px] = txt->txt_w;
		if (t.textured)
		{
			color = sample_pixel(env->sprites[TXT_BLOC_GRASS].img_data,
			(t_point){env->sprites[TXT_BLOC_GRASS].hgt, env->sprites[TXT_BLOC_GRASS].wdt},
			(t_vec2d){cu, cv, 1.0f});
		}
		else
			color = t.color;
		color = shade_color(color, t.illum);
		draw_pixel(env->mlx.img_data, pos[1], pos[0], color);
	}
}

static void	draw_triangle_line(t_env *env, t_texturizer *txt, t_triangle t, int i)
{
	int				j;
	float			tx;
	float			sub_tx;

	tx = 0.0f;
	j = txt->ax;
	txt->t_step = 1.0f / (txt->bx - txt->ax);
	while (j < txt->bx)
	{
		sub_tx = 1.0f - tx;
		txt->txt_u = t.textured ? sub_tx * txt->txt_su + tx * txt->txt_eu : 0;
		txt->txt_v = t.textured ? sub_tx * txt->txt_sv + tx * txt->txt_ev : 0;
		txt->txt_w = sub_tx * txt->txt_sw + tx * txt->txt_ew;

		write_pixel(env, txt, t, (int[2]){i, j});
		tx += txt->t_step;
		j++;
	}
}

static void	flattop(t_env *env, t_texturizer *txt, t_triangle t)
{
	int		i;

	i = t.points[0].y;
	//printf("flattop\n");
	while (i <= t.points[1].y)
	{
		set_line_bounds_top(txt, t, fabs(i - t.points[0].y));
		txt->txt_u = txt->txt_su;
		txt->txt_v = txt->txt_sv;
		txt->txt_w = txt->txt_sw;
		draw_triangle_line(env, txt, t, i);
		i++;
	}
}

static void	flatbot(t_env *env, t_texturizer *txt, t_triangle t)
{
	int		i;

	i = t.points[1].y ;
//	printf("flatbot\n");
	while (i <= t.points[2].y)
	{
		set_line_bounds_bot(txt, t, (float[2]){fabs(i - t.points[0].y), fabs(i - t.points[1].y)});
		txt->txt_u = txt->txt_su;
		txt->txt_v = txt->txt_sv;
		txt->txt_w = txt->txt_sw;
		draw_triangle_line(env, txt, t, i);
		i++;
	}
}

void		fill_triangle_texture(t_env *env, t_triangle t)
{
	t_texturizer	txt;

	txt = (t_texturizer){};
	starting_swap(&t);
	compute_gradients(&txt, t, false);
	if (txt.dy1)
		flattop(env, &txt, t);
	compute_gradients(&txt, t, true);
	flatbot(env, &txt, t);
}
