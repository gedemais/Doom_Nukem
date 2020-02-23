/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bounding_boxs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:42:04 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/23 21:26:14 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	get_box_dims(t_mesh *m)
{
	t_triangle	*t;
	int			i;
	int			j;

	i = 0;
	m->corp.dims = (t_vec3d){0.0f, 0.0f, 0.0f, 0.0f};
	while (i < m->tris.nb_cells)
	{
		j = 0;
		if (!(t = dyacc(&m->tris, i)))
			return (-1);
		while (j < 3)
		{
			if (m->corp.pos.x - t->points[j].x > m->corp.dims.x)
				m->corp.dims.x = m->corp.pos.x - t->points[j].x;
			if (m->corp.pos.y - t->points[j].y > m->corp.dims.y)
				m->corp.dims.y = m->corp.pos.y - t->points[j].y;
			if (m->corp.pos.z - t->points[j].z > m->corp.dims.z)
				m->corp.dims.z = m->corp.pos.z - t->points[j].z;
			j++;
		}
		i++;
	}
	return (0);
}

int		init_bounding_box(t_mesh *m)
{
	if (get_box_dims(m))
		return (-1);
	m->corp.o = vec_sub(m->corp.pos, m->corp.dims);
	return (0);
}
