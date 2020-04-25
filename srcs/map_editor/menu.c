/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:02:32 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/25 18:19:43 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		maped_menu(t_env *env)
{
	map_sprite(env->mlx.img_data, env->sprites[SP_ME_BACKGROUND], (t_point){0, 0});
	
	map_sprite(env->mlx.img_data, env->sprites[SP_ME_BACKGROUND], (t_point){0, 0});
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
