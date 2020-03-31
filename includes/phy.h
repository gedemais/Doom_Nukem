/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   phy.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 03:01:19 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/27 19:59:43 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHY_H
# define PHY_H

struct	s_corp
{
	t_vec3d		acc;
	t_vec3d		vo;
	t_vec3d		v;
	t_vec3d		v_cpy; //pause
	t_vec3d		pos;
	t_vec3d		o;
	t_vec3d		norm;
	t_vec3d		dims;
};

struct	s_collide
{
	t_mesh	*a;
	t_mesh	*b;
	unsigned int i_a;
	unsigned int i_b;
	float dot;
};

// struct s_collde

struct	s_physics
{
	t_dynarray		collides;
	double			time;
	double			prev_time;
	unsigned int	tps;
	float			gravity;
	t_vec3d			gravitax;
};

int		physic_engine(t_env *env);
int		init_physic_engine(t_env *env);
int		init_bounding_box(t_mesh *m);
int		report_collisions(t_env *env);

void	translate_mesh(t_map *map, t_mesh *m, t_vec3d t);
void	tp_mesh(t_map *map, t_mesh *m, t_vec3d t);
void	print_mesh_corp(t_mesh m);
void	print_collide(t_collide c);
void	tp_mesh_print(t_mesh *m);

#endif
