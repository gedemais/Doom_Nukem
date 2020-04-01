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
	while (cam_vec->y - c.b->corp.pos.y < 0.1)
		cam_vec->y += 0.1;

}
// idee : save dans une structure la collide de la camera avec le sol du moment 

static t_vec3d	set_y_dir(t_env *env,  bool keys[NB_KEYS])
{
	t_vec3d f;
	t_cam_stats cam_stats;

	cam_stats = env->cam.stats;
	f = vec_fmult(env->cam.stats.dir, WALK_SPEED);
	if (cam_stats.onfloor == 1 || cam_stats.onplan == 1 || keys[KEY_E])
	{
		if (keys[KEY_E])
			f.y = 0.1;
		else if (cam_stats.onfloor == 1)
			f.y = 0;
		else if (cam_stats.onplan == 1)
			f = fps_move_print(&env->maps[env->scene].cam_floor, env->cam.stats.dir);
	}
	//	else if (cam_stats.onwall == 1)
		//fct
		
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
	
	env->cam.stats.pos = vec_add(env->cam.stats.pos, f);
	cam->corp.o = vec_sub(env->cam.stats.pos, vec_fdiv(cam->corp.dims, 2.0f));
	cam->corp.v = f;

}



static void	handle_keys(t_env *env, t_events *e)
{
	static int move_i = 1;
	t_vec3d dir;
	t_vec3d pos;

	dir = env->cam.stats.dir;
	pos = env->cam.stats.pos;
	if ((e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D]) || e->keys[KEY_E]) 
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
