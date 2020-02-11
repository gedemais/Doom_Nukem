/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 04:59:34 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/11 05:09:06 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ts_to_dev(t_env *env)
{
	(void)env;
	mlx_mouse_hide();
}

void	ts_to_campaign(t_env *env)
{
	(void)env;
	mlx_mouse_hide();
}

void	ts_to_custom(t_env *env)
{
	(void)env;
	mlx_mouse_hide();
}

void	ts_to_map_editor(t_env *env)
{
	(void)env;
	mlx_mouse_hide();
}

void	campaign_to_ts(t_env *env)
{
	(void)env;
	mlx_mouse_show();
}

void	custom_to_ts(t_env *env)
{
	(void)env;
	mlx_mouse_show();
}

void	map_editor_to_ts(t_env *env)
{
	(void)env;
	mlx_mouse_show();
}
