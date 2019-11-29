/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:00:05 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/29 06:20:09 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool		*mouse_freedom(void)
{
	static bool		freedom = true;

	return (&freedom);
}

static void	handle_keys(t_env *env, t_events *e)
{
	(void)e;
	(void)env;
}

static void	handle_mouse(t_env *env, t_events *e)
{
	(void)e;
	(void)env;
}

void		handle_events(t_env *env)
{
	t_events	*e;

	e = &env->events;
	if (!*mouse_freedom())
		mlx_mouse_move(env->mlx.mlx_win, env->mlx.half_wdt, env->mlx.half_hgt);
	handle_keys(env, e);
	handle_mouse(env, e);
}
