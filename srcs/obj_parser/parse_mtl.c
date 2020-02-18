/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 01:12:24 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/18 00:36:15 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		open_mtl_file(char *file_name)
{
	char		r_path[PATH_MAX + 15] = "resources/maps/";
	size_t		size;
	int			fd;

	if ((size = ft_strlen(file_name)) < 4)
		return (-1);
	if (ft_strcmp(&file_name[size - 4], ".mtl"))
		return (-1);
	ft_strcat(&r_path[0], file_name);
	fd = open(r_path, O_RDONLY);
	return (fd);
}

static char		**start_check(char *file)
{
	char			**lines;
	int				i;
	int				j;

	i = 0;
	if (!(lines = ft_strsplit(file, "\n")))
		return (NULL);
	while (lines[i])
	{
		j = -1;
		if (lines[i][0] == '#' && ++i)
			continue ;
		while (lines[i][++j])
			if (!ft_isalnum(lines[i][j]) && !ft_is_whitespace(lines[i][j])
				&& lines[i][j] != '.' && lines[i][j] != '_')
			{
				ft_free_ctab(lines);
				return (NULL);
			}
		i++;
	}
	return (lines);
}

static int		load_mtl_data(t_dynarray *mtls, char **toks, unsigned int j)
{
	static char		*qualis[MTL_MAX] = {"#", "newmtl", "Ns", "Ka", "Kd", "Ks",
													"Ke", "Ni", "d", "illum"};
	static int	(*mtl_lines_fts[MTL_MAX])(char**, t_dynarray*) = {0, mtl_new, 0,
										0, mtl_color, 0, 0, 0, mtl_alpha, 0};
	
	if (!ft_strcmp(qualis[j], toks[0]))
	{
		if (mtl_lines_fts[j] && mtl_lines_fts[j](toks, mtls))
			return (-1);
	}
	return (0);
}

static int		load_materials(t_dynarray *mtls, char **lines)
{
	char			**toks;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		if (!(toks = ft_strsplit(lines[i], " \n\r\t")))
			return (-1);
		while (j < MTL_MAX)
		{
			if (load_mtl_data(mtls, toks, j))
				return (-1);
			j++;
		}
		ft_free_ctab(toks);
		i++;
	}
	return (0);
}

int				parse_mtl(char *file_name, t_dynarray *mtls)
{
	char	**lines;
	char	*file;
	int		fd;

	if ((fd = open_mtl_file(file_name)) == -1 || !(file = read_file(fd)))
		return (-1);
	if (*init_parser())
	{
		free(file);
		return (0);
	}
	if (!(lines = start_check(file)) || load_materials(mtls, lines))
		return (-1);
	ft_free_ctab(lines);
	free(file);
	close(fd);
	return (0);
}
