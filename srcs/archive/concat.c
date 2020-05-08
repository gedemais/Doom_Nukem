/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 01:54:03 by grudler           #+#    #+#             */
/*   Updated: 2020/05/08 22:47:06 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		free_stuff(void *ptrs[4])
{
	if (ptrs[0])
		closedir((DIR*)ptrs[0]);
	if (ptrs[1])
		close((int)ptrs[1]);
	if (ptrs[2])
		close((int)ptrs[2]);
	if (ptrs[3])
		free(ptrs[3]);
	return (-1);
}

void	setBoundary(int fd)
{
	char boundary[81];
	char *tmp;

	tmp = boundary;
	while (tmp - boundary < 80)
	{
		*tmp++ = '#';
	}
	*tmp = '\n';
	write(fd, boundary, 81);
}


int		concatFiles(char *path, int fd_archi)
{
	int fd_file;
	int len;
	char *contain;

	setBoundary(fd_archi);
	write(fd_archi, path, ft_strlen(path));
	write(fd_archi, "\n\n", 2);
	if (!(fd_file = open(path, O_RDONLY)))
		return (-1);
	if (!(contain = read_file(fd_file, &len)))
		return(free_stuff((void*[4]){NULL, NULL, &fd_file, NULL}));
	close(fd_file);
	if (len)
	{
		write(fd_archi, contain, len);
		write(fd_archi, "\n", 1);
	}
	return (0);
}

int		readFolder(char *dir_path)
{
	DIR* dir;
	struct dirent* dirent;
	char *path;
	int fd_archi;

	errno = 0;
	if (!(dir = opendir(dir_path)))
		return (-1);
	if (!(fd_archi = open("resources.archi", O_CREAT | O_WRONLY | O_APPEND, 0666)))
	{
		return(free_stuff((void*[4]){dir, NULL, NULL, NULL}));
	}
	while ((dirent = readdir(dir)) != NULL)
	{
		if ((dirent->d_type == DT_DIR || dirent->d_type == DT_REG) && (*dirent->d_name != '.'))
		{
			if (!(path = ft_strnew(ft_strlen(dir_path) + dirent->d_namlen + 2)))
					return(free_stuff((void*[4]){dir, &fd_archi, NULL, NULL}));
			ft_strcat(path, dir_path);
			ft_strcat(path, "/");
			ft_strcat(path, dirent->d_name);
			if (dirent->d_type == DT_REG && concatFiles(path, fd_archi))
				return(free_stuff((void*[4]){dir, &fd_archi, NULL, path}));
			else if (dirent->d_type == DT_DIR)
				readFolder(path);
			free(path);
		}
	}
	closedir(dir);
	close(fd_archi);
	return (errno == 0 ? 0 : -1);
}

int		main(int argc, char **argv)
{
	if (readFolder(argv[1]))
		printf("%s\n", "error");
	return (0);
}
