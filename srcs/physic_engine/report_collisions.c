/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 03:00:36 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/23 04:55:38 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	boxs_collision()
{
	return (false);
}

static bool	check_collision(t_dynarray *meshs, int i, int j, t_collide *c)
{
	t_mesh	*a;
	t_mesh	*b;

	a = dyacc(meshs, i);
	b = dyacc(meshs, j);
	c->a = a;
	c->b = b;
	return (boxs_collision());
}

int			report_collisions(t_env *env)
{
	int			i;
	int			j;
	t_collide	c;

	i = 0;
	if (env->phy_env.collides.byte_size == 0
		&& init_dynarray(&env->phy_env.collides,
		sizeof(t_collide), env->maps[env->scene].nmesh))
		return (-1);
	while (i < env->maps[env->scene].nmesh - 1)
	{
		j = 0;
		while (j < env->maps[env->scene].nmesh - 1)
		{
			if (i != j && check_collision(&env->maps[env->scene].meshs, 
				i, j, &c) && push_dynarray(&env->phy_env.collides, &c, false))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
