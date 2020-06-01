#include "main.h"

static int      astar_place_pivot(t_dynarray *arr, int low, int high)
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

static int      nodes_place_pivot(t_dynarray *arr, int low, int high)
{
    int     pivot;
    int     switch_i;
    int     i;

    pivot = low;
    i = low + 1;
    switch_i = low + 1;
    while (i < high - 1)
    {
        if (((t_node *)dyacc(arr, i))->i
            < ((t_node *)dyacc(arr, pivot))->i)
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

static void		quick_sort(t_dynarray *arr, int low, int high, bool astar)
{
    int     pivot;

    if (low >= high)
        return;
    if (astar)
        pivot = astar_place_pivot(arr, low, high);
    else
        pivot = nodes_place_pivot(arr, low, high);
    quick_sort(arr, low, pivot - 1, astar);
    quick_sort(arr, pivot + 1, high, astar);
}

void            bubble_sort(t_dynarray *arr)
{
    int     i;
    int     j;

    i = -1;
    while (++i < arr->nb_cells - 1)
    {
        j = -1;
        while (++j < arr->nb_cells - 1)
        {
            if (((t_node *)dyacc(arr, j))->i
                > ((t_node *)dyacc(arr, j + 1))->i)
            {
                dynarray_swap_cells(arr, j, j + 1);
            }
        }
    }
}

void            astar_sort_dynarray(t_dynarray *arr, bool astar)
{
    if (astar)
        quick_sort(arr, 0, arr->nb_cells - 1, astar);
    else
        bubble_sort(arr);
}
