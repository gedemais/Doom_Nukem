/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_handle_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:00:05 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/11 17:21:50 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/*
static void	try_math_cube(t_vec3d dir, t_vec3d pos, t_vec3d pos_cube)
{
	int dx;
	int dy; 
	int dz;

	dx = 1;
	dy = 1;
	dz = 1;
	

}
*/
static void	handle_object(t_env *env, bool keys[NB_KEYS])
{
	t_vec3d dir;
	t_vec3d pos;
	t_vec3d pos_cube;
	t_mesh *m;
	int		i;

	i = 0;
	dir = env->cam.stats.dir;
	pos = env->cam.stats.pos;
	while (i < env->maps[env->scene].meshs.nb_cells)
	{
		m = dyacc(&env->maps[env->scene].meshs, i);		
		if (env->maps[env->scene].stats_cpy[i] == false && keys[KEY_E])
		{
			pos_cube = m->corp.pos;
			printf("dir %f %f %f\n", dir.x, dir.y, dir.z);
			printf("pos %f %f %f\n", pos.x, pos.y, pos.z);
			printf("pos_cube %f %f %f\n", pos_cube.x, pos_cube.y, pos_cube.z);

		}
		i++;
	}
}

static void	move(t_env *env, bool keys[NB_KEYS])
{
	t_vec3d		f;
	t_vec3d		r;

	f = vec_fmult(env->cam.stats.dir, WALK_SPEED);
	r = vec_fmult((t_vec3d){f.z, 0, -f.x, f.w}, 0.5f);

	if (keys[KEY_W])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(f, 3.0f));
	if (keys[KEY_S])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(f, 3.0f));
	if (keys[KEY_A])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(r, 3.0f));
	if (keys[KEY_D])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(r, 3.0f));
}

static void	handle_keys(t_env *env, t_events *e)
{
	if (e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D])
		move(env, e->keys);
	else if (e->keys[KEY_E])
	{
		handle_object(env, e->keys);
		printf("toto %d\n", KEY_E);
	}
		
}

void		dev_handle_events(t_env *env)
{
	t_events	*e;

	e = &env->events;
	handle_keys(env, e);
}
