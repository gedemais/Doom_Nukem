/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 03:00:36 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/04 22:13:36 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	aabb_collision(t_vec3d abo, t_vec3d bbo, t_vec3d abd, t_vec3d bbd)
{
	if ((bbo.x >= abo.x + abd.x)      // trop à droite
		|| (bbo.x + bbd.x <= abo.x) // trop à gauche
		|| (bbo.y >= abo.y + abd.y) // trop en bas
		|| (bbo.y + bbd.y <= abo.y)  // trop en haut	
		|| (bbo.z >= abo.z + abd.z)   // trop derrière
		|| (bbo.z + bbd.z <= abo.z))  // trop devant
		return (false);
	return (true);
}

static bool	check_coll(t_dynarray *meshs, int i, int j, t_collide *c)
{
	t_mesh	*a;
	t_mesh	*b;

	a = dyacc(meshs, i);
	b = dyacc(meshs, j);
	c->a = a;
	c->b = b;
//	printf("%s (%f %f %f) <-> %s (%f %f %F)\n", c->a->name, c->a->corp.pos.x, c->a->corp.pos.y, c->a->corp.pos.z, c->b->name, c->b->corp.pos.x, c->b->corp.pos.y, c->b->corp.pos.z);
//	fflush(stdout);
	return (aabb_collision(a->corp.o, b->corp.o, a->corp.dims, b->corp.dims));
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
	while (i < env->maps[env->scene].nmesh)
	{
		j = -1;
		while (++j < env->maps[env->scene].nmesh)
			if (i != j && !env->maps[env->scene].stats[i]
				&& check_coll(&env->maps[env->scene].meshs, i, j, &c))
			{
				printf("%s <-> %s\n", c.a->name, c.b->name);
				if (push_dynarray(&env->phy_env.collides, &c, false))
					return (-1);
			}
		env->maps[env->scene].colls[i] = true;
		i++;
	}
	printf("%d collisions\n", env->phy_env.collides.nb_cells);
	return (0);
}
