/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raster_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 04:33:11 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/15 02:58:52 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	compute_rotation_matrices(t_env *env, t_mesh m)
{
	update_xrotation_matrix(env->cam.rx_m, m.pitch);
	update_yrotation_matrix(env->cam.ry_m, m.yaw);
	update_zrotation_matrix(env->cam.rz_m, m.roll);
	matrix_mult_matrix(env->cam.rz_m, env->cam.rx_m, env->cam.w_m);
}

void	compute_view_matrice(t_env *env)
{
	t_vec3d	up;
	t_vec3d	target;
	float	yaw_rad;
	float	pitch_rad;

	env->cam.stats.dir = (t_vec3d){0, 0, 1, 0};
	up = (t_vec3d){0, -1, 0, 0};
	target = (t_vec3d){0, 0, 1, 0};

	yaw_rad = ft_to_radians(env->cam.stats.yaw);
	pitch_rad = ft_to_radians(env->cam.stats.pitch);
	
	update_yrotation_matrix(env->cam.cry_m, yaw_rad);
	update_xrotation_matrix(env->cam.crx_m, pitch_rad);
	matrix_mult_matrix(env->cam.crx_m, env->cam.cry_m, env->cam.cr_m);

	env->cam.stats.dir = matrix_mult_vec(env->cam.cr_m, target);
	up = matrix_mult_vec(env->cam.cr_m, (t_vec3d){0, -1, 0, 0});
	target = vec_add(env->cam.stats.pos, env->cam.stats.dir);

	matrix_pointat(env->cam.c_m, env->cam.stats.pos, target, up);

	inverse_matrix(env->cam.c_m, env->cam.v_m);
}

void	swap_floats(float *a, float *b)
{
	float	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	draw_triangle(void *mlx, t_triangle t)
{
	t_point		a;
	t_point		b;
	t_point		c;

	a = (t_point){t.points[0].x, t.points[0].y};
	b = (t_point){t.points[1].x, t.points[1].y};
	c = (t_point){t.points[2].x, t.points[2].y};
	draw_line((t_mlx*)mlx, a, b, t.color);
	draw_line((t_mlx*)mlx, a, c, t.color);
	draw_line((t_mlx*)mlx, b, c, t.color);
}
