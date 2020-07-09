/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 16:11:40 by grudler           #+#    #+#             */
/*   Updated: 2020/07/09 17:54:20 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	draw_physic(t_env *env)
{
	t_ttf_config	*conf;
	char *str;

	conf = ttf_config();
	conf->size = 16;
	if (env->phy_env.type_move == true && !(str = ft_strjoin("Physic : ", "On")))
		return (-1);
	else if (env->phy_env.type_move == false && !(str = ft_strjoin("Physic : ", "Off")))
		return (-1);
	ft_strcpy((char*)conf->s, str);
	free(str);
	my_string_put(env, env->mlx.img_data, (t_point){35, 35}, FONT_COOLVETICA);
	return (0);
}

static int	draw_wave(t_env *env)
{
	t_ttf_config	*conf;
	char			*str;
	char			*s;

	conf = ttf_config();
	conf->size = 20;
	if (!(s = ft_itoa(env->custom_env.game.wave)))
		return (-1);
	if (!(str = ft_strjoin("Wave ", s)))
	{
		free(s);
		return (-1);
	}
	free(s);
	ft_strcpy((char*)conf->s, str);
	free(str);
	my_string_put(env, env->mlx.img_data, (t_point){0.04 * WDT, 0.85 * HGT}, FONT_COOLVETICA);
	return (0);
}

int		draw_hud(t_env *env)
{
	draw_health(env);
	draw_compass(env);
	draw_wave(env);
	if(env->data.time.tv_sec <= env->hud.timePhysic + 2)
		draw_physic(env);
	map_sprite(env->mlx.img_data, env->sprites[SP_COIN], (t_point){900, 38});
	return(0);
}
