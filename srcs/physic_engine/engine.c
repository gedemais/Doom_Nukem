/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:15:21 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/04 22:01:49 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	phy_gravitax(t_env *env, t_mesh *m, int i)
{
	static  t_vec3d		gravitax;

	gravitax = (t_vec3d){0, env->phy_env.gravity * env->phy_env.tps , 0 ,0};
	if (env->maps[env->scene].stats[i] == false)
		m->corp.v = vec_sub(m->corp.v, gravitax);
	env->phy_env.tps++;
}



static t_vec3d	update_angle(t_env *env, int index)
{
	t_collide	*c;
	t_vec3d		v;
	t_vec3d		v2;
	t_vec3d		norm;
	float		frott;

	frott = 0.75;
	c = dyacc(&env->phy_env.collides, index);
	v = c->a->corp.v;
	norm = c->b->corp.norm;
	v2 = (t_vec3d){v.x, v.y, 0, 0.0f};
	c->dot = vec_dot(norm, v);
	printf("v %f %f %f \n",v2.x, v2.y, v2.z);
	printf("norm %f %f %f \n",norm.x, norm.y, norm.z);
	printf("dot = %f\n",c->dot);
	if (fabs(norm.x) > 0)
	{
  	//signe de c.dot => signe de rotation
  	//c.dot > 0 => rotation horaire 90
  	//		< 0 => rotation antihoraire 90
		printf("a\n");
		v2 = (t_vec3d){-v.x * frott, v.y * frott, 0, 0.0f};
	}
	else if (fabs(norm.y) > 0)
	{
		v2 = (t_vec3d){v.x * frott, -(v.y * frott), 0, 0.0f};
	}
	return (v2);
}
static int	test_choc_vertical(t_env *env, t_collide	*c)
{
	t_mesh *m;

	m = dyacc(&env->maps[env->scene].meshs, c->i_b);
	if (c->dot > 0 && m->corp.norm.y == 1.0f)
		return (1);
	else
		return (0);

}

static void	update_speeds(t_env *env)
{
	t_collide	*c;
	int			i;
	float			ratio;

	i = 0;
	while (i < env->phy_env.collides.nb_cells)
	{
		c = dyacc(&env->phy_env.collides, i);
		ratio = c->a->corp.v.y / env->phy_env.tps - vec_norm(c->a->corp.v);
		c->a->corp.v = update_angle(env, i);
		printf("ratio : %f\n", fabs(ratio));
		 if (test_choc_vertical(env, c) == 1 && fabs(ratio) < 0.07)
		{
			c->a->corp.v = (t_vec3d){0, 0, 0, 0};
			env->maps[env->scene].stats[c->i_a] = true;
			//tps = 0;
		}
		else
			printf("f_abs(ratio) v_apres x = %f y = %f z = %f\n---------------\n", c->a->corp.v.x, c->a->corp.v.y, c->a->corp.v.z);
		i++;
	}
}

static void	update_positions(t_env *env)
{
	t_mesh *m;
	int		i;

	i= 0;
	while (i < env->maps[env->scene].meshs.nb_cells)
	{
		m = dyacc(&env->maps[env->scene].meshs, i);		
		if (env->maps[env->scene].stats[i] == false)
		{
		//	printf("x = %f y = %f z = %f\n",m->corp.v.x, m->corp.v.y,m->corp.v.z);
		//	printf("%d\n",env->phy_env.tps);
			phy_gravitax(env, m, i);
			translate_mesh(m, m->corp.v);
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
	unsigned int	i;
	
	i = 0;

	ft_memset(env->maps[env->scene].colls, 0, env->maps[env->scene].nmesh);
	report_collisions(env);
	color_collides(env);
	update_speeds(env);
	update_positions(env);
	//printf("%d collisions\n", env->phy_env.collides.nb_cells);
	clear_dynarray(&env->phy_env.collides);
	return (0);
}
