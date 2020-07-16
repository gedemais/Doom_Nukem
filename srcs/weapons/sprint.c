/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:46:53 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/16 21:10:37 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	do_sprint(t_env *env)
{
	if (env->player.current->reloading > 0
		|| env->player.current->shooting > 0)
		return (false);
	return (true);
}

static bool	move_keys(t_env *env)
{
	return ((env->events.keys[KEY_W]
		|| env->events.keys[KEY_A]
		|| env->events.keys[KEY_S]
		|| env->events.keys[KEY_D]));
}

void		handle_sprint(t_env *env)
{
	static t_vec3d	reset;
	static int		frame = 0;
	static bool		on = false;
	static bool		first = true;
	float			speeds[2];

	if (!do_sprint(env))
		return ;
	speeds[0] = env->events.keys[KEY_SHIFT_LEFT] ? 0.03f : 0.01f; 
	speeds[1] = env->events.keys[KEY_SHIFT_LEFT] ? W_SHAKE / 2 : W_SHAKE;
	if (first && !(first = false))
		reset = env->player.current->w_map->spawn;
	on = (!on && move_keys(env));
	if (on)
	{
		if  (frame > 0)
		{
			env->player.current->w_map->spawn.y -= speeds[0];
			frame--;
		}
		else if (frame > -speeds[1])
		{
			env->player.current->w_map->spawn.y += speeds[0];
			frame--;
		}
		if (frame == -speeds[1])
			frame = speeds[1];

	}
	if (on && !move_keys(env))
	{
		on = false;
		frame = env->events.keys[KEY_SHIFT_LEFT] ? -speeds[1] : speeds[1];
		env->player.current->w_map->spawn = reset;
	}
}
