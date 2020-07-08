/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 06:34:55 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/08 20:27:32 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			sample_pixel(int *img, t_point size, t_vec2d point)
{
	int		pos;

	if (point.u < 0.0f || point.u >= 1.0f || point.v < 0.0f || point.v >= 1.0f)
		return (0);
	pos = (int)(point.v * size.y) * size.x;
	pos += (int)(point.u * size.x);
	return (img[pos]);
}

int			shade_color(int color, float scale)
{
	unsigned char	*rgb;

	rgb = (unsigned char*)&color;
	rgb[0] *= scale;
	rgb[1] *= scale;
	rgb[2] *= scale;
	return (color);
}

void		draw_pixel(char *img, int x, int y, int color)
{
	int			pos;

	if (x < 0 || x >= WDT || y < 0 || y >= HGT)
		return ;
	pos = pixloc(x, y, false);
	*(int*)&img[pos] = color;
}
