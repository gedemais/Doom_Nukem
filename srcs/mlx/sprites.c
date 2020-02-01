/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 07:15:58 by gedemais          #+#    #+#             */
/*   Updated: 2020/01/31 21:52:21 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*blit_sprite(char *img, t_sprite sprite, t_point o, float scale)
{
	int		x;
	int		y;
	int		wdt;
	int		hgt;
	int		pos;
	int		color;
	float	sample_x;
	float	sample_y;
	float	delta_x;
	float	delta_y;

	y = 0;
	wdt = (int)((float)sprite.wdt * scale);
	hgt = (int)((float)sprite.hgt * scale);
	delta_x = 1.0f / wdt;
	delta_y = 1.0f / hgt;
	if (wdt + o.x > WDT || hgt + o.y > HGT)
		return (img);
	sample_y = 0.0f;
	while (y < hgt)
	{
		x = 0;
		sample_y += delta_y;
		sample_x = 0.0f;
		while (x < wdt - 1)
		{
			sample_x += delta_x;
			pos = (abs((int)(sample_y * sprite.hgt) - 1)) * sprite.wdt;
			pos += (int)(sample_x * sprite.wdt);
			pos *= 4;
			ft_memcpy(&color, &sprite.img_data[pos], 4);
			if (color != -16777216)
				draw_pixel(img, x + o.x, y + o.y, color); // A remplacer par un memcpy quand le pixloc sera actif
			x++;
		}
		y++;
	}
	return (img);
}

t_sprite	*load_sprites(t_mlx *mlx)
{
	unsigned int		i;
	int					t;
	t_sprite			*dest;

	i = 0;
	if (!(dest = (t_sprite*)malloc(sizeof(t_sprite) * SP_MAX)))
		return (NULL);
	ft_putendl("Loading sprites...");
	while (i < SP_MAX)
	{
		if (!(dest[i].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, sprites_paths(i), &dest[i].wdt, &dest[i].hgt)))
			return (NULL);
		if (!(dest[i].img_data = mlx_get_data_addr(dest[i].img_ptr, &t, &t, &t)))
			return (NULL);
		i++;
	}
	return (dest);
}
