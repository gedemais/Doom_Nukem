/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 03:53:54 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/15 05:11:57 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	translate_mesh(t_mesh *m, t_vec3d t)
{
	t_triangle	*tri;
	int			i;

	i = 0;
	while (i < m->tris.nb_cells)
	{
		tri = dyacc(&m->tris, i);
		tri->points[0] = vec_add(tri->points[0], t);
		tri->points[1] = vec_add(tri->points[1], t);
		tri->points[2] = vec_add(tri->points[2], t);
		i++;
	}
}
