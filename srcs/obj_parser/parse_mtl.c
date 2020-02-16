/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 01:12:24 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/16 04:48:23 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		check_extension(char *file_name)
{
	size_t	s;

	if ((s = ft_strlen(file_name)) < 4)
		return (-1);
	if (ft_strcmp(&file_name[s - 4], ".mtl"))
		return (-1);
	return (0);
}

int				get_material_color(t_mesh *m)
{
	(void)m;
	return (0xffffff);
}

int				parse_mtl(char *file_name)
{
	int		fd;

	printf("PARSE_MTL=====================\n%s\n", file_name);
	if (check_extension(file_name) || (fd = open(file_name, O_RDONLY)) == -1)
		return (-1);
	close(fd);
	return (0);
}
