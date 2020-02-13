/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 00:13:54 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/14 00:17:16 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	project_triangle(t_env *env, t_triangle t, t_vec3d normal, t_dynarray *tris)
{
	t_triangle	clipped[2];
	int			nclip;
	int			i;

	i = 0;
	t.illum = vec_dot(normal, env->cam.light);

	// View matrix
	t.points[0] = multiply_matrix(env->cam.v_m, t.points[0]);
	t.points[1] = multiply_matrix(env->cam.v_m, t.points[1]);
	t.points[2] = multiply_matrix(env->cam.v_m, t.points[2]);

	nclip = clip_triangle((t_vec3d){0.0f, 0.0f, 0.1f, 1.0f}, (t_vec3d){0.0f, 0.0f, 1.0f, 1.0f}, t, clipped);

	while (i < nclip)
	{
		// Projection
		t.points[0] = multiply_matrix(env->cam.p_m, clipped[i].points[0]);
		t.points[1] = multiply_matrix(env->cam.p_m, clipped[i].points[1]);
		t.points[2] = multiply_matrix(env->cam.p_m, clipped[i].points[2]);

		t.txt[0] = clipped[i].txt[0];
		t.txt[1] = clipped[i].txt[1];
		t.txt[2] = clipped[i].txt[2];

		t.txt[0].u /= t.points[0].w;
		t.txt[1].u /= t.points[1].w;
		t.txt[2].u /= t.points[2].w;

		t.txt[0].v /= t.points[0].w;
		t.txt[1].v /= t.points[1].w;
		t.txt[2].v /= t.points[2].w;

		t.txt[0].w = 1.0f / t.points[0].w;
		t.txt[1].w = 1.0f / t.points[1].w;
		t.txt[2].w = 1.0f / t.points[2].w;

		t.points[0] = vec_fdiv(t.points[0], t.points[0].w);
		t.points[1] = vec_fdiv(t.points[1], t.points[1].w);
		t.points[2] = vec_fdiv(t.points[2], t.points[2].w);
		// Scaling with screen
		t.points[0] = vec_add(t.points[0], (t_vec3d){1.0f, 1.0f, 0.0f, 0.0f});
		t.points[1] = vec_add(t.points[1], (t_vec3d){1.0f, 1.0f, 0.0f, 0.0f});
		t.points[2] = vec_add(t.points[2], (t_vec3d){1.0f, 1.0f, 0.0f, 0.0f});
		t.points[0] = vec_mult(t.points[0], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f, 1.0f});
		t.points[1] = vec_mult(t.points[1], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f, 1.0f});
		t.points[2] = vec_mult(t.points[2], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f, 1.0f});

		t.color = 0xffffff;
		if (push_dynarray(tris, &t, false))
			return ;
		i++;
	}
}

void	triangle_pipeline(t_env *env, t_triangle t, t_dynarray *tris)
{
	t_vec3d		normal;
	t_vec3d		line1;
	t_vec3d		line2;

	// Translation
	t.points[0] = vec_add(t.points[0], (t_vec3d){5.0f, 3.0f, 5.0f, 0.0f});
	t.points[1] = vec_add(t.points[1], (t_vec3d){5.0f, 3.0f, 5.0f, 0.0f});
	t.points[2] = vec_add(t.points[2], (t_vec3d){5.0f, 3.0f, 5.0f, 0.0f});

	//Rotation
	t.points[0] = matrix_mult_vec(env->cam.w_m, t.points[0]);
	t.points[1] = matrix_mult_vec(env->cam.w_m, t.points[1]);
	t.points[2] = matrix_mult_vec(env->cam.w_m, t.points[2]);

	line1 = vec_sub(t.points[1], t.points[0]);
	line2 = vec_sub(t.points[2], t.points[0]);
	normal = vec_cross(line1, line2);
	vec_normalize(&normal);

	if (vec_dot(normal, vec_sub(t.points[0], env->cam.pos)) < 0.0f)
		project_triangle(env, t, normal, tris);
}

