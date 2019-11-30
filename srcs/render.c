/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:50:00 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/30 04:12:13 by demaisonc        ###   ########.fr       */
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
	static float pan = -10.0f;

	mesure_time(false);
	env = ((t_env*)param);
	handle_events(env);

	size += 0.001f;
	pan += 1;
	ft_memset(env->mlx.img_data, 0, sizeof(int) * WDT * HGT);
	blit_sprite(env->mlx.img_data, env->sprites[0], (int[2]){300, 300}, size);
	play_sound(env->sound.samples[0], (ALfloat[3]){pan, 0, 0});
	usleep(100000);
	mlx_put_image_to_window(&env->mlx, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
