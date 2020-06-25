/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 16:12:34 by grudler           #+#    #+#             */
/*   Updated: 2020/06/25 20:45:42 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		draw_health(t_env *env)
{
	t_ttf_config	*conf;
	int color;
	char *test;

	conf = ttf_config();
	ft_strcpy((char *)conf->s, "HP");
	env->player.hp = 100;
	if (env->player.hp <= HP_MAX * 1/3)
		color = RED_HEALTH;
	else if (env->player.hp > HP_MAX * 2/3)
		color = GREEN_HEALTH;
	else
		color = ORA_HEALTH;
	draw_rectangle(env->mlx.img_data, (t_point){0.02 * WDT, 0.9 * HGT}, (t_point){0.20 * WDT * env->player.hp / HP_MAX, 15}, color);
	my_string_put(env, env->mlx.img_data, (t_point){0.02 * WDT, 0.85 * HGT + 15}, FONT_ARIAL);
	test = ft_strjoin(ft_itoa(env->player.hp), "/");
	test = ft_strjoin(test, ft_itoa(HP_MAX));
	ft_strcpy((char*)conf->s, test);
	my_string_put(env, env->mlx.img_data, (t_point){0.05 * WDT, 0.85 * HGT + 15}, FONT_ARIAL);
	free(test);
	return(0);
}
