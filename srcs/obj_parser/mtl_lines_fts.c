/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_lines_fts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 05:00:50 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/15 21:49:37 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		mtl_new(char **toks, t_dynarray *mtls)
{
	t_mtl			m;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_tablen(toks) != 2)
		return (-1);
	while (i < 2)
	{
		j = 0;
		while (toks[i][j])
		{
			if (!ft_isprint(toks[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	if (!(m.name = ft_strdup(toks[1])) || push_dynarray(mtls, &m, false))
		return (-1);
	//printf("Material loaded : |%s|\n", m.name);
	return (0);
}

int		mtl_color(char **toks, t_dynarray *mtls)
{
	t_mtl			*cm;
	unsigned int	i;
	float			t;

	i = 1;
	if (!(cm = dyacc(mtls, mtls->nb_cells - 1)) || ft_tablen(toks) != 4)
		return (-1);
	ft_memset(&cm->color, 0, sizeof(int));
	while (i < 4)
	{
		if (!check_float(toks[i]))
			return (-1);
		t = atof(toks[i]);
		if (t < 0.0f || t > 1.0f)
			return (-1);
		cm->color[i - 1] = (t * 255);
		i++;
	}
	printf("\n-----------------------\n");
	return (0);
}

int		mtl_alpha(char **toks, t_dynarray *mtls)
{
	t_mtl			*cm;

	if (!(cm = dyacc(mtls, mtls->nb_cells - 1)) || ft_tablen(toks) != 2)
		return (-1);
	if ((cm->alpha = atof(toks[1])) < 0.0 || cm->alpha > 1.0f)
		return (-1);
	return (0);
}
