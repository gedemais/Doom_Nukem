/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 01:02:41 by gedemais          #+#    #+#             */
/*   Updated: 2020/01/21 15:22:54 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	classify_triangle(t_clipper *clip, t_triangle in)
{
	if (clip->d0 >= 0.0f)
		clip->in[clip->inside++] = &in.points[0];
	else
		clip->out[clip->outside++] = &in.points[0];

	if (clip->d1 >= 0.0f)
		clip->in[clip->inside++] = &in.points[1];
	else
		clip->out[clip->outside++] = &in.points[1];

	if (clip->d2 >= 0.0f)
		clip->in[clip->inside++] = &in.points[2];
	else
		clip->out[clip->outside++] = &in.points[2];
}

static int	refactor_triangle(t_clipper *clip, t_triangle out[2],
											t_vec3d plane_p, t_vec3d plane_n)
{
	if (clip->inside == 1 && clip->outside == 2)
	{
		out[0].points[0] = *(clip->in[0]);
		out[0].points[1] = vec_intersect_plane(plane_p, plane_n, *clip->in[0], *clip->out[0]);
		out[0].points[2] = vec_intersect_plane(plane_p, plane_n, *clip->in[0], *clip->out[1]);
		return (1);
	}
	else if (clip->inside == 2 && clip->outside == 1)
	{
		out[0].points[0] = *clip->in[0];
		out[0].points[1] = *clip->in[1];
		out[0].points[2] = vec_intersect_plane(plane_p, plane_n, *clip->in[0], *clip->out[0]);

		out[1].points[0] = *clip->in[1];
		out[1].points[1] = out[0].points[2];
		out[1].points[2] = vec_intersect_plane(plane_p, plane_n, *clip->in[1], *clip->out[0]);
		return (2);
	}
	return (0);
}

static void	clip_screen_edges(t_dynarray *to_raster, t_triangle t, unsigned int p)
{
	t_triangle	clipped[2];
	int			to_add;
	int			i;

	i = 0;
	to_add = 0;
	if (p == 0)
		to_add = clip_triangle((t_vec3d){0.0f, 0.0f, 0.0f, 0.0f},
			(t_vec3d){0.0f, 1.0f, 0.0f, 0.0f}, t, clipped);
	else if (p == 1)
		to_add = clip_triangle((t_vec3d){0.0f, (float)(HGT - 1), 0.0f, 0.0f},
			(t_vec3d){0.0f, -1.0f, 0.0f, 0.0f}, t, clipped);
	else if (p == 2)
		to_add = clip_triangle((t_vec3d){0.0f, 0.0f, 0.0f, 0.0f},
			(t_vec3d){1.0f, 0.0f, 0.0f, 0.0f}, t, clipped);
	else if (p == 3)
		to_add = clip_triangle((t_vec3d){(float)(WDT - 1), 0.0f, 0.0f, 0.0f},
			(t_vec3d){-1.0f, 0.0f, 0.0f, 0.0f}, t, clipped);
	while (i < to_add)
	{
		if (push_dynarray(to_raster, &clipped[i], false))
			return ;
		i++;
	}
}

void		clip_mesh_triangles(t_dynarray *tris, t_dynarray *to_raster)
{
	t_triangle		*t;
	unsigned int	p;
	int				i;
	int				nt;

	i = 0;
	nt = 1;
	while (i < tris->nb_cells && tris->nb_cells > 0)
	{
		p = 0;
		while (p < 4) // 4 planes
		{
			while (nt > 0)
			{
				t = (t_triangle*)tris->c;
				pop_dynarray(tris, true); // a faire backward peut etre
				clip_screen_edges(to_raster, *t, p);
				nt--;
			}
			nt = tris->nb_cells;
			p++;
		}
		i++;
	}
}

int			clip_triangle(t_vec3d plane_p, t_vec3d plane_n, t_triangle in, t_triangle out[2])
{
	t_clipper	clip;

	ft_memset(&clip, 0, sizeof(t_clipper));
	vec_normalize(&plane_n);
	clip.d0 = distance_to_plane(plane_n, plane_p, in.points[0]);
	clip.d1 = distance_to_plane(plane_n, plane_p, in.points[1]);
	clip.d2 = distance_to_plane(plane_n, plane_p, in.points[2]);

	classify_triangle(&clip, in);

	if (clip.inside == 0) // No point in the triangle found inside
		return (0);
	else if (clip.inside == 3) // Every points of the triangle found inside
	{
		out[0] = in;
		return (1);
	}
	else
		return (refactor_triangle(&clip, out, plane_p, plane_n));
	return (0);
}
