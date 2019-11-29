/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:50:00 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/29 08:01:16 by gedemais         ###   ########.fr       */
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
	t_env	*env;

	mesure_time(false);
	env = ((t_env*)param);
	handle_events(env);

	mlx_put_image_to_window(&env->mlx, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	mlx_put_image_to_window(&env->mlx, env->mlx.mlx_win, env->sprites[0].img_ptr, 0, 0);
//	printf("%f\n", ((double)1 / mesure_time(true)));
	return (0);
}
