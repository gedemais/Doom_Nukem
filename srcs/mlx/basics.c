/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 06:34:55 by gedemais          #+#    #+#             */
/*   Updated: 2020/05/01 22:05:06 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	**init_pixloc(void)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	int				**pixloc;

	i = 0;
	k = 0;
	if (!(pixloc = (int**)malloc(sizeof(int*) * HGT)))
		return (NULL);
	while (i < HGT)
	{
		j = 0;
		if (!(pixloc[i] = (int*)malloc(sizeof(int) * WDT)))
			return (NULL);
		while (j < WDT)
		{
			pixloc[i][j] = k;
			k += 4;
			j++;
		}
		i++;
	}
	return (pixloc);
}

static void	free_pixloc(int **screen)
{
	unsigned int	i;

	i = 0;
	while (i < HGT)
	{
		free(screen[i]);
		i++;
	}
	free(screen);
}

int			pixloc(int x, int y, bool free)
{
	static int	**screen = NULL;

	if (x < 0 || x >= WDT || y < 0 || y >= HGT)
		return (-1);
	if (!screen && !(screen = init_pixloc()))
		return (-1);
	else if (free)
	{
		free_pixloc(screen);
		return (0);
	}
	return (screen[y][x]);
}

int			sample_pixel(char *img, t_point size, t_vec2d point)
{
	int		ret;
	int		pos;

	pos = abs((int)(point.v * size.y)) * size.x;
	pos += (int)(point.u * size.x);
	pos *= 4;
	ret = *(int*)(&img[pos]);
	return (ret);
}

int			shade_color(int color, float scale)
{
	unsigned char	*rgb;

	rgb = (unsigned char*)&color;
	scale += 1.0f;
	scale /= 2.0f;
	rgb[0] *= scale;
	rgb[1] *= scale;
	rgb[2] *= scale;
	return (color);
}

void		draw_pixel(char *img, int x, int y, int color)
{
	int			pos;

	pos = pixloc(x, y, false);
	if (x < 0 || x >= WDT || y < 0 || y >= HGT)
		return ;
	*(int*)&img[pos] = color;
}
