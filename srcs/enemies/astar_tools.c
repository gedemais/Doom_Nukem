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

float           astar_distance(t_vec3d a, t_vec3d b)
{
    return (1 / astar_rsqrt((a.x - b.x) * (a.x - b.x)
        + (a.y - b.y) * (a.y - b.y)
        + (a.z - b.z) * (a.z - b.z)));
}

void            astar_reset(t_pf *env)
{
    int     i;
    t_node  *node;

    i = -1;
    while (++i < env->d_nodes.nb_cells)
    {
        node = dyacc(&env->d_nodes, i);
        node->bvisited = 0;
        node->globalgoal = INFINITY;
        node->localgoal = INFINITY;
        node->parent = NULL;
    }
    clear_dynarray(&env->d_astar);
}
