/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:50:00 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/30 00:28:00 by demaisonc        ###   ########.fr       */
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
	static float size = 1.0f;

	mesure_time(false);
	env = ((t_env*)param);
	handle_events(env);

	size += 0.001f;
	ft_memset(env->mlx.img_data, 0, sizeof(int) * WDT * HGT);
	blit_sprite(env->mlx.img_data, env->sprites[0], (int[2]){300, 300}, size);
	mlx_put_image_to_window(&env->mlx, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
