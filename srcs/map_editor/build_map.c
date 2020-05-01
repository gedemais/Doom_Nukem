#include "main.h"

static int	free_map_matrice(char ***map, int width, int height)
{
    int        i;
    int        j;

    if (map == NULL)
        return (NULL);
    i = -1;
    while (*map && ++i < width)
    {
        j = -1;
        while (**map && ++j < height)
            ft_strdel(&map[i][j]);
        ft_strdel(map[i]);
    }
    free(map);
    map = NULL;
    return (0);
}

static char		***init_map_matrice(int w, int h, int d)
{
	char	***map;
	int		x;
	int		y;

	if (!(map = (char ***)ft_memalloc(sizeof(char **) * w)))
		exit(1);
	x = -1;
	while (++x < w)
	{
		if (!(map[x] = (char **)ft_memalloc(sizeof(char *) * h)))
			exit(1);
		y = -1;
		while (++y < h)
		{
			if (!(map[x][y] = (char *)ft_memalloc(sizeof(char) * d)))
				exit(1);
		}
	}
	return (map);
}
/*
static void	fill_map_bottom(t_ed_map *new)
{
	int		x;
	int		y;
	int		z;

	x = 0;
	y = new->height - 1;
	while (x < new->width)
	{
		
		x++;
	}
}*/

int			build_map(t_ed_map *new)
{
	if (!(new->map = init_map_matrice(new->width, new->heigth, new->depth)))
		return (-1);
//	fill_map_bottom(new->map);
	return (0);
}
