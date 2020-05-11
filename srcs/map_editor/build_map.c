#include "main.h"

void			free_matrice(t_ed_map *env)
{
	int		i;
	int		j;

	if (env->map == NULL)
		return ;
	i = -1;
	while (*env->map && ++i < env->width)
	{
		j = -1;
		while (**env->map && ++j < env->height)
			ft_strdel((char**)&env->map[i][j]);
		ft_strdel((char**)&env->map[i]);
	}
	free(env->map);
	env->map = NULL;
}

int			init_matrice(t_ed_map *env)
{
	int		x;
	int		y;
	int     error;

	error = 0;
	if (!(env->map = (unsigned char ***)ft_memalloc(sizeof(unsigned char **) * env->width)))
		error = 1;
	x = -1;
	while (error == 0 && ++x < env->width)
	{
		if (!(env->map[x] = (unsigned char **)ft_memalloc(sizeof(unsigned char *) * env->height)))
			error = 1;
		y = -1;
		while (error == 0 && ++y < env->height)
		{
			if (!(env->map[x][y] = (unsigned char *)ft_memalloc(sizeof(unsigned char) * env->depth)))
				error = 1;
		}
	}
	if (error == 1)
		free_matrice(env);
	return (error == 1 ? 0 : 1);
}

static void	fill_map_bottom(t_ed_map *new)
{
	int		x;
	int		z;

	x = 0;
	while (x < new->width)
	{
		z = 0;
		while (z < new->depth)
		{
			new->map[x][0][z] = BTXT_OBSIDIENNE;
			z++;
		}
		x++;
	}
}

int			build_map(t_env *env, t_ed_map *new)
{
	if (!init_matrice(new))
		return (-1);
	fill_map_bottom(new);
	if (map_to_scene(env))
		return (-1);
	return (0);
}
