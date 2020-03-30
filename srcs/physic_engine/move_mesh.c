/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 03:53:54 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/29 22:52:12 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	translate_mesh(t_map *map, t_mesh *m, t_vec3d t)
{
	t_triangle	*tri;
	t_mesh		*d;
	int			i;

	i = 0;
	printf("%d\n", m->tris.nb_cells);
	while (i < m->tris.nb_cells)
	{
		tri = dyacc(&m->tris, i);
		tri->points[0] = vec_add(tri->points[0], t);
		tri->points[1] = vec_add(tri->points[1], t);
		tri->points[2] = vec_add(tri->points[2], t);
		i++;
	}
	i = 0;
	while (map && i < m->deps.nb_cells)
	{
		d = dyacc(&map->meshs, *(int*)dyacc(&m->deps, i));
		translate_mesh(map, d, t);
		i++;
	}
	m->corp.pos = vec_add(m->corp.pos, t);
	m->corp.o = vec_add(m->corp.o, t);
}

void	tp_mesh(t_map *map, t_mesh *m, t_vec3d p)
{
	t_triangle	*tri;
	t_vec3d		diff;
	int			i;

	(void)map;
	i = 0;
	diff = vec_sub(m->corp.pos, p);
	while (i < m->tris.nb_cells)
	{
		tri = dyacc(&m->tris, i);
		tri->points[0] = vec_add(tri->points[0], diff);
		tri->points[1] = vec_add(tri->points[1], diff);
		tri->points[2] = vec_add(tri->points[2], diff);
		i++;
	}
	m->corp.pos = p;
	m->corp.o = vec_add(m->corp.o, diff);
	if (!map)
		return ;
}
