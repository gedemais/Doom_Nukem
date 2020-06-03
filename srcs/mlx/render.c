/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:50:00 by gedemais          #+#    #+#             */
/*   Updated: 2020/06/03 18:55:35 by gedemais         ###   ########.fr       */
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
	static int	(*render_fts[C_MAX])(void*) = {render_dev, render_ts, render_camp, render_custom, render_maped};
	t_env		*env;
	int			context;

	env = (t_env*)param;
	env->data.spent = (double)(clock() - env->data.time) / CLOCKS_PER_SEC;

	printf("fps : %f\n", 1 / env->data.spent);

	env->data.time = clock();

	if (env->events.keys[KEY_ESCAPE])
		exit(EXIT_SUCCESS);
	context = ((t_env*)param)->context;
	return (render_fts[context](param));
}
