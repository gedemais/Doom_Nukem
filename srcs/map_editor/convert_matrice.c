#include "main.h"

static void		copy_matrice(t_ed_map *env, int *len)
{
	int     nb[4];

	nb[0] = 0;
	nb[1] = -1;
	while (++nb[1] < env->width)
	{
		nb[2] = -1;
		while (++nb[2] < env->height)
		{
			nb[3] = -1;
			while (++nb[3] < env->width)
				env->flat[nb[0]++] = env->map[nb[1]][nb[2]][nb[3]];
			if (nb[2] + 1 < env->height)
				env->flat[nb[0]++] = '\n';
		}
		if (nb[1] + 1 < env->width)
		{
			env->flat[nb[0]++] = '\n';
			env->flat[nb[0]++] = '\n';
		}
	}
	env->flat[nb[0]] = '\0';
	*len = nb[0];
}

int			flat_map(t_ed_map *env, int *len)
{
	int     size;

	if (env->map == NULL
			|| env->width + env->height + env->depth == 0)
		return (0);
	size = (env->width + 1) * (env->height + 2) * env->depth;
	if (!(env->flat = (char *)ft_memalloc((sizeof(char) * (size + 1)))))
		return (0);
	copy_matrice(env, len);
	return (1);
}

/************************************************************/

static int		handle_backline(t_ed_map *env, int *nb)
{
	++nb[2];
	if (env->flat[nb[0] + 1] == '\n')
	{
		if (env->height == 0)
			env->height = nb[2];
		else if (env->height != nb[2])
			return (0);
		nb[2] = 0;
		++nb[3];
		++nb[0];
	}
	return (env->flat[nb[0] + 1] == '\0' ? 0 : 1);
}

static int		handle_endline(t_ed_map *env, int *nb)
{
	++nb[2];
	++nb[3];
	if (env->width == 0)
		env->width = nb[0] - nb[1];
	if (env->height == 0)
		env->height = nb[2];
	if (env->depth == 0)
		env->depth = nb[3];
	return (env->height == nb[2] ? 1 : 0);
}

static int		get_matrice_size(t_ed_map *env)
{
	int nb[4];

	nb[2] = 0;
	nb[3] = 0;
	nb[0] = -1;
	while (env->flat[++nb[0]])
	{
		nb[1] = nb[0];
		while (env->flat[nb[0]] && env->flat[nb[0]] != '\n')
			++nb[0];
		if (env->width == 0)
			env->width = nb[0] - nb[1];
		else if (env->width != nb[0] - nb[1])
			return (0);
		if (env->flat[nb[0]] == '\n')
		{
			if (handle_backline(env, nb) == 0)
				return (0);
		}
		else if (env->flat[nb[0]] == '\0')
		{
			if (handle_endline(env, nb) == 0)
				return (0);
		}
	}
	return (1);
}

static void		stock_matrice(t_ed_map *env)
{
	int w;
	int d;
	int h;
	int i;

	i = 0;
	w = -1;
	while (++w < env->width)
	{
		h = -1;
		while (++h < env->height)
		{
			d = -1;
			while(++d < env->depth)
			{
				while (env->flat[i] && env->flat[i] == '\n')
					++i;
				env->map[w][h][d] = env->flat[i];
				++i;
			}
		}
	}
}

int				flat_to_matrice(t_ed_map *env, int offset)
{
	env->flat += offset;
	if (env->flat == NULL || get_matrice_size(env) == 0
		|| init_matrice(env) == 0)
	{
		env->flat -= offset;
		return (0);
	}
	env->flat -= offset;
	stock_matrice(env);
	return (1);
}



