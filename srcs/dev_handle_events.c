/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_handle_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:00:05 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/14 03:25:18 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	move(t_env *env, bool keys[NB_KEYS])
{
	t_vec3d		f;
	t_vec3d		r;

	f = vec_fmult(env->cam.stats.dir, WALK_SPEED);
	r = (t_vec3d){f.z, 0, -f.x, f.w};

	if (keys[KEY_W])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, f);
	if (keys[KEY_S])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, f);
	if (keys[KEY_A])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, r);
	if (keys[KEY_D])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, r);
}

static void	handle_keys(t_env *env, t_events *e)
{
	if (e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D])
		move(env, e->keys);
}

void		dev_handle_events(t_env *env)
{
	t_events	*e;

	e = &env->events;
	handle_keys(env, e);
}
