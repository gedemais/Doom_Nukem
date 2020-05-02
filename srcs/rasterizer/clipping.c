/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 01:02:41 by gedemais          #+#    #+#             */
/*   Updated: 2020/05/02 21:57:13 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	clip_screen_edges(t_dynarray *to_raster, t_triangle t, unsigned int p)
{
	static t_vec3d	ps[4] = {{0, 1.0f, 0, 0}, {0, -1.0f, 0, 0},
								{1.0f, 0, 0, 0}, {-1.0f, 0, 0, 0}};
	t_triangle		clipped[2];
	int				to_add;
	int				i;

	i = 0;
	to_add = 0;
	if (p == 0)
		to_add = clip_triangle((t_vec3d){0, 0, 0, 0}, ps[0], t, clipped);
	else if (p == 1)
		to_add = clip_triangle((t_vec3d){0, HGT - 1, 0, 0}, ps[1], t, clipped);
	else if (p == 2)
		to_add = clip_triangle((t_vec3d){0, 0, 0, 0}, ps[2], t, clipped);
	else if (p == 3)
		to_add = clip_triangle((t_vec3d){WDT - 1, 0, 0, 0}, ps[3], t, clipped);
	while (i < to_add)
	{
		clipped[i].color = t.color;
		clipped[i].textured = t.textured;
		clipped[i].voxel = t.voxel;
		clipped[i].illum = t.illum;
		clipped[i].normal = t.normal;
		clipped[i].sp = t.sp;
		clipped[i].mesh = t.mesh;
		if (push_dynarray(to_raster, &clipped[i], false))
			return ;
		i++;
	}
}

static void	fill_to_raster(t_dynarray *to_raster, t_dynarray arrs[4], t_triangle t)
{
	t_triangle		tmp;
	unsigned int	p;
	int				i;

	p = 1;
	if (is_triangle_in_screen(t))
	{
		push_dynarray(to_raster, &t, false);
		return ;
	}
	clip_screen_edges(&arrs[0], t, 0);
	while (p < 4)
	{
		i = 0;
		while (i < arrs[p - 1].nb_cells)
		{
			tmp = *(t_triangle*)dyacc(&arrs[p - 1], i);
			clip_screen_edges(&arrs[p], tmp, p);
			i++;
		}
		clear_dynarray(&arrs[p - 1]);
		p++;
	}
	i = -1;
	while (++i < arrs[3].nb_cells)
		push_dynarray(to_raster, dyacc(&arrs[3], i), false);
	clear_dynarray(&arrs[3]);
}

void		clip_mesh_triangles(t_dynarray *tris, t_dynarray *to_raster, t_dynarray arrs[4])
{
	t_triangle		*t;
	int				i;

	i = 0;
	while (i < tris->nb_cells)
	{
		t = dyacc(tris, i);
		fill_to_raster(to_raster, arrs, *t);
		i++;
	}
	i = -1;
	while (++i < 4)
		clear_dynarray(&arrs[i]);
}

int			clip_triangle(t_vec3d plane_p, t_vec3d plane_n, t_triangle in, t_triangle out[2])
{
	t_clipper	clip;

	clip = (t_clipper){};
	plane_n = vec_normalize(plane_n);
	clip.d[0] = distance_to_plane(plane_n, plane_p, in.points[0]);
	clip.d[1] = distance_to_plane(plane_n, plane_p, in.points[1]);
	clip.d[2] = distance_to_plane(plane_n, plane_p, in.points[2]);

	classify_triangle(&clip, in);

	if (clip.inside == 0) // No point in the triangle found inside
		return (0);
	else if (clip.inside == 3) // Every points of the triangle found inside
	{
		out[0] = in;
		return (1);
	}
	else
		return (refactor_triangle(&clip, out, (t_vec3d[2]){plane_p, plane_n}, in));
	return (0);
}
