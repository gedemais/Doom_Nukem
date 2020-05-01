/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:07:50 by gedemais          #+#    #+#             */
/*   Updated: 2020/05/01 18:56:24 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char				*read_file(int fd)
{
	struct stat	file_stat;
	char		*dest;
	int			size;

	if (fstat(fd, &file_stat))
		return (NULL);
	size = file_stat.st_size;
	if (!(dest = mmap(NULL, (size_t)size, PROT_READ, MAP_FILE|MAP_PRIVATE, fd, 0)))
		return (NULL);
	return (dest);
}
