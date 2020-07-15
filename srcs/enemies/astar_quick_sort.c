#include "main.h"

int
	astar_compare(void *a, void *b)
{
	return (((t_node *)a)->globalgoal < ((t_node *)b)->globalgoal);
}

int
	nodes_compare(void *a, void *b)
{
	return (((t_node *)a)->i < ((t_node *)b)->i);
}

static int
	partition(t_dynarray *arr, int low, int high,
			int (*compare)(void *a, void *b))
{
	int		i;
	int		j;
	void	*pivot;

	pivot = dyacc(arr, high);
	i = low - 1;
	j = low - 1;
	while (++j <= high)
	{
		if (compare(dyacc(arr, j), pivot))
			dynarray_swap_cells(arr, ++i, j);
	}
	dynarray_swap_cells(arr, i + 1, high);
	return (i + 1);
}

static void
	quicksort(t_dynarray *arr, int low, int high,
			int (*compare)(void *a, void *b))
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high, compare);
		quicksort(arr, low, pivot - 1, compare);
		quicksort(arr, pivot + 1, high, compare);
	}
}

void
	astar_sort_dynarray(t_dynarray *arr,
			int (*compare)(void *a, void *b))
{
	quicksort(arr, 0, arr->nb_cells - 1, compare);
}
