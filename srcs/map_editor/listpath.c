#include "main.h"

static void     tab_free(void **add, int len)
{
	int i;

	if (add == NULL)
		return ;
	i = -1;
	while (++i < len && add[i])
		ft_memdel(&add[i]);
	ft_memdel(add);
}

static char     **tab_add(char **tab, const char *str)
{
	int		i;
	int     error;
	char	**ret;

	error = 0;
	if (tab == NULL || str == NULL)
		error = 1;
	if (error == 1
			|| !(ret = (char **)ft_memalloc(sizeof(char *)
					* (ft_tablen(tab) + 2))))
		error = 1;
	i = -1;
	while (error == 0 && tab[++i])
		if (!(ret[i] = ft_strdup(tab[i])))
			error = 1;
	if (error == 1 || !(ret[i] = ft_strdup(str)))
		error = 1;
	if (error == 1)
		tab_free((void **)ret, ft_tablen(ret));
	else
		ret[++i] = NULL;
	tab_free((void **)tab, ft_tablen(tab));
	return (ret);
}

static int      good_format(char *str, char *format)
{
	int     i;
	int     len;

	len = ft_strlen(format);
	i = -1;
	while (++i < len)
		if (!ft_isalnum(format[i]) && !(format[i] == '.'))
			return (0);
	return (!ft_strcmp(str, format) ? 1 : 0);
}

static int      check_format(char ***path_tab, struct dirent *read,
		char *format, int *len)
{
	int size;

	size = ft_strlen(read->d_name);
	while (size > 0 && read->d_name[size] != '.')
		--size;
	if (size == 0)
		return (0);
	if (good_format(read->d_name + size, format) == 1)
	{
		while (--size > -1)
			if (!ft_isalnum(read->d_name[size]))
				return (0);
		if (!(*path_tab = tab_add(*path_tab, read->d_name)))
			return (-1);
		++(*len);
		return (1);
	}
	return (0);
}

char        **listpath(char *d_path, char *format)
{
	int             len;
	char            **path_tab;
	DIR             *dir;
	struct dirent   *read;

	path_tab = NULL;
	dir = opendir(d_path);
	if (dir)
	{
		len = 0;
		if (!(path_tab = (char **)ft_memalloc(sizeof(char *) * 1)))
			return (NULL);
		while ((read = readdir(dir)))
			if (check_format(&path_tab, read, format, &len) == -1)
				break ;
		closedir(dir);
	}
	return (path_tab);
}
