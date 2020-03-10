#include "main.h"

static int		open_mapconf(char *map_name)
{
	char			*new_path;
	char			*tmp;
	int				fd;
	unsigned int	i;

	i = 0;
	if (!(tmp = ft_strdup(map_name)))
		return (-1);
	while (tmp[i] != '.')
		i++;
	while (tmp[++i])
		tmp[i] = 0;
	new_path = ft_strjoin(tmp, "mapconf");
	free(tmp);
	if (!new_path)
		return (-1);
	if ((fd = open(new_path, O_RDONLY)) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		free(new_path);
		return (-1);
	}
	free(new_path);
	return (fd);
}

char	**get_file_lines(int fd)
{
	char	**ret;
	char	*file;

	if (!(file = read_file(fd)) || !file[0])
		return (NULL);
	if (!(ret = ft_strsplit(file, "\n")))
	{
		free(file);
		return (NULL);
	}
	return (ret);
}

static int	load_mesh_config(t_env *env, t_map *map, t_mesh *m, char *line)
{
	char			**stats;

	if (!(stats = ft_strsplit(line, "|")))
		return (-1);
	if (check_line(env, map, m, stats))
	{
		free(stats);
		return (-1);
	}
	return (0);
}

static t_mesh	*find_mesh(t_map *map, char **line)
{
	t_mesh	*m;
	int		i;

	i = 0;
	while (i < map->nmesh)
	{
		m = dyacc(&map->meshs, i);
		if (!ft_strcmp(m->name, line[0]))
			return (m);
		i++;
	}
	ft_free_ctab(line);
	return (NULL);
}

int			load_map_config(t_env *env, t_map *map, char *map_path)
{
	char			**lines;
	t_mesh			*m;
	int				fd;
	int				i;

	i = 2;
	if ((fd = open_mapconf(map_path)) == -1 || !(lines = get_file_lines(fd)))
		return (-1);
	if (ft_tablen(lines) - 3 != map->nmesh)
	{
		ft_putstr_fd(NEL_MAP, 2);
		ft_putendl_fd(map_path, 2);
		ft_free_ctab(lines);
		return (-1);
	}
	while (lines[++i])
		if (!(m = find_mesh(map, ft_strsplit(lines[i], "|")))
			|| load_mesh_config(env, map, m, lines[i]))
		{
			ft_free_ctab(lines);
			return (-1);
		}
	ft_free_ctab(lines);
	return (0);
}
