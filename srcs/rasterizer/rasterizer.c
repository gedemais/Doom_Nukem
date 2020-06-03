/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:30:36 by gedemais          #+#    #+#             */
/*   Updated: 2020/06/02 22:08:32 by gedemais         ###   ########.fr       */
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
		fill_triangle_texture((t_env*)thr->env, *t);
//		draw_triangle(&env->mlx, *t);
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

int		raster_weapon(t_env *env, t_map *map)
{
	t_cam	cam;

	ft_memcpy(&cam, &env->cam, sizeof(t_cam));
	if (rasterizer(env, map, true))
		return (-1);
	ft_memcpy(&env->cam, &cam, sizeof(t_cam));
	return (0);
}

int		rasterizer(t_env *env, t_map *map, bool respawn)
{
	t_mesh		*m;
	int			i;
	int			j;

	i = -1;
	map_spawn(env, &env->cam, map, respawn);
	compute_view_matrice(env);
	while (++i < map->nmesh)
	{
		j = -1;
		if (!(m = dyacc(&map->meshs, i)))
			return (-1);
		if (m->type == BTXT_NONE)
			continue ;
		compute_rotation_matrices(env);
		while (++j < m->tris.nb_cells)
			triangle_pipeline(env, dyacc(&m->tris, j), &env->cam.to_clip, m);
	}
	if (raster_triangles(env, &env->cam.to_clip))
		return (-1);
	env->scene = map->index;
	clear_dynarray(&env->cam.to_clip);
	return (0);
}
