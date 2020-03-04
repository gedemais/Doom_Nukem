/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:50:02 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/04 17:32:26 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	doom_nukem(t_env *env)
{
	if (setup(env))
		return (-1);
	env->context = C_DEV;
	env->scene = SCENE_A;
	mlx_mouse_move(env->mlx.mlx_win, WDT / 2, HGT / 2);
	mlx_hooks(env);
	return (0);
}

int			main(void)
{
	t_env	env;

	ft_memset(&env, 0, sizeof(t_env));
	if (doom_nukem(&env))
	{
		ft_putstr_fd("Error\n", 2);
		free_env(&env);
		return (1);
	}
	free_env(&env);
	return (0);
}
