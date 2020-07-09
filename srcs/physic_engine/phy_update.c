/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phy_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <bebosson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:44:16 by bebosson          #+#    #+#             */
/*   Updated: 2020/06/30 17:15:33 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/*
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
*/

void	print_info_phy(t_env *env, t_mesh *cam, t_map *maps)
{
	printf("-----------------PRINT_INFO---------------------\n");
	printf("floor %d \n", env->cam.stats.onfloor);
	printf("wall %d \n", env->cam.stats.onwall);
	printf("roof %d \n", env->cam.stats.onroof);
	printf("sum %d \n", return_test_collide(env));
	printf("------------------------------------------------\n");
	printf("cam->corp.pos\n");
	print_vec(cam->corp.pos);
	printf("cam->corp.v\n");
	print_vec(cam->corp.v);
	printf("-----------------------------------------------\n");
	printf("env->cam.stats.pos\n");
	print_vec(env->cam.stats.pos);
	printf("-------------------COLIDE WALL-------------------------\n");
	if (env->cam.stats.onwall == 1)
		print_collide(*maps->cam_wall);
	printf("-------------------COLIDE FLOOR-------------------------\n");
	if (env->cam.stats.onfloor == 1)
		print_collide(*maps->cam_floor);
	printf("-------------------COLIDE ROOF-------------------------\n");
	if (env->cam.stats.onroof == 1)
		print_collide(*maps->cam_roof);

}

t_vec3d		update_angle(t_env *env, int index)
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
		if ((fabs(v2.y) < 0 || vec_norm(v2) > 20) && norm.y == 1)
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



void	update_speeds_collide(t_env *env)
{
	t_collide			*c;
	int					i;
	int					n_mesh;
	
	n_mesh = env->maps[env->scene].nmesh;
	i = 0;
	while (i < env->phy_env.collides.nb_cells) //if collides but no camera ! 
	{
		c = dyacc(&env->phy_env.collides,i);
		c->a->corp.v = update_angle(env, i);
		i++;
	}
}
/*
static	void	actual_collide(t_map *map)
{
	

}
*/
void	update_speeds_collide_cam(t_env *env, t_mesh *cam, t_map *map) // refactor
{
	t_collide			*c;
	int					i;
	int					j;
	
	i = 0;
	j = 0;
	while (i < env->phy_env.collides_cam.nb_cells) //if collides but no camera ! 
	{
		c = dyacc(&env->phy_env.collides_cam, i);
		type_of_plan(env, c, map);
//		print_collide(*c);
		i++;
	}
	if ((env->cam.stats.onwall == 0 && env->cam.stats.onfloor == 0) || (i == 0))
	{
		env->cam.stats.onfloor = 0;	
		phy_gravitax_cam(env, cam, &env->cam.stats);
	}
}

void	update_positions_gravity(t_env *env)
{
	t_events	*e;
	t_mesh		*m;
	int			i;
	
	e = &env->events;
	i = 0;
	while (i < env->maps[env->scene].nmesh)
	{
		m = dyacc(&env->maps[env->scene].meshs, i);		
		if (env->maps[env->scene].stats[i] == false)
		{
			phy_gravitax(env, m, i);
			translate_mesh(&env->maps[env->scene], m, m->corp.v);
		}
		i++;
	}
}
/*
void	ft_inertie(t_env *env, t_map map, t_vec3d v)
{
	static t_vec3d	v = (t_vec3d){-INFINITY, 0, 0, 0};

	printf("corp speed : ");
	print_vec(cam->corp.v);
	printf("speed : ");
	print_vec(v);


	if (key_move(env->events.keys))
	{
		v = cam->corp.v;
		translate_mesh(map, cam, cam->corp.v);
	}
	else if (vec_norm(v) > 0)
	{
		if (fabs(v.x) > INERTIE)
			v.x = (v.x > 0) ? v.x - INERTIE : v.x + INERTIE;
		else
			v = zero_vector();
		if (fabs(v.y) > INERTIE)
			v.y = (v.y > 0) ? v.y - INERTIE : v.y + INERTIE;
		else
			v = zero_vector();
		if (fabs(v.z) > INERTIE)
			v.z = (v.z > 0) ? v.z - INERTIE : v.z + INERTIE;
		else
			v = zero_vector();
	}
}
*/


void	update_positions_cam(t_env *env, t_map *map, t_mesh *cam)
{
//	print_info_phy(env, cam);
	// add f and r to v here ?
//	cam->corp.v = vec_add(*env->phy_env.f, cam->corp.v);
//	cam->corp.v 

	translate_mesh(map, cam, cam->corp.v);	
	env->cam.stats.pos = vec_add(env->cam.stats.pos, cam->corp.v);
	cam->corp.o = vec_sub(env->cam.stats.pos, vec_fdiv(cam->corp.dims, 1.0f * env->cam.stats.crouch));
	
}
