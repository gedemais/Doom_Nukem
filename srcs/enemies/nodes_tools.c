#include "main.h"

t_node          *nodes_get_closest(t_pf *env, t_vec3d pos)
{
    float   dst;
    float   tmp;
    int     nb[3];
    t_node  *node;

    dst = INFINITY;
    nb[0] = -1;
    while (++nb[0] < env->width)
    {
        nb[1] = -1;
        while (++nb[1] < env->height)
        {
            nb[2] = -1;
            while (++nb[2] < env->depth)
            {
                tmp = astar_distance(pos, env->nodes[nb[0]][nb[1]][nb[2]].pos);
                if (tmp < dst)
                {
                    dst = tmp;
                    node = &env->nodes[nb[0]][nb[1]][nb[2]];
                }
            }
        }
    }
    return (node);
}

static int      nodes_free(t_pf *env)
{
    int i;
    int j;

    i = -1;
    while (env->nodes && ++i < env->width)
    {
        j = -1;
        while (env->nodes[i] && ++j < env->height)
            free(env->nodes[i][j]);
        free(env->nodes[i]);
    }
    free(env->nodes);
    return (-1);
}

int             nodes_init(t_pf *env)
{
    int     i;
    int     j;

    if (!(env->nodes = malloc(sizeof(t_node **) * (env->width))))   
        return (nodes_free(env));
    i = -1;
    while (++i < env->width)
    {
        if (!(env->nodes[i] = malloc(sizeof(t_node *) * env->height)))
            return (nodes_free(env));
        j = -1;
        while (++j < env->height)
            if (!(env->nodes[i][j] = malloc(sizeof(t_node) * env->depth)))
                return (nodes_free(env));
    }
    return (0);
}
