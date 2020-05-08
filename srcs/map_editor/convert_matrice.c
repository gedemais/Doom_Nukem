#include "main.h"
/*
static void		print_matrice(t_ed_map *env, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (env->flat[i] != 126)
			printf("0");
		else
			printf("\n");
		i++;
	}
	printf("------------------------------------------\n");
}*/

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
				env->flat[nb[0]++] = 126;
		}
		if (nb[1] + 1 < env->width)
		{
			env->flat[nb[0]++] = 126;
			env->flat[nb[0]++] = 126;
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
	//print_matrice(env, *len);
	return (1);
}

/************************************************************/

static int		get_matrice_size(t_ed_map *env, int len)
{
	int		x;
	int		y;
	int		z;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	z = 0;
	(void)env;
	while (i < len)
	{
		printf("0 : i == %d\n", i);
		while (i < len && env->flat[i] != 126)
		{
			i++;
			x++;
		}
		printf("1 : i == %d\n", i);
		// sep lignes
		if (env->flat[i] == 126 && i < len - 1 && env->flat[i + 1] != 126)
		{
			printf("sep lignes (x = %d | w = %d)\n", x, env->width);
			if (env->width == 0)
				env->width = x;
			else if (env->width != x)
				return (0);
			x = 0;
			z++;
		}
		// sep matrices
		else if (env->flat[i] == 126 && i < len - 1 && env->flat[i + 1] == 126)
		{
			printf("sep matrices (z = %d | d = %d)\n", z, env->depth);
			if (env->depth == 0)
				env->depth = z;
			else if (env->depth != z)
				return (0);
			x = 0;
			z = 0;
			y++;
			i++;
		}
		else if (i != len)
		{
			printf("sep not found (i == %d | len == %d)\n", i, len);
			return (0); // 126 not found
		}
		i++;
	}
	env->depth++;
	env->height = y + 1;
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
				while (env->flat[i] == 126)
					++i;
				env->map[w][h][d] = env->flat[i];
				printf("%d ", env->flat[i]);
				++i;
			}
			printf("\n");
		}
		printf("\n\n");
	}
}

int				flat_to_matrice(t_ed_map *env, int offset, int len)
{
	env->flat += offset;
	len -= offset;
	//print_matrice(env, len);
	if (env->flat == NULL
		|| get_matrice_size(env, len) == 0 
		|| init_matrice(env) == 0)
	{
		env->flat -= offset;
		return (0);
	}
	printf("SIZE : %d %d %d\n", env->width, env->height, env->depth);
	stock_matrice(env);
	env->flat -= offset;
//	print_matrice(env, len);
	return (1);
}



