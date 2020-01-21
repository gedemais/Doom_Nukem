/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 01:02:41 by gedemais          #+#    #+#             */
/*   Updated: 2020/01/19 09:42:47 by gedemais         ###   ########.fr       */
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
