/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:34:45 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/07 01:27:28 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		load_values(t_env *env, t_data *data)
{
	(void)env;
	data->half_wdt = (float)WDT / 2;
	data->half_hgt = (float)HGT / 2;
	data->data_size = WDT * HGT * sizeof(int);
}

static int		init_contexts(t_env *env)
{
	if (setup_ts(env))
		return (-1);
	if (setup_cmp(env))
		return (-1);	// = > t_cmpenv 
	if (setup_medit(env))
		return (-1);
	return (0);
}

int				setup(t_env *env)
{
	if (init_mlx(env) != 0 || !(env->sprites = load_sprites(&env->mlx))
		|| init_openal(&env->sound) != 0 || load_maps(env) != 0
		|| init_contexts(env) || init_physic_engine(env)
		|| init_camera(env, &env->cam))
		return (-1);
	load_values(env, &env->data);
//	play_ambience(env->sound.samples[SA_AMB_1], true, false);
	return (0);
}
