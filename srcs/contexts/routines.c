/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 04:59:34 by gedemais          #+#    #+#             */
/*   Updated: 2020/05/05 17:19:23 by gedemais         ###   ########.fr       */
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
	env->cmp_env.sub_context = CMP_SC_MENU;
}

void	ts_to_custom(t_env *env)
{
	(void)env;
//	if (init_custom_scroll_file(env))
//		exit(1);
//	mlx_mouse_hide();
}

void	ts_to_map_editor(t_env *env)
{
	if (init_maped_scroll_file(env))
		exit(1);
}

void	campaign_to_ts(t_env *env)
{
	(void)env;
	mlx_mouse_show();
}
