/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:50:02 by gedemais          #+#    #+#             */
/*   Updated: 2020/05/02 23:08:18 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	doom_nukem(t_env *env)
{
	srand(time(NULL));
	if (setup(env))
		return (-1);

	// Ajouter toutes les armes dans l'inventaire du joueur
	for (int i = 0; i < W_MAX; i++)
		push_dynarray(&env->cmp_env.player.weapons, &env->cmp_env.weapons[i], false);

	env->cmp_env.player.current = dyacc(&env->cmp_env.player.weapons, W_FAMAS);
	env->cmp_env.player.current->ammos = 120;
	env->cmp_env.player.current->magazine = 30;
	env->cmp_env.player.current->loaded = 30;

	env->context = C_MAP_EDITOR;
	env->scene = SCENE_E1;
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
