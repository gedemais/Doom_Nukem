/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_handle_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:00:05 by gedemais          #+#    #+#             */
/*   Updated: 2020/01/16 20:03:18 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	move(t_env *env, bool keys[NB_KEYS])
{
	t_vec3d		f;
	t_vec3d		r;

	f = vec_fmult(env->cam.dir, WALK_SPEED);
	r = vec_fmult((t_vec3d){f.z, 0, -f.x, f.w}, WALK_SPEED);
	vec_normalize(&f);
	vec_normalize(&r);

	if (keys[KEY_W])
		env->cam.pos = vec_add(env->cam.pos, f);
	if (keys[KEY_S])
		env->cam.pos = vec_sub(env->cam.pos, f);
	if (keys[KEY_A])
		env->cam.pos = vec_add(env->cam.pos, r);
	if (keys[KEY_D])
		env->cam.pos = vec_sub(env->cam.pos, r);
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
