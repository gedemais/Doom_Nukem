/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:15:21 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/04 17:34:33 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_vec3d	update_angle(t_env *env, int index)
{
	t_collide	*c;
	t_vec3d		v;
	t_vec3d		v2;
	float		vnorm;
	float		angle;

	c = dyacc(&env->phy_env.collides, index);
	v = c->a->corp.vo;
	vnorm = vec_norm(v);
	angle = acos(v.x / vnorm);
	v2 = (t_vec3d){-vnorm * cosf(angle), -vnorm * sinf(angle), 0.0f, 0.0f};
	return (v2);
}

static void	update_speeds(t_env *env)
{
	t_collide	*c;
	int			i;

	i = 0;
	while (i < env->phy_env.collides.nb_cells)
	{
		c = dyacc(&env->phy_env.collides, i);
		c->a->corp.vo = update_angle(env, i);
		//c->b->corp.vo = update_angle(env, i);
		i++;
	}
}

static void	update_positions(t_env *env)
{
	t_mesh		*m;
	int			i;

	i = 0;
	while (i < env->maps[env->scene].meshs.nb_cells)
	{
		m = dyacc(&env->maps[env->scene].meshs, i);
		translate_mesh(m, m->corp.vo);
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
