/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:15:21 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/10 15:02:45 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	phy_gravitax(t_env *env, t_mesh *m, int i)
{
	static  t_vec3d		gravitax;

	gravitax = (t_vec3d){0, env->phy_env.gravity * env->phy_env.tps , 0 ,0};
	if (env->maps[env->scene].stats[i] == false)
	{
		m->corp.v = vec_sub(m->corp.v, gravitax);
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

	frott = 1;
	c = dyacc(&env->phy_env.collides, index);
	v = c->a->corp.v;
	norm = c->b->corp.norm;
	v2 = (t_vec3d){v.x, v.y, v.z, 0.0f};
	c->dot = vec_dot(norm, v);
	if (fabs(norm.x) > 0)
		v2 = (t_vec3d){-v.x * frott, v.y * frott, 0, 0.0f};
	else if (fabs(norm.y) > 0)
	{
		v2 = (t_vec3d){v.x * frott, -(v.y) * frott, 0, 0.0f};
		printf("fABS(v2.y) = %f\n",v2.y );
		printf("fABS(v2.y) = %f\n",vec_norm(v2));
		if ((((fabs(v2.y) < 0.3 || vec_norm(v2) > 20) && norm.y == 1)))
		{
			env->phy_env.tps = 0;
			env->maps[env->scene].stats[c->i_a] = true;
			v2 = (t_vec3d){v2.x, 0, 0, 0};
		}
	}
	return (v2);
}
/*
static int	test_choc_vertical(t_env *env, t_collide	*c)
{
	t_mesh *m;

	m = dyacc(&env->maps[env->scene].meshs, c->i_b);
	if (c->dot > 0 && m->corp.norm.y == 1.0f)
		return (1);
	else
		return (0);
}*/

static void	update_speeds(t_env *env)
{
	t_collide	*c;
	int			i;
	float			ratio;
	t_vec3d		norm;
	
	i = 0;
	while (i < env->phy_env.collides.nb_cells)
	{
		c = dyacc(&env->phy_env.collides, i);
		ratio = c->a->corp.v.y / env->phy_env.tps - vec_norm(c->a->corp.v);
		c->a->corp.v = update_angle(env, i);
		norm = c->b->corp.norm;
	/*	
		if (((fabs(c->a->corp.v.y) < 0.005 && fabs(c->a->corp.v.x) < 0.005) && norm.y == 1 && c->a->corp.pos.y < 2))
		{
			env->maps[env->scene].stats[c->i_a] = true;
			c->a->corp.v = (t_vec3d){0, 0, 0, 0};
			env->phy_env.tps = 0;
		}
	*/	i++;
	}
}
/*
static t_vec3d mini_delta(t_vec3d dif)
{
	t_vec3d delta;

	delta = dif;
	delta.x = (fabs(delta.x) > 0.5) ? 0 : delta.x;
	delta.y = (fabs(delta.y) > 0.5) ? 0 : delta.y;
	delta.z = (fabs(delta.z) > 0.5) ? 0 : delta.z;
	delta = vec_fmult(delta, -1);
	return (delta);
	
}

static int cloth_enaugh(t_vec3d dif)
{
	int i;
	
	i = -1;
		
	if (fabs(dif.x) > 1 && fabs(dif.y) > 1)
		return (0);
	else
	{
	//	printf("------------------------\n");
	//	printf("m_face = %s \n",m_face->name);
	//	printf("m.x = %f m.y = %f m.z = %f\n",m->corp.pos.x, m->corp.pos.y, m->corp.pos.z);
	//	printf("m_face.x = %f m_face.y = %f m_face.z = %f\n",m_face->corp.pos.x, m_face->corp.pos.y, m_face->corp.pos.z);
	//	printf("diff.x = %f diff.y = %f diff.z = %f\n",dif.x, dif.y, dif.z);
		return (1);
	}


}

static void	off_plan(t_env *env, t_mesh *m, int j)
{
	t_vec3d *pos;
	t_mesh	*m_face;
	t_vec3d	dif;
	int		i;

	pos = &m->corp.pos;
	i = 0; 
 	while (i < env->maps[env->scene].meshs.nb_cells)
	{
		m_face = dyacc(&env->maps[env->scene].meshs, i);
		dif = vec_sub(m_face->corp.pos, *pos);
		if (env->maps[env->scene].stats[i] == true && j != i
				&& cloth_enaugh(dif) > 0)
			translate_mesh(m, mini_delta(dif));
		i++;
	}
}
*/
/*
static int wh_in_pos(t_env *env, t_mesh *m)
{
	if (m->corp.pos.y > 0)
		
		printf()
		translate_mesh(m, (t_vec3d){0,0.1,0,0});
}
*/
static void	update_positions(t_env *env)
{
	t_mesh *m;
	int		i;

	i = 0;
	while (i < env->maps[env->scene].meshs.nb_cells)
	{
		m = dyacc(&env->maps[env->scene].meshs, i);		
		printf("name = %s\n", m->name);
		printf("------v%f %f %f-------\n",m->corp.v.x, m->corp.v.y, m->corp.v.z);
		printf("------vo %f %f %f-------\n",m->corp.vo.x, m->corp.vo.y, m->corp.vo.z);
		printf("------pos %f %f %f-------\n",m->corp.pos.x, m->corp.pos.y, m->corp.pos.z);
		printf("numero = %d\n", i);
		printf("state = %d\n", env->maps[env->scene].stats[i]);

		if (env->maps[env->scene].stats[i] == false && m->corp.pos.y > 0)
		{
			phy_gravitax(env, m, i);
			translate_mesh(m, m->corp.v);
		}
		
	
//		else if (m->corp.vo.x != 0 || m->corp.vo.y != 0|| m->corp.vo.z != 0)
//			off_plan(env, m, i);	
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
/*
static void	stop_speed(t_env *env)
{
	t_mesh *m;
	t_vec3d		v;
	int		i;

	i = 0;
	while (i < env->maps[env->scene].meshs.nb_cells)
	{
		m = dyacc(&env->maps[env->scene].meshs, i);		
		v = m->corp.v;
		if (env->maps[env->scene].stats[i] == false && vec_norm(v) > 900)
		{
			env->maps[env->scene].stats[i] = true;
			v = (t_vec3d){0, 0, 0, 0};
			env->phy_env.tps = 0;
		}
		i++;
	}
}
*/
int		physic_engine(t_env *env)
{
	unsigned int	i;
	
	i = 0;
	ft_memset(env->maps[env->scene].colls, 0, env->maps[env->scene].nmesh);
	report_collisions(env);
	color_collides(env);
	update_speeds(env);
	update_positions(env);
//	stop_speed(env);
	clear_dynarray(&env->phy_env.collides);
	return (0);
}
