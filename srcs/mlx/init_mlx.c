/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 06:26:02 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/29 06:26:04 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		init_mlx(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init())
		&& write(2, MLX_INIT_FAIL, ft_strlen(MLX_INIT_FAIL)))
		return (-1);
	if (!(mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, WDT, HGT, WINDOW_NAME))
		&& write(2, MLX_NW_FAIL, ft_strlen(MLX_NW_FAIL)))
		return (-1);
	if (!(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WDT, HGT))
		&& write(2, MLX_NI_FAIL, ft_strlen(MLX_NI_FAIL)))
		return (-1);
	if (!(mlx->img_data = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->s_l,
		&mlx->endian)) && write(2, MLX_GDA_FAIL, ft_strlen(MLX_GDA_FAIL)))
		return (-1);
	return (0);
}
