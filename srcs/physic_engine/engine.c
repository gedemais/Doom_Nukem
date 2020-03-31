/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:15:21 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/30 17:36:58 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	phy_gravitax(t_env *env, t_mesh *m, int i)
{
	static  t_vec3d		gravitax;

	gravitax = (t_vec3d){0, env->phy_env.tps * env->phy_env.gravity , 0 ,0};
	//printf("%f\n",gravitax.y);
	if (env->maps[env->scene].stats[i] == false)
	{
		m->corp.v = vec_sub(m->corp.v, gravitax);
//		printf("tps ? %d\n",env->phy_env.tps);
		if (env->phy_env.tps < 900)
			env->phy_env.tps++;
	}
}



static t_vec3d	update_angle(t_env *env, int index)
{
	t_collide	*c;
	t_vec3d		v;
	t_vec3d		v2;
	t_vec3d		norm;
	float		frott;

	frott = 0.95;
	c = dyacc(&env->phy_env.collides, index);
	v = c->a->corp.v;
	norm = c->b->corp.norm;
	v2 = (t_vec3d){v.x, v.y, v.z, 0.0f};
	c->dot = vec_dot(norm, v);
	if (fabs(norm.x) == 1)									//bounce vertical x
		v2 = (t_vec3d){-v.x * frott, v.y, v.z, 0.0f}; 
	else if (fabs(norm.y) == 1)								//bounce vertical y
	{
		v2 = (t_vec3d){v.x * frott, -(v.y) * frott, v.z * frott, 0.0f};
		if ((fabs(v2.y) < 0.3 || vec_norm(v2) > 20) && norm.y == 1)
		{
			env->phy_env.tps = 0;							//stop gravity
			env->maps[env->scene].stats[c->i_a] = true;		//turn to static
			v2 = (t_vec3d){v2.x, 0, 0, 0};					//stop motion
		}
	}
	else if (fabs(norm.z) == 1)
		v2 = (t_vec3d){v.x, v.y, -v.z * frott, 0.0f};
	return (v2);
}
/*
static void	camera_physics(t_env *env, t_collide *c)
{
	t_mesh	*mesh_cam;
	t_mesh	*plan;
	t_vect	*dir;
	t_cam	*cam;


//tester la normal au plan pour savoir quel type de collision et pour bloquer quel mouvement

	cam = c->a;
	plan = c->b;
	env->cam->stats.onfloor = 1;
	env->cam->;
	dir = env->cam->stats.dir;
}

*/
static void	update_speeds(t_env *env)
{
	t_collide			*c;
	int					i;
	int					n_mesh;
	
	n_mesh = env->maps[env->scene].nmesh;
	i = 0;
	while (i < env->phy_env.collides.nb_cells) //if collides but no camera ! 
	{
		c = dyacc(&env->phy_env.collides, i);
		env->maps[env->scene].cam_floor = *c;
		if (c->i_a == (unsigned)n_mesh)
		{	
			if (fabs(c->b->corp.norm.x) == 1 || fabs(c->b->corp.norm.z) == 1)
			{
				env->cam.stats.onfloor = 0;
				env->cam.stats.onplan = 0;
			}
			else
			{
				printf("NORM\n");
				print_vec(c->b->corp.norm);
				if (c->b->corp.norm.y == 1)
				{
					env->cam.stats.onfloor = 1;
					env->cam.stats.onplan = 0;
				}	// save the main collide
				else
				{
					env->cam.stats.onplan = 1;
					env->cam.stats.onfloor = 0; // save the main collide
				}
			}
			// save the next collide here 
//			camera_physics(env, c);
//			print_collide(*c);
		}
		else
			c->a->corp.v = update_angle(env, i); //bounce


	/* try to stop it ... may be after two or three bounce?? 	
		if (((fabs(c->a->corp.v.y) < 0.005 && fabs(c->a->corp.v.x) < 0.005) && norm.y == 1 && c->a->corp.pos.y < 2))
		{
			env->maps[env->scene].stats[c->i_a] = true;
			c->a->corp.v = (t_vec3d){0, 0, 0, 0};
			env->phy_env.tps = 0;
		}
	*/	i++;
	}
	if (i == 0)
	{
		env->cam.stats.onfloor = 0;
		env->cam.stats.onplan = 0;
	}	// save the main collide
}
/*
static void	camera_gravity(t_env *env, t_mesh *m)
{
}
*/
static void	update_positions(t_env *env)
{
	t_events	*e;
	t_mesh		*m;
	int			i;
	
	e = &env->events;
	i = 0;
	while (i < env->maps[env->scene].nmesh + 1)
	{
		m = dyacc(&env->maps[env->scene].meshs, i);		
		if (i == env->maps[env->scene].nmesh)
		{
			//print_mesh_corp(*m);
		}
		else if (env->maps[env->scene].stats[i] == false)
		{
			phy_gravitax(env, m, i);
			translate_mesh(&env->maps[env->scene], m, m->corp.v);
		}
		/* try put object inside the map after stop speeds */	
//		else if (m->corp.vo.x != 0 || m->corp.vo.y != 0|| m->corp.vo.z != 0)
//			off_plan(env, m, i);	
		i++;
	}
}

static void pause_position(t_env *env)
{
	t_mesh		*m;		
	int			i;

	i = 0;
	while (i < env->maps[env->scene].meshs.nb_cells)
	{
		m = dyacc(&env->maps[env->scene].meshs, i);		
		if (env->maps[env->scene].stats[i] == false)
		{
			if (nonzero_vector(m->corp.v))
				vec3d_swap(&m->corp.v, &m->corp.v_cpy); // cancel v and save in vec_cpy
			else
			{
				vec3d_swap(&m->corp.v_cpy, &m->corp.v); // swap in v and cancel the vec_cpy
				m->corp.v_cpy = zero_vector();
			}	
			if (env->phy_env.gravity != 0)
				env->phy_env.gravity = 0;
			else
				env->phy_env.gravity = 0.0000981;
		}
		i++;
	}	
}

static void	color_collides(t_env *env)
{
	t_collide	*m;
	t_mesh		*mesh;
	t_triangle	*t;

	for (int i = 0; i < env->maps[env->scene].nmesh; i++)
	{
		mesh = dyacc(&env->maps[env->scene].meshs, i);
		for (int j = 0; j < mesh->tris.nb_cells; j++)
		{
			t = dyacc(&mesh->tris, j);
			t->color = 0xffffff;
		}
	}

	for (int i = 0; i < env->phy_env.collides.nb_cells; i++)
	{
		m = dyacc(&env->phy_env.collides, i);
		for (int j = 0; j < m->a->tris.nb_cells; j++)
		{
			t = dyacc(&m->a->tris, j);
			t->color = 0xff0000;
		}
		for (int j = 0; j < m->b->tris.nb_cells; j++)
		{
			t = dyacc(&m->b->tris, j);
			t->color = 0xff0000;
		}
	}
}
int		physic_engine(t_env *env)
{
	t_events	*e;

	e = &env->events;
	ft_memset(env->maps[env->scene].colls, 0, env->maps[env->scene].nmesh);
	report_collisions(env);
	color_collides(env);
	update_speeds(env);
	update_positions(env);
	if (e->keys[KEY_P])
		pause_position(env);
//	stop_speed(env);
	clear_dynarray(&env->phy_env.collides);
	return (0);
}
