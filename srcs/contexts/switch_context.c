/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_context.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 01:24:57 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/17 04:45:49 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	open_gates(bool gates[C_MAX][C_MAX])
{
	gates[C_DEV][C_TITLE_SCREEN] = true;
	gates[C_DEV][C_CAMPAIGN] = true;
	gates[C_DEV][C_SURVIVE] = true;
	gates[C_DEV][C_MAP_EDITOR] = true;

	gates[C_TITLE_SCREEN][C_DEV] = true;
	gates[C_TITLE_SCREEN][C_CAMPAIGN] = true;
	gates[C_TITLE_SCREEN][C_SURVIVE] = true;
	gates[C_TITLE_SCREEN][C_MAP_EDITOR] = true;

	gates[C_CAMPAIGN][C_DEV] = true;
	gates[C_CAMPAIGN][C_TITLE_SCREEN] = true;
	gates[C_CAMPAIGN][C_SURVIVE] = false;
	gates[C_CAMPAIGN][C_MAP_EDITOR] = false;

	gates[C_SURVIVE][C_DEV] = true;
	gates[C_SURVIVE][C_TITLE_SCREEN] = true;
	gates[C_SURVIVE][C_CAMPAIGN] = false;
	gates[C_SURVIVE][C_MAP_EDITOR] = false;

	gates[C_MAP_EDITOR][C_DEV] = true;
	gates[C_MAP_EDITOR][C_TITLE_SCREEN] = true;
	gates[C_MAP_EDITOR][C_CAMPAIGN] = false;
	gates[C_MAP_EDITOR][C_SURVIVE] = false;
}

void	init_routines(void (*routines[C_MAX][C_MAX])(t_env*))
{
/*	routines[C_DEV][C_TITLE_SCREEN] = true;
	routines[C_DEV][C_CAMPAIGN] = true;
	routines[C_DEV][C_SURVIVE] = true;
	routines[C_DEV][C_MAP_EDITOR] = true;*/

	routines[C_TITLE_SCREEN][C_DEV] = &ts_to_dev;
	routines[C_TITLE_SCREEN][C_CAMPAIGN] = ts_to_campaign;
	routines[C_TITLE_SCREEN][C_SURVIVE] = ts_to_custom;
	routines[C_TITLE_SCREEN][C_MAP_EDITOR] = ts_to_map_editor;

	routines[C_CAMPAIGN][C_DEV] = NULL;
	routines[C_CAMPAIGN][C_TITLE_SCREEN] = campaign_to_ts;
	routines[C_CAMPAIGN][C_SURVIVE] = NULL;
	routines[C_CAMPAIGN][C_MAP_EDITOR] = NULL;

	routines[C_SURVIVE][C_DEV] = NULL;
	routines[C_SURVIVE][C_TITLE_SCREEN] = custom_to_ts;
	routines[C_SURVIVE][C_CAMPAIGN] = NULL;
	routines[C_SURVIVE][C_MAP_EDITOR] = NULL;

	routines[C_MAP_EDITOR][C_DEV] = NULL;
	routines[C_MAP_EDITOR][C_TITLE_SCREEN] = map_editor_to_ts;
	routines[C_MAP_EDITOR][C_CAMPAIGN] = NULL;
	routines[C_MAP_EDITOR][C_SURVIVE] = NULL;
}

int		switch_context(t_env *env, unsigned int i)
{
	static bool		first = true;
	static bool		gates[C_MAX][C_MAX] = {};
	static void		(*routines[C_MAX][C_MAX])(t_env*) = {};

	if (first)
	{
		open_gates(gates);
		init_routines(routines);
	}
	if (i >= C_MAX || !gates[env->context][i])
	{
		ft_putstr_fd(ICS_ERR, 2);
		return (-1);
	}
	if (routines[env->context][i])
		routines[env->context][i](env);
	env->context = i;
	first = false;
	return (0);
}
