/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_triangles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 04:05:39 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/01 04:25:44 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	swap_meshs(void *a, void *b)
{
	char	buff[sizeof(t_mesh)];

	ft_memcpy(buff, a, sizeof(t_mesh));
	ft_memcpy(a, b, sizeof(t_mesh));
	ft_memcpy(b, buff, sizeof(t_mesh));
}

void		sort_meshs(t_dynarray *meshs, int nmesh)
{
	int		i;
	int		j;

	i = 0;
	while (i < nmesh)
	{
		j = 0;
		while (j < nmesh - 1)
		{
			if (((t_mesh*)(dyacc(meshs, j)))->tris.nb_cells <
				((t_mesh*)(dyacc(meshs, j + 1)))->tris.nb_cells)
				swap_meshs(dyacc(meshs, j), dyacc(meshs, j + 1));
			j++;
		}
		i++;
	}
}
