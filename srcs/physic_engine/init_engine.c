/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 03:10:25 by gedemais          #+#    #+#             */
/*   Updated: 2020/06/04 15:27:41 by gedemais         ###   ########.fr       */
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


static	void init_physic_engine2(t_env *env)
{
	env->phy_env.tps = 0;
	env->phy_env.gravity = 0.0000981;
	// faire apres quand on a teste le plan en dessous du joueur ?
	env->cam.stats.onfloor = 0;
	env->cam.stats.onplan = 0;
	env->cam.stats.onwall = 0;
	//other type of plan 
}

int			init_physic_engine(t_env *env)
{
	t_mesh		*m;
	int			i;
	int			j;
	int			nb_m;
	
	i = 0;
	nb_m = -1;
	//ft_putendl("Init physic engine...");
	while (i < SCENE_MAX)
	{
		j = 0;
		while (j < env->maps[i].nmesh)
		{
			if (!(m = dyacc(&env->maps[i].meshs, j)) || init_mesh_physics(m))
				return (-1);
			j++;
		}
		ft_putchar(i == SCENE_MAX - 1 ? '\0' : '\r');
		i++;
	}
	init_physic_engine2(env);
	return (0);
}
