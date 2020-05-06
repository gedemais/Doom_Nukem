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
	if (!(new_path = ft_strjoin(tmp, "mapconf")))
		return (-1);
	free(tmp);
	if (!new_path)
		return (-1);
	if ((fd = open(new_path, O_RDONLY)) == -1)
	{
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
	int		len;

	if (!(file = read_file(fd, &len)) || len == 0)
		return (NULL);
	if (!(ret = ft_strsplit(file, "\n")))
	{
		free(file);
		return (NULL);
	}
	return (ret);
}

static int	load_mesh_config(t_env *env, t_mesh *m, char *line)
{
	char		**stats;

	if (!(stats = ft_strsplit(line, "|")))
		return (-1);
	if (check_line(env, m, stats))
	{
		free(stats);
		return (-1);
	}
	return (0);
}

t_mesh		*find_mesh(t_map *map, char **line, bool *prop)
{
	t_mesh	*m;
	int		i;

	i = 0;
	*prop = true;
	if (!line)
		return (NULL);
	if (!ft_strcmp(line[0], "spawn"))
	{
		if (get_spawn_position(map, line))
			return (NULL);
	}
	else if (!ft_strcmp(line[0], "orientation"))
	{
		if (get_cam_direction(map, line))
			return (NULL);
	}
	else
		*prop = false;
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
	bool			prop;
	int				fd;
	int				i;

	i = 3;
	if ((fd = open_mapconf(map_path)) == -1 || !(lines = get_file_lines(fd)))
		return (0);
	while (lines[++i])
		if ((!(m = find_mesh(map, ft_strsplit(lines[i], "|"), &prop)) && !prop)
			|| (!prop && load_mesh_config(env, m, lines[i])))
		{
			ft_free_ctab(lines);
			return (-1);
		}
	ft_free_ctab(lines);
	if (check_deps_cycle(&map->meshs))
		return (-1);
	return (0);
}
