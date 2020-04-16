/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 00:56:57 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/12 14:47:12 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	refactor_smaller(t_clipper *clip, t_triangle out[2],
											t_vec3d plane_p, t_vec3d plane_n)
{
	float	t;

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
}

static void	refactor_quad(t_clipper *clip, t_triangle out[2],
											t_vec3d plane_p, t_vec3d plane_n)
{
	float	t;

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
}

int			refactor_triangle(t_clipper *clip, t_triangle out[2],
											t_vec3d planes[2], t_triangle t)
{
	if (clip->inside == 1 && clip->outside == 2)
	{
		refactor_smaller(clip, out, planes[0], planes[1]);
		out[0].textured = t.textured;
		out[0].color = t.color;
		out[0].normal = t.normal;
		out[0].sp = t.sp;
		out[0].mesh = t.mesh;
		return (1);
	}
	else if (clip->inside == 2 && clip->outside == 1)
	{
		refactor_quad(clip, out, planes[0], planes[1]);
		out[0].textured = t.textured;
		out[0].normal = t.normal;
		out[0].color = t.color;
		out[0].mesh = t.mesh;
		out[0].sp = t.sp;

		out[1].textured = t.textured;
		out[1].normal = t.normal;
		out[1].color = t.color;
		out[1].mesh = t.mesh;
		out[1].sp = t.sp;
		return (2);
	}
	return (0);
}

void		classify_triangle(t_clipper *clip, t_triangle in)
{
	unsigned int	i;

	i = 0;
	clip->inside = 0;
	clip->outside = 0;
	while (i < 3)
	{
		if (clip->d[i] >= 0)
		{
			clip->in[clip->inside++] = in.points[i];
			clip->txt_in[clip->txt_inside++] = in.txt[i];
		}
		else
		{
			clip->out[clip->outside++] = in.points[i];
			clip->txt_out[clip->txt_outside++] = in.txt[i];
		}
		i++;
	}
}

bool		is_triangle_in_screen(t_triangle t)
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
