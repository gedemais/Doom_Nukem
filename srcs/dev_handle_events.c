/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_handle_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:00:05 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/30 17:31:43 by gedemais         ###   ########.fr       */
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
	t_vec3d go;
	t_vec3d *pos_cube;
	t_mesh *m;
	int		i;

	i = 0;
	dir = env->cam.stats.dir;
	pos = env->cam.stats.pos;
	go = (t_vec3d){0,1,0,0};
	(void)keys;
	(void)pos_cube;
	while (i < env->maps[env->scene].meshs.nb_cells)
	{
		m = dyacc(&env->maps[env->scene].meshs, i);		
		if (env->maps[env->scene].stats[i] == false)
		{
	//		if (keys[KEY_E])
	//			translate_mesh(m, go);
	//		else if (keys[KEY_P])
	//		{
	//			pos_cube = &m->corp.pos;
	//		}
		}
		i++;
	}
}

static void	real_move(t_env *env, bool keys[NB_KEYS])
{
	t_vec3d		f;
	t_vec3d		r;

	f = vec_fmult(env->cam.stats.dir, WALK_SPEED);
	r = vec_fdiv((t_vec3d){f.z, 0, -f.x, f.w}, env->cam.stats.aspect_ratio);

	if (keys[KEY_W])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(f, 3.0f));
	if (keys[KEY_S])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(f, 3.0f));
	if (keys[KEY_A])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(r, 3.0f));
	if (keys[KEY_D])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(r, 3.0f));

}

static void	move(t_env *env, bool keys[NB_KEYS])
{
	t_mesh		*cam;
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

	// actualise camera's stats into camera mesh for collisions
	cam = dyacc(&env->maps[env->scene].meshs, env->maps[env->scene].nmesh);
//	cam.corp.pos = ;
	cam->corp.o = vec_sub(env->cam.stats.pos, vec_fdiv(cam->corp.dims, 2.0f));
}

static void	handle_keys(t_env *env, t_events *e)
{
	static int move_i = 0;
	t_vec3d dir;
	t_vec3d pos;

	dir = env->cam.stats.dir;
	pos = env->cam.stats.pos;
//	printf("----------dir---------\n");
//	print_vec(dir);
//	printf("----------pos---------\n");
//	print_vec(pos);
	if ((e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D]) && move_i == 0) 
		move(env, e->keys);
	if ((e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D]) && move_i == 1) 
		real_move(env, e->keys);
	else if (e->keys[KEY_E] || e->keys[KEY_P])
		handle_object(env, e->keys); //try to grab and throw objects ? 
	else if (e->keys[KEY_N])
		move_i = (move_i == 0) ? 1 : 0;
}

void		dev_handle_events(t_env *env)
{
	t_events	*e;

	e = &env->events;
	handle_keys(env, e);
}
