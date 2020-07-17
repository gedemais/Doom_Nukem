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

static void	step_sound(t_env *env)
{
	static int	delay = 0;
	t_vec3d		pos;

	if (delay-- == 0)
	{
		pos = env->cam.stats.pos;
		pos.y -= 2;
		if (move_keys(env))
			sound_system(env, SA_STEP,
				sp_play(env->sound.volume / 1.8f, PITCH, pos));
		delay = env->events.keys[KEY_SHIFT_LEFT] ? 5 : 10;
	}
	if (env->events.keys[KEY_SPACE])
		sound_system(env, SA_STEP, sp_stop());
}

static void	movements(t_env *env, float speeds[2], int *frame)
{
	if (env->events.keys[KEY_SPACE])
		return ;
	if  (*frame > 0)
	{
		env->player.current->w_map->spawn.y -= speeds[0];
		(*frame)--;
	}
	else if (*frame > -speeds[1])
	{
		env->player.current->w_map->spawn.y += speeds[0];
		(*frame)--;
	}
	if (*frame == -speeds[1])
		*frame = speeds[1];
}

void		handle_sprint(t_env *env)
{
	static t_vec3d	reset;
	static int		frame = 0;
	static bool		on = false;
	static bool		first = true;
	float			speeds[2];

	step_sound(env);
	if (!do_sprint(env))
		return ;
	speeds[0] = env->events.keys[KEY_SHIFT_LEFT] ? 0.002f : 0.001f; 
	speeds[1] = env->events.keys[KEY_SHIFT_LEFT] ? W_SHAKE / 2 : W_SHAKE;
	if (first && !(first = false))
		reset = env->player.current->w_map->spawn;
	on = (!on && move_keys(env));
	if (on)
		movements(env, speeds, &frame);
	if (on && !move_keys(env))
	{
		on = false;
		frame = env->events.keys[KEY_SHIFT_LEFT] ? -speeds[1] : speeds[1];
		env->player.current->w_map->spawn = reset;
		sound_system(env, SA_STEP, sp_stop());
	}
}
