/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_context.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 01:24:57 by gedemais          #+#    #+#             */
/*   Updated: 2020/01/31 03:38:24 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	open_gates(bool gates[C_MAX][C_MAX])
{
	gates[C_DEV][C_TITLE_SCREEN] = true;
	gates[C_DEV][C_CAMPAIGN] = true;
	gates[C_DEV][C_CUSTOM] = true;
	gates[C_DEV][C_MAP_EDITOR] = true;

	gates[C_TITLE_SCREEN][C_DEV] = true;
	gates[C_TITLE_SCREEN][C_CAMPAIGN] = true;
	gates[C_TITLE_SCREEN][C_CUSTOM] = true;
	gates[C_TITLE_SCREEN][C_MAP_EDITOR] = true;

	gates[C_CAMPAIGN][C_DEV] = true;
	gates[C_CAMPAIGN][C_TITLE_SCREEN] = true;
	gates[C_CAMPAIGN][C_CUSTOM] = false;
	gates[C_CAMPAIGN][C_MAP_EDITOR] = false;

	gates[C_CUSTOM][C_DEV] = true;
	gates[C_CUSTOM][C_TITLE_SCREEN] = true;
	gates[C_CUSTOM][C_CAMPAIGN] = false;
	gates[C_CUSTOM][C_MAP_EDITOR] = false;

	gates[C_MAP_EDITOR][C_DEV] = true;
	gates[C_MAP_EDITOR][C_TITLE_SCREEN] = true;
	gates[C_MAP_EDITOR][C_CAMPAIGN] = false;
	gates[C_MAP_EDITOR][C_CUSTOM] = false;
}

int		switch_context(t_env *env, unsigned int i)
{
	static bool		first = true;
	static bool		gates[C_MAX][C_MAX] = {};
	// tableau 2d [C_MAX][C_MAX] de psf correspondant a des routines de switch

	if (first)
		open_gates(gates);
	if (i >= C_MAX || !gates[env->context][i])
		return (-1);
	env->context = i;
	// if (routines[env->context][i])
	//	routines[env->context][i](env);
	first = false;
	return (0);
}
