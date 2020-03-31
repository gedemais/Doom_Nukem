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
static t_vec3d *coefdir_plan(t_mesh *m, t_vec3d *dir)
{
	t_triangle *tri;
	t_vec3d v;
	t_vec3d w;
	t_vec3d	p;
	t_vec3d	*new_dir;


	new_dir = dir;
	tri = dyacc(&m->tris, 0);
	v = tri->points[0];
	w = tri->points[1];
	p.x = v.y * w.z - (w.y * v.z);
	p.y = v.z * w.x - (w.z * v.x);
	p.z = v.x * w.y - (v.y * w.x);
	new_dir->y = -(p.x * new_dir->x + p.z * new_dir->z) / p.y;
	return (new_dir);
}

static t_vec3d		fps_move_print(t_collide *c, t_vec3d dir)
{
	t_mesh *b;
	b = c->b;
	t_vec3d f;	

	f = vec_fmult(*coefdir_plan(b, &dir), WALK_SPEED);
	return (f);
//	printf("print f\n");
//print triangle de la mesh du plan pour trouver l'equation de plan 
//pour pouvoir orienter la direction ou le y de la camera 
	//	i = -1;
//	while (++i < 3)
//		print_vec(b->triangle[i]);	
//	return (r);
}


// idee : save dans une structure la collide de la camera avec le sol du moment 

static void	fps_move(t_env *env, bool keys[NB_KEYS], int on_plan)
{
	t_mesh		*cam;
	t_vec3d		f;
	t_vec3d		r;

	f = fps_move_print(&env->maps[env->scene].cam_floor, env->cam.stats.dir);
	if (on_plan == 0)
	{
		f = vec_fmult(env->cam.stats.dir, WALK_SPEED);
		f.y = 0;
	}
	else
		f = fps_move_print(&env->maps[env->scene].cam_floor, env->cam.stats.dir);
	print_vec(f);
	r = vec_fdiv((t_vec3d){f.z, 0, -f.x, f.w}, env->cam.stats.aspect_ratio);
	

	if (keys[KEY_W])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(f, 3.0f));
	if (keys[KEY_S])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(f, 3.0f));
	if (keys[KEY_A])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(r, 3.0f));
	if (keys[KEY_D])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(r, 3.0f));
	
	cam = dyacc(&env->maps[env->scene].meshs, env->maps[env->scene].nmesh);
	cam->corp.o = vec_sub(env->cam.stats.pos, vec_fdiv(cam->corp.dims, 2.0f));

}

static void	move(t_env *env, bool keys[NB_KEYS])
{
	t_mesh		*cam;
	t_vec3d		f;
	t_vec3d		r;

	f = vec_fmult(env->cam.stats.dir, WALK_SPEED);
//	printf("\nf");
//	print_vec(f);
	r = vec_fmult((t_vec3d){f.z, 0, -f.x, f.w}, 0.5f);
//	printf("\nr");
//	print_vec(r);
	
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
	int on_floor;
	int on_plan;
	t_vec3d dir;
	t_vec3d pos;

	dir = env->cam.stats.dir;
	pos = env->cam.stats.pos;
	on_floor = env->cam.stats.onfloor;
	on_plan = env->cam.stats.onplan;
//	printf("move_i = %d\n",move_i);
	printf("on_floor = %d\n",on_floor);
	printf("on_plan = %d\n",on_plan);
	if ((e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D])) 
	{
		if (move_i == 0)
			move(env, e->keys);
		else if (on_floor == 1 || on_plan == 1)
			fps_move(env, e->keys, on_plan);
//		else if (on_floor == 1 && on_plan == 1)

	}
	else if (e->keys[KEY_E] || e->keys[KEY_P])
		handle_object(env, e->keys); //try to grab and throw objects ? 
	else if (e->keys[KEY_N])
		move_i = (move_i == 0) ? 1 : 0;
	else if (e->keys[KEY_T])
	{
		printf("----------dir---------\n");
		print_vec(dir);
		printf("----------pos---------\n");
		print_vec(pos);
	}
}

void		dev_handle_events(t_env *env)
{
	t_events	*e;

	e = &env->events;
	handle_keys(env, e);
}
