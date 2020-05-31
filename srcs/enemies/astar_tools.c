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
