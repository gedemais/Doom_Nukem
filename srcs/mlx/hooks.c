/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:11:52 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/29 06:24:55 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	mlx_hooks(t_env *env)
{
	mlx_hook(env->mlx.mlx_win, KEY_PRESS, KEY_PRESS_MASK,
		(int(*)(void))key_press, &env);
	mlx_hook(env->mlx.mlx_win, KEY_RELEASE, KEY_RELEASE_MASK,
		(int(*)(void))key_release, &env);
	mlx_hook(env->mlx.mlx_win, 4, (1L << 2), (int(*)(void))mouse_press, env);
	mlx_hook(env->mlx.mlx_win, 4, (1L << 3), (int(*)(void))mouse_release, env);
	mlx_hook(env->mlx.mlx_win, 6, 0, (int(*)(void))mouse_position, &env);
	mlx_loop_hook(env->mlx.mlx_ptr, (int(*)(void))render, env);
	mlx_hook(env->mlx.mlx_win, 17, (1L << 17), (int(*)(void))exit, (void*)0);
	mlx_loop(env->mlx.mlx_ptr);
}
