/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 07:15:58 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/25 01:56:57 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char		*alpha_val(void)
{
	static char		val = 0;

	return (&val);
}

void	map_sprite(char *img, t_sprite sprite, t_point o)
{
	int		x;
	int		y;
	int		k;
	int		xbound;
	int		ybound;

	xbound = o.x + sprite.wdt;
	ybound = o.y + sprite.hgt;
	k = 0;
	y = o.y;
	while (y < ybound)
	{
		x = o.x;
		while (x < xbound)
		{
			if (*(int*)(&sprite.img_data[k]) != ALPHA)
				draw_pixel(img, x, y, *(int*)(&sprite.img_data[k]));
			k += 4;
			x++;
		}
		y++;
	}
}

char	*blit_sprite(char *img, t_sprite sprite, t_point o, float scale)
{
	int		x;
	int		y;
	int		wdt;
	int		hgt;
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
		sample_x = 0.0f;
		while (x < wdt - 1)
		{
			color = sample_pixel(sprite.img_data, (t_point){sprite.wdt, sprite.hgt}, (t_vec2d){sample_x, sample_y, 0.0f});
			if (color != ALPHA)
				draw_pixel(img, x + o.x, y + o.y, color); // A remplacer par un memcpy quand le pixloc sera actif
			//ft_memcpy(&img[pixloc(x + o.x, y + o.y, false)], &color, sizeof(int)); // To try
			sample_x += delta_x;
			x++;
		}
		sample_y += delta_y;
		y++;
	}
	return (img);
}

int			load_texture(t_mlx *mlx, char *path, t_sprite *txt)
{
	int		t;

	if (!(txt->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &txt->wdt, &txt->hgt)))
		return (-1);
	//printf("Sprite (%s) : %d by %d pixels\n", path, txt->wdt, txt->hgt);
	if (!(txt->img_data = mlx_get_data_addr(txt->img_ptr, &t, &t, &t)))
		return (-1);
	reverse_texture(txt);
	return (0);
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
		loading_bar(i, SP_MAX, false);
		if (!(dest[i].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, sprites_paths(i), &dest[i].wdt, &dest[i].hgt)))
			return (NULL);
		if (!(dest[i].img_data = mlx_get_data_addr(dest[i].img_ptr, &t, &t, &t)))
			return (NULL);
		if (i < SP_MAX - 1)
			ft_putchar('\r');
		i++;
	}
	loading_bar(i, SP_MAX, true);
	return (dest);
}
