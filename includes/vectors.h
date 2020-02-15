/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 02:39:04 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/15 02:00:08 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

struct	s_vec2d
{
	float		u;
	float		v;
	float		w;
};

struct	s_vec3d
{
	float		x;
	float		y;
	float		z;
	float		w;
};

t_vec3d			vec_add(t_vec3d a, t_vec3d b);
t_vec3d			vec_sub(t_vec3d a, t_vec3d b);
t_vec3d			vec_mult(t_vec3d a, t_vec3d b);
t_vec3d			vec_fdiv(t_vec3d a, float n);
t_vec3d			vec_fmult(t_vec3d a, float n);

void			vec3d_swap(t_vec3d *a, t_vec3d *b);
t_vec3d			vec_cross(t_vec3d a, t_vec3d b);
void			vec_normalize(t_vec3d *vec);
float			vec_dot(t_vec3d a, t_vec3d b);
float			vec_sdist(t_vec3d o, t_vec3d v);
t_vec3d			vec_intersect_plane(t_vec3d plane_p, t_vec3d plane_n,
												t_vec3d s_e[2], float *tmp);

float			distance_to_plane(t_vec3d plane_n, t_vec3d plane_p, t_vec3d p);

void			vec2d_swap(t_vec2d *a, t_vec2d *b);

#endif
