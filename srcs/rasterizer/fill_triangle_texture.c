/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_triangle_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:50:11 by gedemais          #+#    #+#             */
/*   Updated: 2020/05/30 15:12:10 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	write_pixel(t_env *env, t_texturizer *txt, t_triangle *t, int pos[4])
{
	float		cu;
	float		cv;
	int			color;

	if (txt->txt_w < env->cam.z_buffer[pos[2]])
		return ;
	if (t->voxel)
		if (pos[0] == env->data.half_hgt)
			if (pos[1] == env->data.half_wdt)
				env->mid = *t;
	if (t->sp >= 0 && t->textured)
	{
		cu = txt->txt_u / txt->txt_w;
		cv = txt->txt_v / txt->txt_w;
		color = sample_pixel(txt->texture->img_data,
			(t_point){txt->texture->hgt, txt->texture->wdt},
			(t_vec2d){cu, cv, 1.0f});
		color = shade_color(color, t->illum);
	}
	else
		color = t->color;
	env->cam.z_buffer[pos[2]] = txt->txt_w;
	*(int*)(&env->mlx.img_data[pos[3]]) = color;
}

static void	simplify_interpolation(t_texturizer *txt, float steps[6], float simples[6], bool textured)
{
	if (textured)
	{
		steps[0] = (txt->t_step * txt->txt_su);
		steps[1] = (txt->t_step * txt->txt_eu);
		steps[2] = (txt->t_step * txt->txt_sv);
		steps[3] = (txt->t_step * txt->txt_ev);
	}
	steps[4] = (txt->t_step * txt->txt_sw);
	steps[5] = (txt->t_step * txt->txt_ew);
	simples[0] = txt->txt_su;
	simples[1] = 0.0f;
	simples[2] = txt->txt_sv;
	simples[3] = 0.0f;
	simples[4] = txt->txt_sw;
	simples[5] = 0.0f;
}

static void	update_expr(float steps[6], float simples[6], bool textured)
{
	if (textured)
	{
		simples[0] -= steps[0];
		simples[1] += steps[1];
		simples[2] -= steps[2];
		simples[3] += steps[3];
	}
	simples[4] -= steps[4];
	simples[5] += steps[5];
}

static void	draw_triangle_line(t_env *env, t_texturizer *txt, t_triangle t, int i)
{
	int		j;
	int		px;
	int		addr;
	float	steps[6];
	float	simples[6];

	j = txt->ax;
	txt->t_step = 1.0f / (txt->bx - txt->ax);
	px = abs(i - 1) * WDT + j;
	addr = px * 4;
	simplify_interpolation(txt, steps, simples, t.textured);
	while (j < txt->bx)
	{
		if (t.textured)
		{
			txt->txt_u = simples[0] + simples[1];
			txt->txt_v = simples[2] + simples[3];
		}
		txt->txt_w = simples[4] + simples[5];
		update_expr(steps, simples, t.textured);
		write_pixel(env, txt, &t, (int[4]){i, j, px, addr});
		addr += 4;
		px++;
		j++;
	}
}

static void	flattop(t_env *env, t_texturizer *txt, t_triangle t)
{
	int		i;
	int		end;

	i = ceil(t.points[0].y);
	end = ceil(t.points[1].y);
	(void)env;
	while (i < end)
	{
		set_line_bounds_top(txt, t, i - t.points[0].y);
		txt->txt_u = txt->txt_su;
		txt->txt_v = txt->txt_sv;
		txt->txt_w = txt->txt_sw;
//		draw_triangle_line(env, txt, t, i);
		i++;
	}
}

static void	flatbot(t_env *env, t_texturizer *txt, t_triangle t)
{
	int		i;
	int		end;

	i = ceil(t.points[1].y);
	end = ceil(t.points[2].y);
	(void)env;
	while (i < end)
	{
		set_line_bounds_bot(txt, t, (float[2]){i - t.points[0].y, i - t.points[1].y});
		txt->txt_u = txt->txt_su;
		txt->txt_v = txt->txt_sv;
		txt->txt_w = txt->txt_sw;
//		draw_triangle_line(env, txt, t, i);
		i++;
	}
}

void		fill_triangle_texture(t_env *env, t_triangle t)
{
	t_texturizer	txt;

	txt = (t_texturizer){};
	starting_swap(&t);
	if (t.voxel)
		txt.texture = &env->edit_env.btxts[t.sp];
	else
		txt.texture = env->maps[env->scene].txts.c + (t.sp * sizeof(t_sprite));

	compute_gradients(&txt, t, false);
	if (txt.dy1)
		flattop(env, &txt, t);
	compute_gradients(&txt, t, true);
	if (txt.dy1)
		flatbot(env, &txt, t);
}
