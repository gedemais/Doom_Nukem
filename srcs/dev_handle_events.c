/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_handle_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:00:05 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/23 14:15:28 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_vec3d project_ortho(t_vec3d u, t_vec3d y) //projection orthogonal sur un vecteur //7
{
	t_vec3d y_proj;

	y_proj = vec_fmult(u, (vec_dot(y, u) / vec_dot(u, u)));
	return (y_proj);
}

// only define the direction of the slope
static t_vec3d *coefdir_plan(t_mesh *m, t_vec3d *dir) //6
{
	t_triangle *tri;
	t_vec3d v;
	t_vec3d w;
	t_vec3d u;
	t_vec3d x;
	t_vec3d y;
	t_vec3d z;
	t_vec3d	*new_dir;
	t_vec3d step_dir;
	
	tri = dyacc(&m->tris, 0);
	x = tri->points[0];
	y = tri->points[1];
	z = tri->points[2];
	/* creation vecteurs pentes */
	u = vec_sub(x, y);
	print_vec(u);
	v = vec_sub(x, z);
	print_vec(v);
	w = vec_sub(y, z);
	print_vec(w);
	tri = dyacc(&m->tris, 1);
	x = tri->points[0];
	y = tri->points[1];
	z = tri->points[2];
	/* dot product*/
//	printf("dot(u,v) = %f\n", vec_dot(u, v));
//	printf("dot(v,w) = %f\n", vec_dot(v, w));
//	printf("dot(u,w) = %f\n", vec_dot(u, w));
	new_dir = dir;
	step_dir = project_ortho(w, *dir);
	new_dir->y = step_dir.y;
//	printf("step_dir = \n");
//	print_vec(step_dir);
	
	return (new_dir);
}

static t_vec3d		fps_move_print(t_collide *c, t_vec3d dir) //5
{
	t_mesh *b;
	t_vec3d f;	

	b = c->a;
	f = vec_fmult(*coefdir_plan(b, &dir), WALK_SPEED); 
	return (f);
}

void	test_distance_camplan(t_collide c, t_vec3d *cam_vec) //8
{
	float diff;

	diff = cam_vec->y - c.a->corp.dims.y;
	printf("diff = %f \n", diff);
//	if (diff < 0.3 && diff > 0)
//		cam_vec->y += 0.1;

}

static int simple_test_floor(t_env *env) //4 (a supprimer)
{
	t_cam_stats cam_stats;

	cam_stats = env->cam.stats;
//	printf("cam_stats_onfloor = %d\n", cam_stats.onfloor);
//	printf("cam_stats_onplan = %d\n", cam_stats.onplan);
	if (cam_stats.onfloor == 1 || cam_stats.onplan == 1)
		return (1);
	else
		return (0);
}

static t_vec3d	set_y_dir(t_env *env,  bool keys[NB_KEYS]) //3
{
	t_vec3d f;
	t_cam_stats cam_stats;

	cam_stats = env->cam.stats;
	f = vec_fmult(cam_stats.dir, WALK_SPEED);
	if (keys[KEY_E])
		f.y = 0.1;
	else
		f = fps_move_print(&env->maps[env->scene].cam_floor, env->cam.stats.dir);
	return (f);

}


static t_vec3d test_dist_wall(t_env *env, t_collide *c, t_vec3d f)
{
	t_mesh *cam;
	t_mesh wall;
	t_vec3d norm_wall;

	(void)env;
	cam = c->b;
	wall = *(c->a);
	norm_wall = wall.corp.norm;
	if (vec_dot(f, norm_wall) < 0 && c->i_a != 0)
		return (zero_vector());
	else
		return (f);
}

static void	move(t_env *env, bool keys[NB_KEYS]) //2
{
	t_mesh		*cam;
	t_vec3d		f;
	t_vec3d		r;
	int			i;

	i = 0;
	cam = &env->maps[env->scene].cam;
	f = set_y_dir(env, keys);
	r = vec_fdiv((t_vec3d){f.z, 0, -f.x, 0}, env->cam.stats.aspect_ratio);
	if (keys[KEY_W] || keys[KEY_E])
	{
		f = vec_add(f, vec_fmult(f, 3.0f));
		if (keys[KEY_E] && !keys[KEY_W])
		{
			f.x = 0;
			f.z = 0;
		}
	}
	if (keys[KEY_S])
		f = vec_add(f, vec_fmult(f, -3.0f));
	if (keys[KEY_A])
		f = vec_add(f, vec_fmult(r, 3.0f));
	if (keys[KEY_D])
		f = vec_add(f, vec_fmult(r, -3.0f));
	if (env->cam.stats.onwall == 1)
		f =	test_dist_wall(env, &env->maps[env->scene].cam_wall, f);
	
	env->cam.stats.pos = vec_add(env->cam.stats.pos, f);
	cam->corp.o = vec_sub(env->cam.stats.pos, vec_fdiv(cam->corp.dims, 2.0f));
	cam->corp.v = f;
}

static int key_move(bool keys[NB_KEYS]) //1
{
	if ((keys[KEY_W] || keys[KEY_S] || keys[KEY_A] || keys[KEY_D]) || keys[KEY_E]) 
		return (1);
	else
		return (0);

}

static void	fake_move(t_env *env, bool keys[NB_KEYS])
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



static void	handle_keys(t_env *env, t_events *e)
{
	static int move_i = 1;
	t_vec3d dir;
	t_vec3d pos;
	t_mesh		*cam;
	t_cam_stats cam_stats;

	cam_stats = env->cam.stats;
	cam = &env->maps[env->scene].cam;
	dir = env->cam.stats.dir;
	pos = env->cam.stats.pos;
	print_vec(cam->corp.dims);
	if (key_move(e->keys)  &&  move_i == 1)
		move(env, e->keys);
	else if (move_i == 0)
		fake_move(env, e->keys);
		move_i = (move_i == 0) ? 1 : 0;
		printf("----------dir---------\n");
		print_vec(dir);
		printf("----------pos---------\n");
		print_vec(pos);
}

void		dev_handle_events(t_env *env)
{
	t_events *e;
	
	e = &env->events;
	handle_keys(env, e);
}
