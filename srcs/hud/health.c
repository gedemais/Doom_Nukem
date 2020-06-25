/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 16:12:34 by grudler           #+#    #+#             */
/*   Updated: 2020/06/25 18:59:19 by grudler          ###   ########.fr       */
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
	if (env->player.hp <= 0.33 * HP_MAX)
		color = RED_HEALTH;
	else if (env->player.hp > 0.67 * HP_MAX)
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
