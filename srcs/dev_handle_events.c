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

static float	print_points_face(t_triangle *tri, t_cam_stats cam_stat)
{
	unsigned int i;
	float y_min;
	t_vec3d diff;
	
	i = -1;
	y_min = 0;
	while (++i < 3)
	{
		diff = vec_sub(cam_stat.pos, tri->points[i]);
		y_min = (i == 0) ? diff.y : fmin(diff.y, y_min);
	}
	printf("y_min = %f\n", y_min);
	return (y_min);
}

static void	print_vect_face(t_triangle *tri, t_cam_stats cam_stat)
{
	t_vec3d u;
	t_vec3d v;
	t_vec3d w;
	
	print_points_face(tri, cam_stat);
	u = vec_sub(tri->points[0], tri->points[1]);
//	print_vec(u);
	v = vec_sub(tri->points[1], tri->points[2]);
//	print_vec(v);
	w = vec_sub(tri->points[2], tri->points[0]);
//	print_vec(w);

}

static t_vec3d	browse_vect_plan(t_mesh *m, t_cam_stats cam_stat)
{
	unsigned int i;

	i = -1;
	printf("nb_triangle %d \n",m->tris.nb_cells);
	while (++i < m->tris.nb_cells)
	{
		printf("triangle num %d \n",i);
		print_vect_face(dyacc(&m->tris, i), cam_stat);	
	}
}

// only define the direction of the slope
static t_vec3d *coefdir_plan(t_mesh *m, t_vec3d *dir, t_cam_stats cam_stats) //6
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
	
	browse_vect_plan(m, cam_stats);
	tri = dyacc(&m->tris, 0);
	x = tri->points[0];
	y = tri->points[1];
	z = tri->points[2];
	/* creation vecteurs pentes */
	u = vec_sub(x, y);
//	print_vec(u);
	v = vec_sub(x, z);
//	print_vec(v);
	w = vec_sub(y, z);
//	print_vec(w);
	/* dot product*/
//	printf("dot(u,v) = %f\n", vec_dot(u, v));
//	printf("dot(v,w) = %f\n", vec_dot(v, w));
//	printf("dot(u,w) = %f\n", vec_dot(u, w));
	new_dir = dir;
	step_dir = project_ortho(w, *dir);
	printf("dot = %f\n",vec_dot(step_dir , w));	
	new_dir->y = step_dir.y;
	// print norm triangle 
//	printf("step_dir = \n");
//	print_vec(step_dir);
	
	return (new_dir);
}

static t_vec3d		fps_move_print(t_collide *c, t_vec3d dir, t_cam_stats cam_stats) //5
{
	t_mesh *b;
	t_vec3d f;	

	b = c->a;
	f = vec_fmult(*coefdir_plan(b, &dir, cam_stats), WALK_SPEED); 
	return (f);
}

void	test_distance_camplan(t_collide c, t_vec3d *cam_vec) //8 // fonction hyper importante a refaire 
{
	float diff;

	diff = cam_vec->y - c.a->corp.pos.y;
	printf("diff = %f \n", diff);
	if (diff < 0.3 && diff > 0)
		cam_vec->y += 0.1;

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
		f = fps_move_print(&env->maps[env->scene].cam_floor, env->cam.stats.dir, cam_stats);
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
			f = (t_vec3d){0 , f.y, 0, f.w};
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
