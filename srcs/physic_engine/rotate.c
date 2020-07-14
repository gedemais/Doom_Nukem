/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benji_code <benji_code@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:10:33 by benji_code        #+#    #+#             */
/*   Updated: 2020/07/14 20:16:50 by benji_code       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			rotate_x(t_vec3d *v, t_vec3d m, float fcos, float fsin)
{
	float	y;
	float	z;

	y = (v->y - m.y) * fcos - (v->z - m.z) * fsin;
	z = (v->y - m.y) * fsin + (v->z - m.z) * fcos;
	v->y = y + m.y;
	v->z = z + m.z;
}

void			rotate_y(t_vec3d *v, t_vec3d m, float fcos, float fsin)
{
	float	x;
	float	z;

	x = (v->x - m.x) * fcos - (v->z - m.z) * fsin;
	z = (v->x - m.x) * fsin + (v->z - m.z) * fcos;
	v->x = x + m.x;
	v->z = z + m.z;
}

void			rotate_z(t_vec3d *v, t_vec3d m, float fcos, float fsin)
{
	float	x;
	float	y;

	x = (v->x - m.x) * fcos - (v->y - m.y) * fsin;
	y = (v->x - m.x) * fsin + (v->y - m.y) * fcos;
	v->x = x + m.x;
	v->y = y + m.y;
}
