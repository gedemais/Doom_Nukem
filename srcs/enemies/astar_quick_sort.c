#include "main.h"

static int      astar_partition(t_dynarray *arr, int low, int high)
{
    int     i;
    int     j;
    float   pivot;
    t_node  *d;

    pivot = ((t_node *)dyacc(arr, high))->globalgoal;
    i = low - 1;
    j = low - 1;
    while (++j <= high)
    {
        d = dyacc(arr , j);
        if (d->globalgoal < pivot)
        {
            i++;
            dynarray_swap_cells(arr, i, j);
        }
    }
    dynarray_swap_cells(arr, i + 1, high);
    return (i + 1);
}

static int      nodes_partition(t_dynarray *arr, int low, int high)
{
    int     i;
    int     j;
    int     pivot;
    t_node  *d;

    pivot = ((t_node *)dyacc(arr, high))->i;
    i = low - 1;
    j = low - 1;
    while (++j <= high)
    {
        d = dyacc(arr , j);
        if (d->i < pivot)
        {
            i++;
            dynarray_swap_cells(arr, i, j);
        }
    }
    dynarray_swap_cells(arr, i + 1, high);
    return (i + 1);
}

void            quicksort(t_dynarray *arr, int low, int high, bool astar)
{
    int     pi;

    if (low < high)
    {
        if (astar)
            pi = astar_partition(arr, low, high);
        else
            pi = nodes_partition(arr, low, high);
        quicksort(arr, low, pi - 1, astar);
        quicksort(arr, pi + 1, high, astar);
    }
}

void            astar_sort_dynarray(t_dynarray *arr, bool astar)
{
    quicksort(arr, 0, arr->nb_cells - 1, astar);
}
