#include "main.h"

int             nodes_3d_1d(t_vec3d dim, t_vec3d pos)
{
    return ((pos.z * dim.x * dim.y) + (pos.y * dim.x) + pos.x);
}

t_node          *nodes_get_closest(t_dynarray *arr, t_vec3d pos)
{
    int     i;
    float   dst;
    float   tmp;
    t_node  *d;
    t_node  *node;

    node = NULL;
    dst = INFINITY;
    i = -1;
    while (++i < arr->nb_cells)
    {
        d = dyacc(arr, i);
        tmp = astar_distance(pos, d->pos);
        if (tmp < dst)
        {
            dst = tmp;
            node = dyacc(arr, i);
        }
    }
    return (node);
}
