/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:53:57 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/15 20:00:18 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	custom_to_ts(t_env *env)
{
	mlx_mouse_show();
	ft_free_ctab(env->scroll.list);
	env->scroll.list = NULL;
	ft_strdel(&env->scroll.s_path);
}

void	map_editor_to_ts(t_env *env)
{
	ft_free_ctab(env->scroll.list);
	env->scroll.list = NULL;
	ft_strdel(&env->scroll.s_path);
}
