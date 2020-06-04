#include "main.h"

int             astar_compare(void *a, void *b)
{
    t_node  *n1;
    t_node  *n2;

    n1 = (t_node *)a;
    n2 = (t_node *)b;
    return (n1->globalgoal < n2->globalgoal);
}

int             nodes_compare(void *a, void *b)
{
    t_node  *n1;
    t_node  *n2;

    n1 = (t_node *)a;
    n2 = (t_node *)b;
    return (n1->i < n2->i);
}

static int      partition(t_dynarray *arr, int low, int high,
                    int (*compare)(void *a, void *b))
{
    int     i;
    int     j;
    void    *pivot;

    pivot = ((t_node *)dyacc(arr, high));
    i = low - 1;
    j = low - 1;
    while (++j <= high)
    {
        if (compare(dyacc(arr , j), pivot))
        {
            i++;
            dynarray_swap_cells(arr, i, j);
        }
    }
    dynarray_swap_cells(arr, i + 1, high);
    return (i + 1);
}

void            quicksort(t_dynarray *arr, int low, int high,
                    int (*compare)(void *a, void *b))
{
    int     pivot;

    if (low < high)
    {
        pivot = partition(arr, low, high, compare);
        quicksort(arr, low, pivot - 1, compare);
        quicksort(arr, pivot + 1, high, compare);
    }
}

void            astar_sort_dynarray(t_dynarray *arr,
                    int (*compare)(void *a, void *b))
{
    quicksort(arr, 0, arr->nb_cells - 1, compare);
}
