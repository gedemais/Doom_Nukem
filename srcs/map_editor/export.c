#include "main.h"

static int	write_header(char **str, char *map_name)
{
	char	*tmp;
	char	*tmp2;
	int		magic;

	magic = MAP_MAGIC_NUMBER;
	if (!(tmp = ft_strnew(sizeof(int))))
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

static char	*add_matrice(t_edit_env *env, char *header, int *len)
{
	char	*file;
	int		matrice_len;
	int		i;

	i = 0;
	if (!flat_map(&env->new_map, &matrice_len))
	{
		free(header);
		return (NULL);
	}
//	if (!(*file = ft_strjoin(header, env->new_map.flat)))
//		return (-1);
	if (!(file = ft_strnew(*len + matrice_len)))
		return (NULL);
	while (i < *len)
	{
		file[i] = header[i];
		i++;
	}
	free(header);
	i = 0;
	while (i < matrice_len)
	{
		file[i + *len] = env->new_map.flat[i];
		i++;
	}
	file[i + *len] = 0;
	*len += matrice_len;
	return (file);
}

int			export_maped_map(t_edit_env *env)
{
	char	path[MAX_MAP_PATH_LEN];
	char	*header;
	char	*str;
	int		len;

	if (write_header(&header, env->new_map.name))
		return (-1);
	len = ft_strlen(header);
	printf("header size : %d\n", len);
	gen_path(path, env->new_map.name);
	if (!(str = add_matrice(env, header, &len)))
		return (-1);
	if (!write_infile(path, str, len, true))
		return (-1);
	free(str);
	return (0);
}
