/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 16:11:40 by grudler           #+#    #+#             */
/*   Updated: 2020/07/08 22:01:26 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	my_string_put(env, env->mlx.img_data, (t_point){42, 642}, FONT_COOLVETICA);
	return (0);
}

int		draw_hud(t_env *env)
{
	draw_health(env);
	draw_compass(env);
	draw_wave(env);
	return(0);

}
