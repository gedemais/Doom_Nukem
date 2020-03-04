/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:18:43 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/03 19:29:03 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

float	vec_norm(t_vec3d vec)
{
	return (sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec3d	vec_normalize(t_vec3d vec)
{
	float	l;

	l = sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return ((t_vec3d){vec.x /= l, vec.y /= l, vec.z /= l, 0.0f});
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

float	vec_sdist(t_vec3d o, t_vec3d v)
{
	float	ret;

	ret = 0.0f;
	ret += o.x * v.x;
	ret += o.y * v.y;
	ret += o.z * v.z;
	return (ret);
}
