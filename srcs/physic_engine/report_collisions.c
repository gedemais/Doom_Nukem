/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 03:00:36 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/23 20:06:39 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void print_mesh_corp(t_mesh m)
{
	printf("acc |");
	print_vec(m.corp.acc);
	printf("vo |");
	print_vec(m.corp.vo);
	printf("v |");
	print_vec(m.corp.v);
	printf("v_cpy |");
	print_vec(m.corp.v_cpy);
	printf("pos |");
	print_vec(m.corp.pos);
	printf("o |");
	print_vec(m.corp.o);
	printf("norm |");
	print_vec(m.corp.norm);
	printf("dims |");
	print_vec(m.corp.dims);
}

void	print_collide(t_collide c)
{
	printf("%s <-> %s\n", c.a->name, c.b->name);
	printf("------\n%s\n------\n", c.a->name);
	printf("%d\n", c.i_a);
	print_mesh_corp(*c.a);
	printf("------\n%s\n------\n\n", c.b->name);
	printf("%d\n", c.i_b);
	print_mesh_corp(*c.b);

}

static bool	aabb_collision(t_vec3d abo, t_vec3d bbo, t_vec3d abd, t_vec3d bbd)
{
//	if (bbo.x >= abo.x + abd.x)
//		printf("trop a droite\n");
//	if (bbo.x + bbd.x <= abo.x)
//		printf("trop a gauche\n");
//	if (bbo.y >= abo.y + abd.y)
//		printf("trop en bas\n");
//	if (bbo.y + bbd.y <= abo.y)
///		printf("trop devant\n");
//	if (bbo.z >= abo.z + abd.z)
//		printf("trop derriere\n");
//	if (bbo.z + bbd.z <= abo.z)
//		printf("trop devant\n");
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
// il faut le tableau de mesh de la scene et la mesh camera 
// stop gravity
static bool	check_coll_cam(t_dynarray *meshs, int i, t_mesh *cam, t_collide *c)
{
	t_mesh	*a;

	a = dyacc(meshs, i);
	c->a = a;
	c->b = cam;
//	printf("%s (%f %f %f) <-> %s (%f %f %F)\n", c->a->name, c->a->corp.pos.x, c->a->corp.pos.y, c->a->corp.pos.z, c->b->name, c->b->corp.pos.x, c->b->corp.pos.y, c->b->corp.pos.z);
//	fflush(stdout);
	return (aabb_collision(a->corp.o, cam->corp.o, a->corp.dims, cam->corp.dims));
}


int			report_cam_collisions(t_env *env)
{
	int			i;
	t_collide	c;
	t_mesh	*cam;
	
	cam = &env->maps[env->scene].cam;
	if (init_dynarray(&env->phy_env.collides_cam,
		sizeof(t_collide), env->maps[env->scene].nmesh)) //pas la peine de mettre autant de case
		return (-1);
	i = 0;
	while (i < env->maps[env->scene].nmesh)
	{
		if (check_coll_cam(&env->maps[env->scene].meshs, i, cam, &c))
		{
			c.i_a = i;
			if (push_dynarray(&env->phy_env.collides_cam, &c, false))
					return (-1);
		}
		i++;
		env->maps[env->scene].colls[i] = true;
	}
	return (0);
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
				c.i_a = i;
				c.i_b = j;
				if (push_dynarray(&env->phy_env.collides, &c, false))
					return (-1);
			}
		env->maps[env->scene].colls[i] = true;
		i++;
	}
	report_cam_collisions(env);
//	printf("%d collisions\n", env->phy_env.collides.nb_cells);
	return (0);
}
