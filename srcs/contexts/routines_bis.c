/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:53:57 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/15 13:17:16 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	custom_to_ts(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	ft_free_ctab(env->scroll.list);
	mlx_mouse_show();
}

void	map_editor_to_ts(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	ft_free_ctab(env->scroll.list);
}
