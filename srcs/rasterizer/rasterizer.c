/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:30:36 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/15 02:05:45 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


void	*rasthreader(void *param)
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

int		rasterizer(t_env *env, int scene)
{
	int			i;
	int			j;
	t_mesh		*m;
	t_triangle	t;

	i = 0;
	compute_view_matrice(env);
	while (i < env->maps[scene].nmesh)
	{
		j = 0;
		if (!(m = dyacc(&env->maps[scene].meshs, i)))
			return (-1);
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
		return (-1);
	clear_dynarray(&env->cam.to_clip);
	return (0);
}
