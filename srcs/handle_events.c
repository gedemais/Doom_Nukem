/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:00:05 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/06 17:35:23 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool		*mouse_freedom(void)
{
	static bool		freedom = true;

	return (&freedom);
}

void		handle_events(t_env *env)
{
	t_events	*e;

	e = &env->events;
	if (!*mouse_freedom())
		mlx_mouse_move(env->mlx.mlx_win, WDT / 2, HGT / 2);
}
