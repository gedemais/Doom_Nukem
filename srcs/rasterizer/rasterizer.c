/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:30:36 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/14 00:17:18 by gedemais         ###   ########.fr       */
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

void	compute_matrices(t_env *env)
{
	t_vec3d	up;
	t_vec3d	target;
	static float		theta = 0.0f;

	env->cam.dir = (t_vec3d){0, 0, 1, 0};
	up = (t_vec3d){0, -1, 0, 0};
	target = (t_vec3d){0, 0, 1, 0};

	update_yrotation_matrix(env->cam.cry_m, ft_to_radians(env->cam.yaw));
	update_xrotation_matrix(env->cam.crx_m, ft_to_radians(env->cam.pitch));
	matrix_mult_matrix(env->cam.crx_m, env->cam.cry_m, env->cam.cr_m);

	env->cam.dir = matrix_mult_vec(env->cam.cr_m, target);
	up = matrix_mult_vec(env->cam.cr_m, (t_vec3d){0, -1, 0, 0});
	target = vec_add(env->cam.pos, env->cam.dir);

	matrix_pointat(env->cam.c_m, env->cam.pos, target, up);

	inverse_matrix(env->cam.c_m, env->cam.v_m);
	theta -= 0.01f;
}

void		*rasthreader(void *param)
{
	t_rasthread	*thr;
	t_triangle	*t;
	t_env		*env;

	thr = (t_rasthread*)param;
	env = thr->env;
	while (thr->index < thr->end)
	{
		t = (t_triangle*)dyacc(&env->cam.to_raster, thr->index);
//		if (t->textured)
			fill_triangle_texture((t_env*)thr->env, *t);
//		else
//		fill_triangle_unit((t_env*)thr->env, *t, shade_color(0xffffff, t->illum));
		draw_triangle(&env->mlx,
			(t_point){t->points[0].x, t->points[0].y},
			(t_point){t->points[1].x, t->points[1].y},
			(t_point){t->points[2].x, t->points[2].y});
		thr->index++;
	}
	thr->done = true;
	if (thr->mono)
		return (NULL);
	else
		pthread_exit(NULL);
}

void	monothread_raster(void *e)
{
	t_rasthread		thread;
	t_env			*env;

	env = e;
	thread.env = env;
	thread.tris = &env->cam.to_raster;
	thread.start = 0;
	thread.index = 0;
	thread.end = env->cam.to_raster.nb_cells;
	thread.done = false;
	thread.mono = true;
	rasthreader(&thread);
}

void	rasterizer(t_env *env, int scene)
{
	int			i;
	int			j;
	t_mesh		*m;
	t_triangle	t;

	i = 0;
	compute_matrices(env);
	while (i < env->maps[scene].nmesh)
	{
		j = 0;
		if (!(m = dyacc(&env->maps[scene].meshs, i)))
			return ;
		compute_rotation_matrices(env, *m);
		while (j < m->faces.nb_cells)
		{
			t = *(t_triangle*)(dyacc(&m->tris, j));
			triangle_pipeline(env, t, &env->cam.to_clip);
			j++;
		}
		i++;
	}
	if (raster_triangles(env, &env->cam.to_clip))
		return ;
	clear_dynarray(&env->cam.to_clip);
}
