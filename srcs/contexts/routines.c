/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 04:59:34 by gedemais          #+#    #+#             */
/*   Updated: 2020/06/06 15:40:49 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ts_to_dev(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	mlx_mouse_hide();
}

void	ts_to_campaign(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	env->cmp_env.sub_context = CMP_SC_MENU;
}

void	ts_to_custom(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	if (init_scroll_file(env, MAPED_SAVE_PATH, ".map"))
		exit(1);
	env->scroll.o = (t_point){WDT / 12, HGT / 4 };
	env->scroll.d = (t_point){WDT / 3, HGT - HGT / 4};
}

void	ts_to_map_editor(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	if (init_scroll_file(env, MAPED_SAVE_PATH, ".map"))
		exit(1);
}

void	campaign_to_ts(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	mlx_mouse_show();
}
