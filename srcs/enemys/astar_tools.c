#include "main.h"

void            astar_delvisited_nodes(t_dynarray *arr)
{
    int     i;
    t_node  *d;

    i = -1;
    while (++i < arr->nb_cells)
    {
        d = dyacc(arr, i);
        if (d->bvisited)
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

void            quick_sort(t_dynarray *data, int left, int right)
{
    int     left_index;
    int     right_index;
    float   pivot;

    left_index = left;
    right_index = right;
    pivot = ((t_node *)dyacc(data, (left + right) / 2))->globalgoal;
    while (left_index <= right_index)
    {
        while (((t_node *)dyacc(data, left_index))->globalgoal < pivot)
            ++left_index;
        while (((t_node *)dyacc(data, right_index))->globalgoal > pivot)
            --right_index;
        if (left_index <= right_index)
            dynarray_swap_cells(data, left_index++, right_index--);
    }
    if (right_index > left)
        quick_sort(data, left, right_index);
    if (left_index < right)
        quick_sort(data, left_index, right);
}

void            bubble_sort(t_dynarray *arr)
{
    int     i;
    int     j;
    t_node  *d1;
    t_node  *d2;

    i = -1;
    while (++i < arr->nb_cells - 1)
    {
        j = -1;
        while (++j < arr->nb_cells - 1)
        {
            d1 = dyacc(arr, j);
            d2 = dyacc(arr, j + 1);
            if (d1->globalgoal > d2->globalgoal)
                dynarray_swap_cells(arr, j, j + 1);
        }
    }
}

void            astar_sort_dynarray(t_dynarray *arr)
{
    //bubble_sort(arr);
    quick_sort(arr, 0, arr->nb_cells - 1);
}
