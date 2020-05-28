#include "main.h"

void            astar_delvisited_nodes(t_dynarray *arr)
{
    int     i;

    i = -1;
    while (++i < arr->nb_cells)
    {
        if (((t_node *)dyacc(arr, i))->bvisited)
            extract_dynarray(arr, i);
    }
}

static float	astar_rsqrt(float number)
{
	float	i;
	float	threehalfs;
	t_rsqrt	conv;

	i = number * 0.5f;
	threehalfs = 1.5f;
	conv = (t_rsqrt){ number };
	conv.i = 0x5f3759df - (conv.i >> 1);
	conv.f *= (threehalfs - (i * conv.f * conv.f));
	return (conv.f);
}

float           astar_distance(t_node a, t_node b)
{
    return (1 / astar_rsqrt((a.x - b.x) * (a.x - b.x)
        + (a.y - b.y) * (a.y - b.y)));
}

void            astar_reset(t_pf *env)
{
    int x;
    int y;
    int z;

    x = -1;
    while (++x < env->width)
    {
        y = -1;
        while (++y < env->height)
        {
            z = -1;
            while (++z < env->depth)
            {
                env->nodes[x][y][z].bvisited = 0;
                env->nodes[x][y][z].globalgoal = INFINITY;
                env->nodes[x][y][z].localgoal = INFINITY;
                env->nodes[x][y][z].parent = NULL;
            }
        }
    }
    clear_dynarray(&env->d_astar);
}

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

void            quick_sort(t_dynarray *arr, int low, int high)
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
