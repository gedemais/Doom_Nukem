#include "dynarray.h"

void	*dyacc(t_dynarray *arr, int index)
{
	if (index >= arr->nb_cells || index < 0)
		return (NULL);
	return ((void*)(arr->c + (index * arr->cell_size)));
}

void	free_dynarray(t_dynarray *arr)
{
	if (arr->byte_size > 0)
		free(arr->c);
	if (arr->t_byte_size > 0)
		free(arr->tmp);
	arr->byte_size = 0;
	arr->t_byte_size = 0;
	arr->cell_size = 0;
	arr->nb_cells = 0;
	arr->c = NULL;
	arr->tmp = NULL;
}

int		init_dynarray(t_dynarray *arr, int cell_size, int nb_cells)
{
	if (cell_size <= 0 || nb_cells < 0)
		return (-1);
	arr->cell_size = cell_size;
	arr->nb_cells = nb_cells;
	arr->byte_size = cell_size * nb_cells;
	arr->t_byte_size = arr->byte_size;
	if (nb_cells == 0)
	{
		arr->c = NULL;
		arr->tmp = NULL;
		return (0);
	}
	if (!(arr->c = malloc(arr->byte_size))
		|| !(arr->tmp = malloc(arr->byte_size)))
		return (-1);
	ft_memset(arr->c, 0, arr->byte_size);
	ft_memset(arr->tmp, 0, arr->t_byte_size);
	return (0);
}
