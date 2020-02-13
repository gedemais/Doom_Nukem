/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 01:02:41 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/13 22:11:10 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	classify_triangle(t_clipper *clip, t_triangle in)
{
	clip->inside = 0;
	clip->outside = 0;
	if (clip->d0 >= 0.0f)
	{
		clip->in[clip->inside++] = in.points[0];
		clip->txt_in[clip->txt_inside++] = in.txt[0];
	}
	else
	{
		clip->out[clip->outside++] = in.points[0];
		clip->txt_out[clip->txt_outside++] = in.txt[0];
	}

	if (clip->d1 >= 0.0f)
	{
		clip->in[clip->inside++] = in.points[1];
		clip->txt_in[clip->txt_inside++] = in.txt[1];
	}
	else
	{
		clip->out[clip->outside++] = in.points[1];
		clip->txt_out[clip->txt_outside++] = in.txt[1];
	}

	if (clip->d2 >= 0.0f)
	{
		clip->in[clip->inside++] = in.points[2];
		clip->txt_in[clip->txt_inside++] = in.txt[2];
	}
	else
	{
		clip->out[clip->outside++] = in.points[2];
		clip->txt_out[clip->txt_outside++] = in.txt[2];
	}
	/*
	for (int i = 0; i < clip->inside || i < clip->outside; i++)
	{
		if (i < clip->outside)
			printf("outside[%d] = %f %f\n", i, clip->out[i].x, clip->out[i].y);
		if (i < clip->inside)
			printf("inside[%d] = %f %f\n", i, clip->in[i].x, clip->in[i].y);
	}
	printf("\n");*/
}

static int	refactor_triangle(t_clipper *clip, t_triangle out[2],
											t_vec3d plane_p, t_vec3d plane_n)
{
	float	t;

	if (clip->inside == 1 && clip->outside == 2)
	{
		out[0].points[0] = clip->in[0];
		out[0].txt[0] = clip->txt_in[0];

		out[0].points[1] = vec_intersect_plane(plane_p, plane_n, (t_vec3d[2]){clip->in[0], clip->out[0]}, &t);
		out[0].txt[1].u = t * (clip->txt_out[0].u - clip->txt_in[0].u) + clip->txt_in[0].u;
		out[0].txt[1].v = t * (clip->txt_out[0].v - clip->txt_in[0].v) + clip->txt_in[0].v;
		out[0].txt[1].w = t * (clip->txt_out[0].w - clip->txt_in[0].w) + clip->txt_in[0].w;

		out[0].points[2] = vec_intersect_plane(plane_p, plane_n, (t_vec3d[2]){clip->in[0], clip->out[1]}, &t);
		out[0].txt[2].u = t * (clip->txt_out[1].u - clip->txt_in[0].u) + clip->txt_in[0].u;
		out[0].txt[2].v = t * (clip->txt_out[1].v - clip->txt_in[0].v) + clip->txt_in[0].v;
		out[0].txt[2].w = t * (clip->txt_out[1].w - clip->txt_in[0].w) + clip->txt_in[0].w;
		return (1);
	}
	else if (clip->inside == 2 && clip->outside == 1)
	{
		out[0].points[0] = clip->in[0];
		out[0].points[1] = clip->in[1];
		out[0].txt[0] = clip->txt_in[0];
		out[0].txt[1] = clip->txt_in[1];

		out[0].points[2] = vec_intersect_plane(plane_p, plane_n, (t_vec3d[2]){clip->in[0], clip->out[0]}, &t);
		out[0].txt[2].u = t * (clip->txt_out[0].u - clip->txt_in[0].u) + clip->txt_in[0].u;
		out[0].txt[2].v = t * (clip->txt_out[0].v - clip->txt_in[0].v) + clip->txt_in[0].v;
		out[0].txt[2].w = t * (clip->txt_out[0].w - clip->txt_in[0].w) + clip->txt_in[0].w;

		out[1].points[0] = clip->in[1];
		out[1].txt[0] = clip->txt_in[1];

		out[1].points[1] = out[0].points[2];
		out[1].txt[1] = out[0].txt[2];

		out[1].points[2] = vec_intersect_plane(plane_p, plane_n, (t_vec3d[2]){clip->in[1], clip->out[0]}, &t);
		out[1].txt[2].u = t * (clip->txt_out[0].u - clip->txt_in[1].u) + clip->txt_in[1].u;
		out[1].txt[2].v = t * (clip->txt_out[0].v - clip->txt_in[1].v) + clip->txt_in[1].v;
		out[1].txt[2].w = t * (clip->txt_out[0].w - clip->txt_in[1].w) + clip->txt_in[1].w;
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
		to_add = clip_triangle((t_vec3d){0.0f, (float)(HGT - 1.0f), 0.0f, 0.0f},
			(t_vec3d){0.0f, -1.0f, 0.0f, 0.0f}, t, clipped);
	else if (p == 2)
		to_add = clip_triangle((t_vec3d){0.0f, 0.0f, 0.0f, 0.0f},
			(t_vec3d){1.0f, 0.0f, 0.0f, 0.0f}, t, clipped);
	else if (p == 3)
		to_add = clip_triangle((t_vec3d){(float)(WDT - 1), 0.0f, 0.0f, 0.0f},
			(t_vec3d){-1.0f, 0.0f, 0.0f, 0.0f}, t, clipped);
	while (i < to_add)
	{
		clipped[i].color = t.color;
		clipped[i].illum = t.illum;
		if (push_dynarray(to_raster, &clipped[i], false))
			return ;
		i++;
	}
}

static bool	is_triangle_in_screen(t_triangle t)
{
	unsigned int	i;

	i = 0;
	while (i < 3)
	{
		if (t.points[i].x < 0 || t.points[i].x >= WDT
			|| t.points[i].y < 0 || t.points[i].y >= HGT)
			return (false);
		i++;
	}
	return (true);
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
