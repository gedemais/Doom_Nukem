/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unarchive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 17:35:15 by grudler           #+#    #+#             */
/*   Updated: 2020/05/14 16:42:57 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		createFolders(char *path)
{
	char *tmp;
	char *subPath;

	tmp = path;
	while ((size_t)(tmp - path) < ft_strlen(path))
	{
		if (*tmp == '/')
		{
			if (!(subPath = ft_strsub(path, 0, tmp - path)))
				return (-1);
			mkdir(subPath, 0766);
			free(subPath);
		}
		tmp++;
	}
	return (0);
}

char	*ft_strsearch(const char *haystack, const char *needle, int mdr)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(needle);
	if (!len)
		return ((char *)haystack);
	while (i < mdr)
	{
		if (ft_strncmp(&haystack[i], needle, len) == 0)
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}

int		readArchi(char *archi, int len)
{
	char *tmp;
	int fd_file;

	tmp = archi;
	while (tmp)
	{
		tmp += ft_strlen(BOUNDARY) + 1;
		len -= tmp - archi;
		archi = tmp;
		if (!(tmp = ft_strchr(archi, '\n')))
			return (-1);
		*tmp = '\0';
		if (createFolders(archi) == -1)
			return (-1);
		if ((fd_file = open(archi, O_WRONLY | O_CREAT, 0666)) < 0)
			return (-1);
		len -= (tmp - archi) + 1;
		archi = tmp + 1;
		tmp = ft_strsearch(archi, BOUNDARY, len);
		write(fd_file, archi, !tmp ? len - 1 : tmp - archi - 1);
		close(fd_file);
	}
	return(0);
}


int		unarchive_directory(char *archive_path)
{
	int fd_archi;
	char *archi;
	int len;

	ft_putendl("Unarchive resources...");
	if ((fd_archi = open(archive_path, O_RDONLY)) < 0)
		return(-1);
	if (!(archi = read_file(fd_archi, &len)))
		return(free_stuff((void*[4]){NULL, &fd_archi, NULL, NULL}));
	if (readArchi(archi, len))
		return(free_stuff((void*[4]){NULL, &fd_archi, NULL, NULL}));
	close(fd_archi);
	return (0);
}
