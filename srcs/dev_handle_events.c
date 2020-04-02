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


static t_vec3d *coefdir_plan(t_mesh *m, t_vec3d *dir)
{
	t_triangle *tri;
	t_vec3d v;
	t_vec3d w;
	t_vec3d	p;
	t_vec3d	*new_dir;

	new_dir = dir;
	printf("------------coeff_dir---------\n");
	tri = dyacc(&m->tris, 0);
	v = tri->points[0];
	w = tri->points[1];
	p.x = v.y * w.z - (w.y * v.z);
	p.y = v.z * w.x - (w.z * v.x);
	p.z = v.x * w.y - (v.y * w.x);
	new_dir->y = -(p.x * new_dir->x + p.z * new_dir->z) / p.y;
	if (new_dir->y < 0.2 && new_dir->y > 0)
		new_dir->y = 0.2;
	return (new_dir);
}

static t_vec3d		fps_move_print(t_collide *c, t_vec3d dir)
{
	t_mesh *b;
	t_vec3d f;	

	b = c->b;
	f = vec_fmult(*coefdir_plan(b, &dir), WALK_SPEED);
	return (f);
}

void	test_distance_camplan(t_collide c, t_vec3d *cam_vec)
{
	int y_cam;
	int y_plan;
	float diff;

	y_cam = cam_vec->y;
//	printf("pos cam\n");
	print_vec(*cam_vec);
	y_plan = c.b->corp.pos.y;
//	printf("pos plan\n");
	print_vec(c.b->corp.pos);
	diff = cam_vec->y - c.b->corp.pos.y;
//	printf("diff %f\n",diff);
	while (cam_vec->y - c.b->corp.pos.y < 1)
		cam_vec->y += 1;

}
// idee : save dans une structure la collide de la camera avec le sol du moment 
static int simple_test_floor(t_env *env)
{
	t_cam_stats cam_stats;

	cam_stats = env->cam.stats;
	if (cam_stats.onfloor == 1 || cam_stats.onplan == 1)
		return (1);
	else
		return (0);
}

static t_vec3d	set_y_dir(t_env *env,  bool keys[NB_KEYS])
{
	t_vec3d f;
	t_cam_stats cam_stats;


	cam_stats = env->cam.stats;
	f = vec_fmult(env->cam.stats.dir, WALK_SPEED);
	if (cam_stats.onfloor == 1 || cam_stats.onplan == 1 || keys[KEY_E])
	{
		if (keys[KEY_E] && (simple_test_floor(env) == 1))
			f.y = 0.1;
		else if (cam_stats.onfloor == 1)
			f.y = 0;
		else if (cam_stats.onplan == 1)
			f = fps_move_print(&env->maps[env->scene].cam_floor, env->cam.stats.dir);
	}
	return (f);

}


static t_vec3d test_dist_wall(t_env *env, t_collide *c, t_vec3d f)
{
	t_mesh *cam;
	t_mesh wall;
	t_vec3d pos_cam;
	t_vec3d v_cam;
	t_vec3d pos_wall;
	t_vec3d norm_wall;

	(void)env;
	cam = c->a;
	wall = *(c->b);
	pos_cam = cam->corp.pos;
	pos_wall = wall.corp.pos;
	v_cam = wall.corp.v;
	norm_wall = wall.corp.norm;
	printf("pos_cam = ");
	print_vec(pos_cam);
	printf("pos_wall = ");
	print_vec(pos_wall);
	printf("pos_cam = ");
	print_vec(pos_cam);
	printf("norm_wall");
	print_vec(norm_wall);
	printf("speed = ");
	print_vec(f);
	if (vec_dot(f, norm_wall) < 0)
		return (zero_vector());
	else
		return (f);
}

static void	move(t_env *env, bool keys[NB_KEYS])
{
	t_mesh		*cam;
	t_vec3d		f;
	t_vec3d		r;
	int			i;

//	f = fps_move_print(&env->maps[env->scene].cam_floor, env->cam.stats.dir);
	/*	MOVE ?		*/
	i = 0;
	cam = dyacc(&env->maps[env->scene].meshs, env->maps[env->scene].nmesh);
	f = set_y_dir(env, keys);
	print_vec(f);
	r = vec_fdiv((t_vec3d){f.z, 0, -f.x, f.w}, env->cam.stats.aspect_ratio);
	if (keys[KEY_W])
		f = vec_add(f, vec_fmult(f, 3.0f));
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

static int key_move(bool keys[NB_KEYS])
{
	if ((keys[KEY_W] || keys[KEY_S] || keys[KEY_A] || keys[KEY_D]) || keys[KEY_E]) 
		return (1);
	else
		return (0);

}

static void	handle_keys(t_env *env, t_events *e)
{
	static int move_i = 1;
	t_vec3d dir;
	t_vec3d pos;

	dir = env->cam.stats.dir;
	pos = env->cam.stats.pos;
	if (key_move(e->keys) && simple_test_floor(env)) 
		move(env, e->keys);
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
