/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:34:45 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/09 10:30:10 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		load_values(t_env *env, t_data *data)
{
	(void)env;
	data->half_wdt = (float)WDT / 2;
	data->half_hgt = (float)HGT / 2;
}

int				setup(t_env *env)
{
	if (init_mlx(env) != 0
		|| !(env->sprites = load_sprites(&env->mlx)))
		return (-1);
	if (init_openal(&env->sound) != 0 || load_maps(env) != 0)
		return (-1);
	init_camera(&env->cam);
	load_values(env, &env->data);
	env->context = C_DEV;
//	play_ambience(env->sound.samples[SA_AMB_1], true, false);
	return (0);
}
