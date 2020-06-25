/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:21:03 by gedemais          #+#    #+#             */
/*   Updated: 2020/06/25 07:39:49 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		vec2d_swap(t_vec2d *a, t_vec2d *b)
{
	t_vec2d		t;

	t = *a;
	*a = *b;
	*b = t;
}

float		vec2d_det_xz(t_vec3d a, t_vec3d b)
{
	return(a.x * b.z - a.z * b.x);
}

float		vec2d_dot_xz(t_vec3d a, t_vec3d b)
{
	return(a.x * b.x + a.z * b.z);
}
