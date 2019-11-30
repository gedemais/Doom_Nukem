/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:34:45 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/30 00:47:10 by demaisonc        ###   ########.fr       */
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
	if (init_mlx(&env->mlx)
		|| !(env->sprites = load_sprites(env->mlx)))
		return (-1);
	load_values(env);
	if (init_openal(&env->sound))
		return (-1);
	return (0);
}
