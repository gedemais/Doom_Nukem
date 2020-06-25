/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 08:22:11 by grudler           #+#    #+#             */
/*   Updated: 2020/06/25 18:52:08 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		draw_ennemies_indicator(t_env *env)
{
	int		i;
	t_enemy	*mob;
	t_dynarray *mobs = &env->mobs;
	float angle;

	t_vec3d sub;

	draw_rectangle(env->mlx.img_data, (t_point){env->data.third_wdt, 35}, (t_point){env->data.third_wdt, 35}, DARK_GREY);
	draw_rectangle(env->mlx.img_data, (t_point){WDT / 2 - 2, 35}, (t_point){4, 35}, LIGHT_GREY);

	i = -1;
	while (++i < mobs->nb_cells)
	{
		mob = dyacc(mobs, i);
		sub = vec_normalize(vec_sub(mob->pos, env->cam.stats.pos));
		angle = atan2(vec2d_det_xz(vec_normalize(env->cam.stats.dir), sub), vec2d_dot_xz(vec_normalize(env->cam.stats.dir), sub)) * (180 / M_PI);

		if (WDT * (angle + 180) / 360 > env->data.third_wdt && WDT * (angle + 180) / 360 + 2 < env->data.third_wdt * 2)
			draw_rectangle(env->mlx.img_data, (t_point){WDT * ((angle + 180) / 360), 45}, (t_point){2, 15}, NORMAL_RED);
	}
}

void	print_cord(t_env *env, float index, t_point points, bool east)
{
	t_ttf_config	*conf;
	char *cord;

	conf = ttf_config();
	if (index == 0)
		cord = "S";
	else if (index == 180)
		cord = "N";
	else if (index == 90)
		cord = (east ? "E" : "W");
	else
		cord = "I";
	ft_strcpy((char*)conf->s, cord);
	my_string_put(env, env->mlx.img_data, points, FONT_COOLVETICA);
}

void	draw_coordinates(t_env *env)
{
	t_vec3d		nord;
	float		angle;
	float		index;

	nord = (t_vec3d){1,0,0,0};
	angle = atan2(vec2d_det_xz(env->cam.stats.dir, nord), vec2d_dot_xz(env->cam.stats.dir, nord)) * (180 / M_PI);
	index = 0;
	while (index <= 360)
	{
		angle = angle < 0 ? 180 + (180 + angle) : angle;
		if ((angle / 360 - index / 360) * WDT > env->data.third_wdt && (angle / 360 - index / 360) * WDT + 10 < env->data.third_wdt * 2)
			print_cord(env, index, (t_point){(angle / 360 - index / 360) * WDT, 60}, true);
		if ((angle / 360 + index / 360) * WDT > env->data.third_wdt && (angle / 360 + index / 360) * WDT + 10 < env->data.third_wdt * 2)
			print_cord(env, index, (t_point){(angle / 360 + index / 360) * WDT, 60}, false);
		index += 10;
	}
}

void		draw_compass(t_env *env)
{
	draw_ennemies_indicator(env);
	draw_coordinates(env);
}
