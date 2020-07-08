/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:18:43 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/08 21:52:54 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// kessafou dans vectors/ ?
float		rsqrt(float number)
{
	float	i;
	float	threehalfs;
	t_rsqrt	conv;

	i = number * 0.5f;
	threehalfs = 1.5f;
	conv = (t_rsqrt){ number };
	conv.i = 0x5f3759df - (conv.i >> 1);
	conv.f *= (threehalfs - (i * conv.f * conv.f));
	return (conv.f);
}


// a bouger dans physics
t_vec3d project_ortho(t_vec3d u, t_vec3d y)
{
	t_vec3d y_proj;

	y_proj = vec_fmult(u, (vec_dot(y, u) / vec_dot(u, u)));
	return (y_proj);
}

void		vec3d_swap(t_vec3d *a, t_vec3d *b)
{
	t_vec3d		t;

	t = *a;
	*a = *b;
	*b = t;
}

t_vec3d		vec_cross(t_vec3d a, t_vec3d b)
{
	t_vec3d	ret;

	ret.x = (a.y * b.z) - (a.z * b.y);
	ret.y = (a.z * b.x) - (a.x * b.z);
	ret.z = (a.x * b.y) - (a.y * b.x);
	return (ret);
}

// a virer (printf)
void	print_vec(t_vec3d vec)
{
	printf("vec.x = %f", vec.x);
	printf(" vec.y = %f", vec.y);
	printf(" vec.z = %f\n", vec.z);
}

t_vec3d zero_vector()
{
	return ((t_vec3d){0,0,0,0});
}

float	vec_norm(t_vec3d vec)
{
	return (1/ rsqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec3d	vec_normalize(t_vec3d vec)
{
	float	l;

	l = vec_norm(vec);
	return ((t_vec3d){vec.x /= l, vec.y /= l, vec.z /= l, 0});
}

float	vec_dot(t_vec3d a, t_vec3d b)
{
	float	ret;

	ret = 0.0f;
	ret += a.x * b.x;
	ret += a.y * b.y;
	ret += a.z * b.z;
	return (ret);
}

float	vec3d_dist(t_vec3d o, t_vec3d v)
{
    return (1 / rsqrt((o.x - v.x) * (o.x - v.x)
        + (o.y - v.y) * (o.y - v.y)
        + (o.z - v.z) * (o.z - v.z)));
}
