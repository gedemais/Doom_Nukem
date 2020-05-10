#include "dynarray.h"

int			pop_dynarray(t_dynarray *arr, bool front)
{
	int		len;

	len = (arr->nb_cells - 1) * arr->cell_size;
	if (front)
	{
		ft_memcpy(arr->tmp, (void*)(arr->c + arr->cell_size), len);
		ft_memcpy(arr->c, arr->tmp, len);
	}
	if (arr->nb_cells)
		arr->nb_cells--;
	else
		return (-1);
	return (0);
}

int			push_dynarray(t_dynarray *arr, void *src, bool front)
{
	int		len;

	len = arr->nb_cells * arr->cell_size;
	if (check_space(arr))
		return (-1);
	if (front)
	{
		ft_memcpy(arr->tmp, arr->c, len);
		ft_memcpy(arr->c, src, arr->cell_size);
		ft_memcpy((void*)(arr->c + arr->cell_size), arr->tmp, len);
	}
	else
		ft_memcpy((void*)(arr->c + len), src, arr->cell_size);
	return (0);
}

int			replace_dynarray_cell(t_dynarray *arr, void *src, int index)
{
	void	*ptr;

	if (index >= arr->nb_cells)
		return (-1);
	ptr = arr->c + (arr->cell_size * index);
	ft_memcpy(ptr, src, arr->cell_size);
	return (0);
}
