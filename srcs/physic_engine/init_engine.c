/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 03:10:25 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/09 17:32:54 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		set_mesh_position(t_mesh *m)
{
	t_vec3d		average;
	t_triangle	*t;
	int			i;

	i = 0;
	average = (t_vec3d){0, 0, 0, 0};
	while (i < m->tris.nb_cells)
	{
		if (!(t = dyacc(&m->tris, i)))
			return (-1);
		average = vec_add(average, t->points[0]);
		average = vec_add(average, t->points[1]);
		average = vec_add(average, t->points[2]);
		i++;
	}
	m->corp.pos = vec_fdiv(average, (float)i);
	m->corp.pos = vec_fdiv(m->corp.pos, 3.0f);
   	return (0);
}
static int		init_mesh_physics(t_mesh *m)
{

	if (set_mesh_position(m) || init_bounding_box(m))
		return (-1);
	return (0);
}
/*
static void	set_hparams(t_physics *phy)
{
	phy->gravity = 9.9f;
}


static void	set_norm_face(t_env *env)
{
	t_mesh		*m;

	m = dyacc(&env->maps[env->scene].meshs, 1);
	m->corp.norm = (t_vec3d){0, 1, 0, 0};
	m = dyacc(&env->maps[env->scene].meshs, 2);
	m->corp.norm = (t_vec3d){0, -1, 0, 0};
	m = dyacc(&env->maps[env->scene].meshs, 3);
	m->corp.norm = (t_vec3d){-1, 0, 0, 0};
	m = dyacc(&env->maps[env->scene].meshs, 4);
	m->corp.norm = (t_vec3d){1, 0, 0, 0};
	m = dyacc(&env->maps[env->scene].meshs, 5);
	m->corp.norm = (t_vec3d){-1, 0, 0, 0};
	m = dyacc(&env->maps[env->scene].meshs, 6);
	m->corp.norm = (t_vec3d){-1, 0, 0, 0};

}

static void	init_static_physic(t_env *env)
{
	int i;

	i = -1;
	env->maps[env->scene].stats[0] = true;
	env->maps[env->scene].stats[1] = true;
	env->maps[env->scene].stats[2] = true;
	env->maps[env->scene].stats[3] = true;
	env->maps[env->scene].stats[4] = false;
	while (++i < 5)
		env->maps[env->scene].stats_cpy[i] = env->maps[env->scene].stats[i];
}
*/	

int		init_physic_engine(t_env *env)
{
	t_mesh		*m;
	int			i;
	int			j;
	int			nb_m;
	static int x = 0;
	
	i = 0;
	nb_m = -1;
//	set_hparams(&env->phy_env);
	ft_putendl("Init physic engine...");
	while (i < SCENE_MAX)
	{
//		loading_bar(i, SCENE_MAX, false);
		printf("----------------------\nScene %d (%d meshs)\n", i, env->maps[i].nmesh);
		j = 0;
		if (!(env->maps[i].stats_cpy = (bool*)malloc(sizeof(bool) * env->maps[i].nmesh)))
			return (-1);
		while (j < env->maps[i].nmesh)
		{
			printf("mesh %d\n", j);
			if (!(m = dyacc(&env->maps[i].meshs, j)) || init_mesh_physics(m))
				return (-1);
			j++;
		}
		ft_putchar(i == SCENE_MAX - 1 ? '\0' : '\r');
		i++;
	}
	i--;
	while (++nb_m < 7)
	{
		m = dyacc(&env->maps[i].meshs, nb_m);
		env->maps[i].stats_cpy[j] = env->maps[env->scene].stats[j];
		if (nb_m == 0)
		{
			m->corp.vo = (t_vec3d){0, 0.2, 0.2f, 0.0f};
			m->corp.pos = (t_vec3d){0, 20, 0.0f, 0.0f};
			m->corp.v = m->corp.vo;
			printf("name = %s\n", m->name);
			printf("------v%f %f %f-------\n",m->corp.v.x, m->corp.v.y, m->corp.v.z);
			printf("------vo %f %f %f-------\n",m->corp.vo.x, m->corp.vo.y, m->corp.vo.z);
			printf("------pos %f %f %f-------\n",m->corp.pos.x, m->corp.pos.y, m->corp.pos.z);
			printf("numero = %d\n", i);
			printf("state = %d\n", env->maps[i].stats[j]);
		}
	}
	env->phy_env.tps = 0;
	env->phy_env.gravity = 0.0000981;
//	set_norm_face(env);
/*	env->maps[env->scene].stats[0] = true;
	env->maps[env->scene].stats[1] = true;
	env->maps[env->scene].stats[2] = true;
	env->maps[env->scene].stats[3] = true;
	env->maps[env->scene].stats[4] = false;*/
//	printf("%s | pos : %f %f %f | origin : %f %f %f | dims = %f %f %f\n norm = %f %f %f\n", m->name, m->corp.pos.x, m->corp.pos.y, m->corp.pos.z, m->corp.o.x, m->corp.o.y, m->corp.o.z, m->corp.dims.x, m->corp.dims.y, m->corp.dims.z, m->corp.norm.x, m->corp.norm.y, m->corp.norm.z);
	if (++x > 5)
		exit(EXIT_SUCCESS);

//	loading_bar(i, SCENE_MAX, true);
	return (0);
}
