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

/************************************************************/

static int		handle_sep_line(t_ed_map *env, int i, int j, int hd[2])
{
	if (env->width == 0)
		env->width = i - j;
	else if (i - j != env->width)
		return (-1);

	if (env->depth == 0)
		hd[1]++;
	return (0);
}

static int		handle_sep_matrice(t_ed_map *env, int i, int j, int hd[2])
{
	(void)i;
	(void)j;
	(void)env;
	if (env->depth == 0)
		env->depth = hd[1];
	return (0);
}

static int		get_matrice_size(t_ed_map *env, int len)
{
	int		i;
	int		j;
	int		hd[2];

	i = 0;
	hd[0] = 0;
	hd[1] = 0;
	while (i < len)
	{
		j = i;
		while (i < len && env->flat[i] != 127)
			i++;
		if (env->flat[i] != 127)
			return (0);
		else if (i < len - 1 && env->flat[i + 1] != 127
				&& handle_sep_line(env, i, j, hd))
				return (0);
		else if (i < len - 1 && env->flat[i + 1] == 127
				&& handle_sep_matrice(env, i, j, hd))
				return (0);
			return (0);
		i++;
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
	env->flat -= offset;
	stock_matrice(env);
	return (1);
}



