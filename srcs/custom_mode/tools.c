/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:47:31 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/17 15:18:49 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		add_random_weapon(t_env *env)
{
	t_weapon	*w;
	int			index;
	int			i;
	bool		same;

	same = true;
	while (same)
	{
		i = -1;
		same = false;
		index = rand() % W_MAX;
		while (++i < env->player.weapons.nb_cells)
		{
			w = dyacc(&env->player.weapons, i);
			if (w->index == index && (same = true))
				break ;
		}
		if (i == env->player.weapons.nb_cells
			&& push_dynarray(&env->player.weapons, &env->weapons[index], 0))
			return (-1);
	}
	env->player.current = dyacc(&env->player.weapons,
		env->player.weapons.nb_cells - 1);
	env->player.current->ammos = env->player.current->max_ammos;
	return (0);
}
