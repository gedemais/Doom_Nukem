#include "main.h"

int             place_pivot(t_dynarray *arr, int low, int high)
{
    int     pivot;
    int     switch_i;
    int     i;

    pivot = low;
    i = low + 1;
    switch_i = low + 1;
    while (i < high - 1)
    {
        if (((t_node *)dyacc(arr, i))->globalgoal
            < ((t_node *)dyacc(arr, pivot))->globalgoal)
        {
            dynarray_swap_cells(arr, i, switch_i);
            dynarray_swap_cells(arr, pivot, switch_i);
            ++pivot;
            ++switch_i;
        }
        ++i;
    }
    return (pivot);
}

static void		quick_sort(t_dynarray *arr, int low, int high)
{
    int     pivot;

    if (low >= high)
        return;
    pivot = place_pivot(arr, low, high); 
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
}

void            astar_sort_dynarray(t_dynarray *arr)
{
    quick_sort(arr, 0, arr->nb_cells - 1);
}
