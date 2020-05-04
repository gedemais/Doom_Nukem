#include "main.h"

static int	write_header(char **str, char *map_name)
{
	char	*tmp;
	char	*tmp2;
	int		magic;

	magic = MAP_MAGIC_NUMBER;
	if (!(tmp = (char*)malloc(sizeof(char) * sizeof(int))))
		return (-1);
	ft_memcpy(tmp, &magic, sizeof(int));
	if (!(tmp2 = ft_strdup(map_name)))
	{
		free(tmp);
		return (-1);
	}
	if (!(*str = ft_strjoin(tmp, tmp2)))
	{
		free(tmp);
		free(tmp2);
		return (-1);
	}
	free(tmp);
	free(tmp2);
	return (0);
}

static void	gen_path(char path[MAX_MAP_PATH_LEN], char *name)
{
	ft_bzero(path, MAX_MAP_PATH_LEN);
	ft_strcpy(path, MAPED_SAVE_PATH);
	ft_strcat(path, name);
	ft_strcat(path, ".map");
}

static int	add_matrice(t_edit_env *env, char *header, char **file, int *len)
{
	int		matrice_len;

	if (!flat_map(&env->new_map, &matrice_len))
	{
		free(header);
		return (-1);
	}
	*len += matrice_len;
	if (!(*file = ft_strjoin(header, env->new_map.flat)))
		return (-1);
	free(header);
	return (0);
}

int			export_maped_map(t_edit_env *env)
{
	char	path[MAX_MAP_PATH_LEN];
	char	*header;
	char	*str;
	int		len;

	len = 0;
	if (write_header(&header, env->new_map.name))
		return (-1);
	len += ft_strlen(header);
	gen_path(path, env->new_map.name);
	if (add_matrice(env, header, &str, &len))
		return (-1);
	if (!write_infile(path, str, len, true))
		return (-1);
	free(str);
	return (0);
}
