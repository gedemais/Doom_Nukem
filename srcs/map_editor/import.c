#include "main.h"

static int	ft_strclen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	gen_path(char path[MAX_MAP_PATH_LEN], char *name)
{
	ft_bzero(path, MAX_MAP_PATH_LEN);
	ft_strcpy(path, MAPED_SAVE_PATH);
	ft_strcat(path, name);
}

int			check_header(char *file, char *name, int *len)
{
	int		magic;

	if (ft_strlen(file) <= 4)
		return (-1);
	magic = *(int*)file;
	if (magic != MAP_MAGIC_NUMBER)
	{
		free(file);
		return (-1);
	}
	if (ft_strncmp(&file[sizeof(int)], name, ft_strclen(name, '.')))
	{
		free(file);
		return (-1);
	}
	*len = 4 + ft_strclen(name, '.');
	return (0);
}

int		import_maped_map(t_edit_env *env, char *name)
{
	char	path[MAX_MAP_PATH_LEN];
	char	*file;
	int		len;
	int		offset;
	int		fd;

	gen_path(path, name);
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		perror(strerror(errno));
		return (-1);
	}
	if (!(file = read_file(fd, &len)) || len < 6)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	if (check_header(file, name, &offset))
		return (-1);
	env->new_map.flat = file;
	if (!flat_to_matrice(&env->new_map, offset, len))
		return (-1);
	return (0);
}
