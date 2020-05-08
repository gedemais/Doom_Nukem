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
			while (++nb[3] < env->depth)
				env->flat[nb[0]++] = env->map[nb[1]][nb[2]][nb[3]];
			if (nb[2] + 1 < env->height)
				env->flat[nb[0]++] = 127;
		}
		if (nb[1] + 1 < env->width)
		{
			env->flat[nb[0]++] = 127;
			env->flat[nb[0]++] = 127;
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

static int		handle_backline(t_ed_map *env, int *nb, int len)
{
	++nb[2];
	if (env->width == 0)
		env->width = nb[0] - nb[1];
	else if (env->width != nb[0] - nb[1])
		return (0);
	if (env->flat[nb[0] + 1] == 127)
	{
		if (env->height == 0)
			env->height = nb[2];
		else if (env->height != nb[2])
			return (0);
		nb[2] = 0;
		++nb[3];
		++nb[0];
	}
	return (nb[0] + 1 != len);
}

static int		handle_endline(t_ed_map *env, int *nb)
{
	++nb[2];
	++nb[3];
	if (env->width != nb[0] - nb[1])
		return (0);
	if (env->height == 0)
		env->height = nb[2];
	if (env->depth == 0)
		env->depth = nb[3];
	return (env->height == nb[2]);
}

static int		get_matrice_size(t_ed_map *env, int len)
{
	int nb[4];

	nb[2] = 0;
	nb[3] = 0;
	nb[0] = -1;
	while (++nb[0] < len)
	{
		nb[1] = nb[0];
		while (nb[0] < len && env->flat[nb[0]] != 127)
			++nb[0];
		if (env->flat[nb[0]] == 127)
		{
			if (handle_backline(env, nb, len) == 0)
				return (0);
		}
		else if (nb[0] == len)
		{
			if (handle_endline(env, nb) == 0)
				return (0);
		}
	}
	return (env->width && env->height && env->depth);
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
				while (env->flat[i] == 127)
					++i;
				env->map[w][h][d] = env->flat[i];
				++i;
			}
		}
	}
}

int				flat_to_matrice(t_ed_map *env, int offset, int len)
{
	env->flat += offset;
	len -= offset;
	if (env->flat == NULL
		|| get_matrice_size(env, len) == 0 
		|| init_matrice(env) == 0)
	{
		env->flat -= offset;
		return (0);
	}
	stock_matrice(env);
	env->flat -= offset;
	return (1);
}
