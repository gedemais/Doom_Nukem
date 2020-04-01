/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 04:59:34 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/31 21:44:32 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ts_to_dev(t_env *env)
{
	(void)env;
	mlx_mouse_hide();
	play_ambience(env->sound.samples[SA_TITLE_SCREEN_S], false, true, false);
	loop_sample(env->sound.samples[SA_TITLE_SCREEN_L], false, true, false);
}

void	ts_to_campaign(t_env *env)
{
	(void)env;
	mlx_mouse_hide();
}

void	ts_to_custom(t_env *env)
{
	(void)env;
//	mlx_mouse_hide();
}

void	ts_to_map_editor(t_env *env)
{
	(void)env;
//	mlx_mouse_hide();
}

void	campaign_to_ts(t_env *env)
{
	(void)env;
	mlx_mouse_show();
}
