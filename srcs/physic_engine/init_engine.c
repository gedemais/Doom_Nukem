/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 03:10:25 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/15 04:05:29 by gedemais         ###   ########.fr       */
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
	m->pos = vec_fdiv(average, (float)i);
	return (0);
}

static int		init_mesh_physics(t_mesh *m)
{
	if (set_mesh_position(m))
		return (-1);
	return (0);
}

static void	set_hparams(t_physics *phy)
{
	phy->gravity = 9.9f;
}

int		init_physic_engine(t_env *env)
{
	t_mesh		*m;
	int		i;
	int		j;

	i = 0;
	set_hparams(&env->phy_env);
	ft_putendl("Init physic engine...");
	while (i < SCENE_MAX)
	{
		loading_bar(i, SCENE_MAX, false);
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
	loading_bar(i, SCENE_MAX, true);
	return (0);
}