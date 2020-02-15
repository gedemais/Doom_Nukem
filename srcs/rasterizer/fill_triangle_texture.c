/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_triangle_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:50:11 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/15 00:34:37 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	draw_triangle_line(t_env *env, t_texturizer *txt, t_triangle t, unsigned int i)
{
	unsigned int	j;
	float			tx;
	int				color;

	j = txt->ax;
	tx = 0.0f;
	txt->t_step = 1.0f / (float)(txt->bx - txt->ax); //inf
	while (j < (unsigned)txt->bx)
	{
		txt->txt_u = (1.0f - tx) * txt->txt_su + tx * txt->txt_eu;
		txt->txt_v = (1.0f - tx) * txt->txt_sv + tx * txt->txt_ev;
		txt->txt_w = (1.0f - tx) * txt->txt_sw + tx * txt->txt_ew;

		if (txt->txt_w > env->cam.z_buffer[i * WDT + j])
		{
			env->cam.z_buffer[i * WDT + j] = txt->txt_w;
			color = sample_pixel(env->sprites[TXT_BLOC_GRASS].img_data,
			(t_point){env->sprites[TXT_BLOC_GRASS].hgt, env->sprites[TXT_BLOC_GRASS].wdt},
			(t_vec2d){txt->txt_u / txt->txt_w, txt->txt_v / txt->txt_w, 1.0f});
			color = shade_color(color, t.illum);
			draw_pixel(env->mlx.img_data, j, i, color);
		}
		tx += txt->t_step;
		j++;
	}
}

static void	flattop(t_env *env, t_texturizer *txt, t_triangle t)
{
	unsigned int	i;

	i = t.points[0].y;
	while (i <= t.points[1].y)
	{
		set_line_bounds_top(txt, t, (float)(i - t.points[0].y));
		txt->txt_u = txt->txt_su;
		txt->txt_v = txt->txt_sv;
		txt->txt_w = txt->txt_sw;
		if (txt->ax == txt->bx && ++i)
			continue ;
		draw_triangle_line(env, txt, t, i);
		i++;
	}
}

static void	flatbot(t_env *env, t_texturizer *txt, t_triangle t)
{
	unsigned int	i;

	i = t.points[1].y;
	while (i <= t.points[2].y)
	{
		set_line_bounds_bot(txt, t, (float[2]){(i - t.points[0].y), (i - t.points[1].y)});
		txt->txt_u = txt->txt_su;
		txt->txt_v = txt->txt_sv;
		txt->txt_w = txt->txt_sw;
		if (txt->ax == txt->bx && ++i)
			continue ;
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
	flattop(env, &txt, t);
	compute_gradients(&txt, t, true);
	flatbot(env, &txt, t);
}
