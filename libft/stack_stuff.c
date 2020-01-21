#include "dynarray.h"

int		realloc_content(t_dynarray *arr)
{
	void	*tmp;
	int		prev_size;

	prev_size = arr->byte_size;
	arr->byte_size *= 2;
	if (!(tmp = malloc(arr->byte_size))
		|| !(arr->tmp = malloc(arr->byte_size)))
		return (-1);
	ft_memcpy(tmp, arr->c, prev_size);
	free(arr->c);
	arr->c = tmp;
	return (0);
}

int		pop_dynarray(t_dynarray *arr, bool front)
{
	(void)arr;
	(void)front;
	return (0);
}

int		push_dynarray(t_dynarray *arr, void *src, bool front)
{
	if ((++arr->nb_cells) * arr->cell_size > arr->byte_size)
		while (arr->nb_cells * arr->cell_size > arr->byte_size)
			if (realloc_content(arr))
				return (-1);
	if (front)
	{
		ft_memcpy(arr->tmp, arr->c, arr->byte_size);
		ft_memcpy(arr->c, src, arr->cell_size);
		ft_memcpy((void*)(arr->c + arr->cell_size), arr->tmp, arr->byte_size);
	}
	else
		ft_memcpy((void*)(arr->c + arr->nb_cells * arr->cell_size), src, arr->cell_size);
	arr->byte_size += arr->cell_size;
	return (0);
}
