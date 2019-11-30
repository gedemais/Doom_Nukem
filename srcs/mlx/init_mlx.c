/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 06:26:02 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/30 21:12:46 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		init_mlx(t_env *env)
{
	if (!(env->mlx.mlx_ptr = mlx_init())
		&& write(2, MLX_INIT_FAIL, ft_strlen(MLX_INIT_FAIL)))
		return (-1);
	if (!(env->mlx.mlx_win = mlx_new_window(env->mlx.mlx_ptr, WDT, HGT, WINDOW_NAME))
		&& write(2, MLX_NW_FAIL, ft_strlen(MLX_NW_FAIL)))
		return (-1);
	if (!(env->mlx.img_ptr = mlx_new_image(env->mlx.mlx_ptr, WDT, HGT))
		&& write(2, MLX_NI_FAIL, ft_strlen(MLX_NI_FAIL)))
		return (-1);
	if (!(env->mlx.img_data = mlx_get_data_addr(env->mlx.img_ptr, &env->mlx.bpp, &env->mlx.s_l,
		&env->mlx.endian)) && write(2, MLX_GDA_FAIL, ft_strlen(MLX_GDA_FAIL)))
		return (-1);
	return (0);
}
