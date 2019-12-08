#include "dynarray.h"

int		pop_dynarray(t_dynarray *arr)
{
	ft_memcpy(arr->tmp, arr->c, arr->byte_size);
	free(arr->c);
	arr->byte_size -= arr->cell_size;
	arr->nb_cells--;
	if (!(arr->c = malloc(arr->byte_size)))
		return (-1);
	ft_memcpy(arr->c, (void*)(arr->tmp + arr->cell_size), arr->byte_size);
	return (0);
}

int		push_dynarray(t_dynarray *arr, void *src, bool front)
{
	ft_memcpy(arr->tmp, arr->c, arr->byte_size);
	free(arr->c);
	arr->byte_size += arr->cell_size;
	arr->nb_cells++;
	if (!(arr->c = malloc(arr->byte_size)))
		return (-1);
	if (front)
	{
		ft_memcpy(arr->c, src, arr->cell_size);
		ft_memcpy((void*)(arr->c + arr->cell_size), arr->tmp, arr->byte_size - arr->cell_size);
	}
	else
	{
		ft_memcpy(arr->c, arr->tmp, arr->byte_size - arr->cell_size);
		ft_memcpy((void*)(arr->c + arr->byte_size - arr->cell_size), src, arr->cell_size);
	}
	arr->t_byte_size += arr->cell_size;
	free(arr->tmp);
	if (!(arr->tmp = malloc(arr->t_byte_size)))
		return (-1);
	return (0);
}

void	*dyacc(t_dynarray *arr, int index)
{
	if (index > arr->nb_cells)
		return (NULL);
	return ((void*)(arr->c + index * arr->cell_size));
}

int		init_dynarray(t_dynarray *arr, int cell_size, int nb_cells)
{
	if (cell_size <= 0 || nb_cells <= 0)
		return (-1);
	arr->cell_size = cell_size;
	arr->nb_cells = nb_cells;
	arr->byte_size = cell_size * nb_cells;
	arr->t_byte_size = arr->byte_size;
	if (!(arr->c = malloc(arr->byte_size))
		|| !(arr->tmp = malloc(arr->byte_size)))
		return (-1);
	return (0);
}
