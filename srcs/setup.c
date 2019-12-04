/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:34:45 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/04 03:52:47 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	load_values(t_env *env)
{
	env->mlx.half_hgt = HGT / 2;
	env->mlx.half_wdt = WDT / 2;
}

int			setup(t_env *env)
{
	if (init_mlx(env) != 0
		|| !(env->sprites = load_sprites()))
		return (-1);
	load_values(env);
	if (init_openal(&env->sound) != 0)
		return (-1);
	init_camera(&env->cam);
//	play_ambience(env->sound.samples[SA_AMB_1], true, false);
	return (0);
}
