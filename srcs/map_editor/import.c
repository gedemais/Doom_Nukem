#include "main.h"

static char	*get_file_name(char *path)
{
	char	**split;
	char	*name;
	int		len;
	int		i;

	i = 0;
	if (!(split = ft_strsplit(path, "/")))
		return (NULL);
	len = ft_tablen(split);
	while (split[len - 1][i] && split[len - 1][i] != '.')
		i++;
	if (!split[len - 1][i])
	{
		ft_free_ctab(split);
		return (NULL);
	}
	if (!(name = ft_strndup(split[len - 1], i)))
	{
		ft_free_ctab(split);
		return (NULL);
	}
	ft_free_ctab(split);
	return (name);
}

int			check_header(char *file, char *path)
{
	char	*name;
	int		magic;

	magic = *(int*)file;
	if (magic != MAP_MAGIC_NUMBER)
	{
		free(file);
		return (-1);
	}
	if (!(name = get_file_name(path))
		|| ft_strncmp(&file[sizeof(int)], name, ft_strlen(name)))
	{
		free(file);
		return (-1);
	}
	free(file);
	return (0);
}

int		import_maped_map(t_edit_env *env, char *path)
{
	(void)env;
	(void)path;
	/*char	*file;
	int		len;
	int		fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (-1);
	if (!(file = read_file(fd)))
	{
		close(fd);
		return (-1);
	}
	close(fd);
	if (check_header(file, path))
		return (-1);
	//if (!())*/
	return (0);
}
