/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:50:00 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/05 05:17:33 by demaisonc        ###   ########.fr       */
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
	static float	av = 0.0f;
	static int		it = 0;

	mesure_time(false);
	env = ((t_env*)param);

	handle_events(env);

	ft_memset(env->mlx.img_data, 50, sizeof(int) * WDT * HGT);
//	rasterizer(env);
//	mlx_string_put(env->mlx.mlx_ptr, env->mlx.mlx_win, 400, 100, 0xffffff, "Maboye sent le poney");
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);

	av += ((double)1.0f / mesure_time(true));
	if (it > 50)
	{
		av /= it;
		printf("%f\n", (double)av);
		av = 0.0f;
		it = 0;
	}
	it++;
	return (0);
}
