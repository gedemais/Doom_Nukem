/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 07:15:58 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/02 22:59:15 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*blit_sprite(char *img, t_sprite sprite, int x_y[2], float scale)
{
	int		x;
	int		y;
	int		wdt;
	int		hgt;
	int		pos;
	int		color;
	float	sample_x;
	float	sample_y;

	y = 0;
	wdt = (int)((float)sprite.wdt * scale);
	hgt = (int)((float)sprite.hgt * scale);
	if (wdt + x_y[0] >= WDT || hgt + x_y[1] >= HGT)
		return (img);
	while (y < hgt)
	{
		x = 0;
		sample_y = (float)y / (float)hgt;
		while (x < wdt)
		{
			sample_x = (float)x / (float)wdt;
			pos = (abs((int)(sample_y * sprite.hgt) - 1)) * sprite.wdt;
			pos += (int)(sample_x * sprite.wdt);
			pos *= 4;
			ft_memcpy(&color, &sprite.img_data[pos], 4);
			draw_pixel(img, x + x_y[0], y + x_y[1], color); // A remplacer par un memcpy quand le pixloc sera actif
			x++;
		}
		y++;
	}
	return (img);
}

t_sprite	*load_sprites(t_mlx mlx)
{
	unsigned int		i;
//	int					t;
	t_sprite			*dest;

	i = 0;
	if (!(dest = (t_sprite*)malloc(sizeof(t_sprite) * NB_SPRITES)))
		return (NULL);
	while (i < NB_SPRITES)
	{
		(void)mlx;
//		if (!(dest[i].img_data = bmp_read(sprites_paths(i), &dest[i].wdt, &dest[i].hgt)))
//		{
//			ft_putstr_fd(MLX_PNGTOIMG_FAIL, 2);
//			return (NULL);
//		}
/*		if (!(dest[i].img_data = mlx_get_data_addr(dest[i].img_ptr, &t, &t, &t)))
		{
			ft_putstr_fd(MLX_GDA_FAIL, 2);
			return (NULL);
		}*/
		i++;
	}
	return (dest);
}
