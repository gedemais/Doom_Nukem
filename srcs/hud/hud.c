/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 16:11:40 by grudler           #+#    #+#             */
/*   Updated: 2020/07/09 19:33:26 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		draw_hud(t_env *env)
{
	draw_compass(env);
	if (draw_wave(env) || draw_health(env)
		|| print_countdown(env, env->custom_env.game.countdown))
		return (-1);
	return(0);

}
