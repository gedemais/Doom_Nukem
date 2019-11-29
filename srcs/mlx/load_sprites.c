/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 07:15:58 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/29 21:06:29 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*spaths(unsigned int index)
{
	static char		*paths[NB_SPRITES] = {"download.XPM"};

	return (paths[index]);
}

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
	if (scale <= 0.0f || scale > 1.0f)
		return (img);
	(void)x_y;
//	printf("wdt = %d | hgt = %d\n", sprite.wdt, sprite.hgt);
	wdt = (int)((float)sprite.wdt * scale);
	hgt = (int)((float)sprite.hgt * scale);
	printf("prop wdt = %d | prop hgt = %d\n", wdt, hgt);
	while (y < hgt)
	{
		x = 0;
		sample_y = (float)y / (float)hgt;
		while (x < wdt)
		{
			sample_x = (float)x / (float)wdt;
			pos = (int)(sample_y * sprite.hgt - 1) * sprite.wdt + (int)(sample_x * sprite.wdt) * 4;
			ft_memcpy(&color, &sprite.img_data[pos], 4);
			draw_pixel(img, x + x_y[0], y + x_y[1], color);
			x++;
		}
		y++;
	}
	return (img);
}

t_sprite	*load_sprites(t_mlx mlx)
{
	unsigned int		i;
	int					t;
	t_sprite			*dest;

	i = 0;
	if (!(dest = (t_sprite*)malloc(sizeof(t_sprite) * NB_SPRITES)))
		return (NULL);
	while (i < NB_SPRITES)
	{
		if (!(dest[i].img_ptr = mlx_xpm_file_to_image(mlx.img_ptr, spaths(i),
			&dest[i].wdt, &dest[i].hgt)))
		{
			ft_putstr_fd(MLX_PNGTOIMG_FAIL, 2);
			return (NULL);
		}
		printf("%s : height = %d | width = %d\n", spaths(i), dest[i].wdt, dest[i].hgt);
		if (!(dest[i].img_data = mlx_get_data_addr(dest[i].img_ptr, &t, &t, &t)))
		{
			ft_putstr_fd(MLX_GDA_FAIL, 2);
			return (NULL);
		}
		i++;
	}
	return (dest);
}
