/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:41:22 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/14 17:41:32 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	me_menu_to_new_map(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	env->ttfs.fields[0].rendered = true;
	env->ttfs.fields[1].rendered = true;
	env->ttfs.fields[2].rendered = true;
	env->ttfs.fields[3].rendered = true;
	return (0);
}

int	me_menu_to_creative(t_env *env)
{
	env->cam.stats.pos = zero_vector();
	env->cam.stats.pitch = 0;
	env->cam.stats.yaw = 0;
	env->mid.mesh = NULL;
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	mlx_mouse_hide();
	return (0);
}

int	me_new_map_to_creative(t_env *env)
{
	env->cam.stats.pos = zero_vector();
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	mlx_mouse_hide();
	return (0);
}

int	me_new_map_to_menu(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	env->ttfs.fields[0].rendered = false;
	env->ttfs.fields[1].rendered = false;
	env->ttfs.fields[2].rendered = false;
	env->ttfs.fields[3].rendered = false;
	return (0);
}

int	me_creative_to_menu(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	free_maped(env);
	mlx_mouse_show();
	return (0);
}
