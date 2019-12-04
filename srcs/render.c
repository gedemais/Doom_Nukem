/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:50:00 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/04 03:51:09 by demaisonc        ###   ########.fr       */
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

//	mesure_time(false);
	env = ((t_env*)param);

	handle_events(env);

	ft_memset(env->mlx.img_data, 50, sizeof(int) * WDT * HGT);
//	rasterizer(env);
	blit_sprite(env->mlx.img_data, env->sprites[SP_MONKEY], (int[2]){0, 0}, 1.0f);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
//	mesure_time(true);
//	printf("%f\n", (double)1.0f / (mesure_time(true)));
	return (0);
}
