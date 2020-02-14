/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raster_triangles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 02:08:49 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/14 04:35:44 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	relaunch_thread(t_rasthread threads[NB_THREADS], int i)
{
	int				t;
	int				j;
	unsigned int	work;
	unsigned int	max_work;

	j = -1;
	t = -1;
	max_work = 0;
	while (++j < NB_THREADS)
		if (i != j && (work = threads[j].end - threads[j].index) > max_work)
		{
			max_work = work;
			t = j;
		}
	if (t == -1)
		return (0);
	threads[i].start = threads[t].index + (max_work / 2); // Placing new's start
	threads[i].index = threads[i].start; // Placing new's start
	threads[i].end = threads[t].end; // Placing new's end
	threads[t].end = threads[i].start; // Copying on weak's end
	threads[i].done = false;
	threads[t].done = false;
	if (pthread_create(&threads[i].thread, NULL, rasthreader, &threads[i]))
		return (-1);
	return (threads[i].start - threads[i].end);
}

static void	manage_threads(t_rasthread threads[NB_THREADS], t_dynarray *arr)
{
	unsigned int	i;
	int				waste;
	int				amount;
	int				relaunched = 0;

	amount = INT_MAX;
	waste = (arr->nb_cells / NB_THREADS);
	while (amount > waste)
	{
		i = 0;
		while (i < NB_THREADS)
		{
			if (threads[i].done)
			{
				amount = relaunch_thread(threads, (int)i);
				relaunched++;
				break ;
			}
			i++;
		}
	}
}

static int	launch_thread(t_env *env, t_rasthread *thread, int part, int rest)
{
	(void)rest;
	thread->env = env;
	thread->tris = &env->cam.to_raster;
	thread->start = thread->id * part;
	thread->index = thread->start;
	thread->end = thread->start + part + (thread->id == NB_THREADS - 1 ? rest : 0);
	thread->done = false;
	thread->mono = false;
	if (pthread_create(&thread->thread, NULL, rasthreader, thread))
		return (-1);
	return (0);
}

static int	switch_threads(t_env *env, t_rasthread threads[NB_THREADS],
														int work_size, bool w)
{
	unsigned int	i;
	int				rest;

	i = 0;
	rest = work_size % NB_THREADS;
	while (i < NB_THREADS && i < (unsigned)work_size)
	{
		if (w)
		{
			if (pthread_join(threads[i].thread, NULL))
				return (-1);
		}
		else
		{
			threads[i].id = (int)i;
			if (launch_thread(env, &threads[i], work_size / NB_THREADS, rest))
				return (-1);
		}
		i++;
	}
	return (0);
}

int			raster_triangles(void *e, t_dynarray *arr)
{
	t_rasthread	threads[NB_THREADS];
	t_env		*env;
	int			i;

	i = -1;
	env = e;
	clip_mesh_triangles(arr, &env->cam.to_raster, env->cam.clip_arrs);
	if (env->cam.to_raster.nb_cells < NB_THREADS)
		monothread_raster(env);
	else
	{
		switch_threads(env, threads, env->cam.to_raster.nb_cells, false);
		manage_threads(threads, &env->cam.to_raster);
		switch_threads(env, threads, env->cam.to_raster.nb_cells, true);
	}
	clear_dynarray(&env->cam.to_raster);
	return (0);
}
