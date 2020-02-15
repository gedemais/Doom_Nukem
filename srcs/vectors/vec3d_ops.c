/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:10:39 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/15 01:16:56 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_vec3d		vec_add(t_vec3d a, t_vec3d b)
{
	t_vec3d		ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}

t_vec3d		vec_sub(t_vec3d a, t_vec3d b)
{
	t_vec3d		ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}

t_vec3d		vec_mult(t_vec3d a, t_vec3d b)
{
	t_vec3d		ret;

	ret.x = a.x * b.x;
	ret.y = a.y * b.y;
	ret.z = a.z * b.z;
	return (ret);
}

t_vec3d		vec_fdiv(t_vec3d a, float n)
{
	t_vec3d		ret;

	ret.x = a.x / n;
	ret.y = a.y / n;
	ret.z = a.z / n;
	ret.w = a.w / n;
	return (ret);
}

t_vec3d		vec_fmult(t_vec3d a, float n)
{
	t_vec3d		ret;

	ret.x = a.x * n;
	ret.y = a.y * n;
	ret.z = a.z * n;
	return (ret);
}
