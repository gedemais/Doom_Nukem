/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <bebosson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:43:56 by bebosson          #+#    #+#             */
/*   Updated: 2020/06/05 15:45:14 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rotate_mesh(t_mesh *mesh, t_vec3d mesh_center, float angle,
			void (*rotation)(t_vec3d *v, t_vec3d m, float fcos, float fsin))
{
	int			i;
	float		fcos;
	float		fsin;
	t_triangle	*tri;

	fcos = cos(angle);
	fsin = sin(angle);
	i = -1;
	while (++i < mesh->tris.nb_cells)
	{
		tri = dyacc(&mesh->tris, i);
		rotation(&tri->points[0], mesh_center, fcos, fsin);
		rotation(&tri->points[1], mesh_center, fcos, fsin);
		rotation(&tri->points[2], mesh_center, fcos, fsin);
	}
}

void	translate_mesh(t_map *map, t_mesh *m, t_vec3d t)
{
	t_triangle	*tri;
	t_mesh		*d;
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

void	tp_mesh_print(t_mesh *m)
{
	t_triangle	*tri;
	int			i;

	i = 0;
	while (i < m->tris.nb_cells)
	{
		tri = dyacc(&m->tris, i);
		print_vec(tri->points[0]);
		print_vec(tri->points[1]);
		print_vec(tri->points[2]);
		i++;
	}
	if (i == m->tris.nb_cells)
		printf("%d \n", i);
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
