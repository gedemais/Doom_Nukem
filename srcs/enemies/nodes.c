#include "main.h"

static void     nodes_neighbours(t_pf *env, int x, int y, int z)
{
    int     i;
    t_node  ***nodes;

    nodes = env->nodes;
    i = -1;
    while (++i < NEIGHBOURG)
        nodes[x][y][z].ngbhr[i] = NULL;
    if (x > 0)
        nodes[x][y][z].ngbhr[0] = &nodes[x - 1][y][z];
    if (x < env->width - 1)
        nodes[x][y][z].ngbhr[1] = &nodes[x + 1][y][z];
    if (y > 0)
        nodes[x][y][z].ngbhr[2] = &nodes[x][y - 1][z];
    if (y < env->height - 1)
        nodes[x][y][z].ngbhr[3] = &nodes[x][y + 1][z];
    if (z > 0)
        nodes[x][y][z].ngbhr[4] = &nodes[x][y][z - 1];
    if (z < env->depth - 1)
        nodes[x][y][z].ngbhr[5] = &nodes[x][y][z + 1];
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

static int      nodes_init(t_pf *env)
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

int             astar_get_custom_nodes(t_ed_map map, t_pf *env)
{
    int     x;
    int     y;
    int     z;

    if (nodes_init(env))
        return (-1);
    x = -1;
    while (++x < map.width)
    {
        y = -1;
        while (++y < map.height)
        {
            z = -1;
            while (++z < map.depth)
            {
                env->nodes[x][y][z].x = x;
                env->nodes[x][y][z].y = y;
                env->nodes[x][y][z].z = z;
                if (map.map[x][y][z])
                    env->nodes[x][y][z].bobstacle = 1;
                nodes_neighbours(env, x, y, z);
            }
        }
    }
    return (0);
}
