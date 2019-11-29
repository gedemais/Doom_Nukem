/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:34:45 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/29 06:18:27 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	load_values(t_env *env)
{
	env->mlx.half_hgt = HGT / 2;
	env->mlx.half_wdt = WDT / 2;
}

int			setup(t_env *env)
{
	if (init_mlx(&env->mlx))
		return (-1);
	load_values(env);
	return (0);
}
