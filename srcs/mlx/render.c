/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:50:00 by gedemais          #+#    #+#             */
/*   Updated: 2020/06/05 18:24:57 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	mesure_time(bool end)
{
	static clock_t	start;

	if (!end)
	{
		start = clock();
		return (0);
	}
	else
		return ((double)(clock() - start) / CLOCKS_PER_SEC);
}


int		render(void *param)
{
	static int				(*render_fts[C_MAX])(void*) = {render_dev, render_ts, render_camp, render_custom, render_maped};
	static struct timeval	t;
	t_env					*env;
	t_data					*data;

	static float	fps;
	static int		it = 0;

	env = (t_env*)param;
	data = &env->data;
	gettimeofday(&t, NULL);
	data->spent = (t.tv_sec - data->time.tv_sec) * 1000;
	data->spent += (t.tv_usec - data->time.tv_usec) / 1000;
	data->spent /= 1000;
	gettimeofday(&data->time, NULL);

	fps += 1 / data->spent;
	it++;
	if (it > 30)
	{
		printf("fps : %f\n", fps / it);
		it = 0;
		fps = 0;
	}

	if (env->events.keys[KEY_ESCAPE])
		exit(EXIT_SUCCESS);
	return (render_fts[((t_env*)param)->context](param));
}
