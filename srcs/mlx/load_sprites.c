/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 07:15:58 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/29 08:03:56 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*spaths(unsigned int index)
{
	static char		*paths[NB_SPRITES] = {"truc.xpm"};

	return (paths[index]);
}

t_sprite	*load_sprites(t_mlx mlx)
{
	unsigned int		i;
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
		if (!(dest[i].img_data = mlx_get_data_addr(dest[i].img_ptr, &dest[i].wdt, &dest[i].hgt)))
		{
			ft_putstr_fd(MLX_GDA_FAIL, 2);
			return (NULL);
		}
		i++;
	}
	return (dest);
}
