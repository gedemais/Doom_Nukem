/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 01:54:03 by grudler           #+#    #+#             */
/*   Updated: 2020/05/08 02:12:35 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		readPathFiles(char *dir_path)
{
	DIR* dir;
	struct dirent* dirent;
	char *path;

	errno = 0;
	if (!(dir = opendir(dir_path)))
		return (-1);
	while ((dirent = readdir(dir)) != NULL)
	{
		if ((dirent->d_type == DT_DIR || dirent->d_type == DT_REG) && (*dirent->d_name != '.'))
		{
			if (!(path = (char *)malloc(sizeof(char) * (ft_strlen(dir_path) + dirent->d_namlen + 2))))
				return (-1);
			ft_bzero(path, ft_strlen(path));
			ft_strcat(path, dir_path);
			ft_strcat(path, "/");
			ft_strcat(path, dirent->d_name);
			dirent->d_type == DT_REG ? printf("%s\n", path) : readFolder(path);
			free(path);
		}
	}
	closedir(dir);
	if (errno != 0)
		return (-1);
	return (0);
}

// To do delete

int		main(int argc, char **argv)
{
	if (readFolder(argv[1]) == -1)
		printf("%s\n", "error");
	return (0);
}
