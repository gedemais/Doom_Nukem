/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 06:34:55 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/07 18:52:56 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		shade_color(int color, float scale)
{
	unsigned char	*rgb;

	rgb = (unsigned char*)&color;
	if (scale > -1.0f && scale < 1.0f)
	{
		scale += 1.0f;
		scale /= 2.0f;
		rgb[0] = (float)rgb[0] * scale;
		rgb[1] = (float)rgb[1] * scale;
		rgb[2] = (float)rgb[2] * scale;
	}
	return (color);
}

void	draw_pixel(char *img, int x, int y, int color)
{
	int		pos;

	if (x < 0 || x >= WDT || y < 0 || y >= HGT)
		return ;
	pos = (abs(y - 1) * WDT + x) * 4;
	ft_memcpy(&img[pos], &color, 4);
}
