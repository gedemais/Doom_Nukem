/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phy.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 03:01:19 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/02 22:14:33 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHY_H
# define PHY_H

struct	s_corp
{
	t_vec3d		acc;
	t_vec3d		vo;
	t_vec3d		pos;
	t_vec3d		o;
	t_vec3d		dims;
};

struct	s_collide
{
	t_mesh	*a;
	t_mesh	*b;
};

// struct s_collde

struct	s_physics
{
	t_dynarray	collides;
	double		time;
	double		prev_time;
	float		gravity;
};

int		physic_engine(t_env *env);
int		init_physic_engine(t_env *env);
int		init_bounding_box(t_mesh *m);
int		report_collisions(t_env *env);

void	translate_mesh(t_mesh *m, t_vec3d t);

#endif
