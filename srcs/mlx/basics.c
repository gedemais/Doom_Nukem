/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 06:34:55 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/04 10:00:58 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_pixel(char *img, int x, int y, int color)
{
	int		pos;

	if (x < 0 || x >= WDT || y < 0 || y >= HGT)
		return ;
	pos = (abs(y - 1) * WDT + x) * 4;
	ft_memcpy(&img[pos], &color, 4);
}
