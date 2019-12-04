/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:11:52 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/04 07:43:02 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * Pour definir les hooks a utiliser par type d'event / contexte du programme,
 * on utilisera des tableaux de pointeurs sur fonction (1 par type d'evenement,
 * pour eviter les conflits de typage dans le tableau)
 */

void		mlx_hooks(t_env *env)
{
	//static int	(*moves_fts[NB_MOVES])(t_env*) = {&swap_a, &swap_b};
	void			*win;

	win = env->mlx.mlx_win;
	mlx_hook(win, 2, E_KEY_PRESS, (int(*)(void))key_press, env);
	mlx_hook(win, 3, E_KEY_RELEASE, (int(*)(void))key_release, env);
	mlx_hook(win, 4, E_MOUSE_PRESS, (int(*)(void))mouse_press, env);
	mlx_hook(win, 4, E_MOUSE_RELEASE, (int(*)(void))mouse_release, env);
	mlx_hook(win, 6, E_MOUSE_POSITION, (int(*)(void))mouse_position, env);
	mlx_hook(win, 17, E_CLOSE, (int(*)(void))exit, (void*)0);
	mlx_loop_hook(env->mlx.mlx_ptr, (int(*)(void))render, (void*)env);
	mlx_loop(env->mlx.mlx_ptr);
}
