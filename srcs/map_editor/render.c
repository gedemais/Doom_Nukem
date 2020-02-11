/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:51:39 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/10 22:04:23 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		render_maped(void *param)
{
	t_env	*env;

	env = ((t_env*)param);

	if (env->events.keys[KEY_M])
		switch_context(env, C_TITLE_SCREEN);
	ft_memset(env->mlx.img_data, 0, sizeof(int) * WDT * HGT);
/********************************************/
/********************************************/
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	//mlx_string_put(env->mlx.mlx_ptr, env->mlx.mlx_win, 10, 10, 0xffffff, "Contexte : map editor");
	return (0);
}
