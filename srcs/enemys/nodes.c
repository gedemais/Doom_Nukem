#include "main.h"

static void     nodes_neighbours(t_pf *env, int x, int y, int z)
{
    ft_memset((void *)nodes[x][y][z].ngbhr, 0, sizeof(t_node *));
    if (x > 0)
        env->nodes[x][y][z].ngbhr[0] = &nodes[x - 1][y][z];
    if (x < env->width - 1)
        env->nodes[x][y][z].ngbhr[1] = &nodes[x + 1][y][z];
    if (y > 0)
        env->nodes[x][y][z].ngbhr[2] = &nodes[x][y - 1][z];
    if (y < env->height - 1)
        env->nodes[x][y][z].ngbhr[3] = &nodes[x][y + 1][z];
    if (z > 0)
        env->nodes[x][y][z].ngbhr[4] = &nodes[x][y][z - 1];
    if (z < env->depth - 1)
        env->nodes[x][y][z].ngbhr[5] = &nodes[x][y][z + 1];
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
        return (free_node(env));
    i = -1;
    while (++i < env->width)
    {
        if (!(env->nodes[i] = malloc(sizeof(t_node *) * env->height)))
            return (free_node(env));
        j = -1;
        while (++j < env->edit_env)
            if (!(env->nodes[i][j] = malloc(sizeof(t_node) * env->depth)))
                return (free_node(env));
    }   
}

int             astar_get_nodes(t_pf *env)
{
    int     x;
    int     y;
    int     z;

    if (nodes_init(&env->astar))
        return (-1);
    x = -1;
    while (++x < env->width)
    {
        y = -1;
        while (++y < env->height)
        {
            z = -1;
            while (++z < env->depth)
            {
                env->astar.nodes[x][y][z].x = x;
                env->astar.nodes[x][y][z].y = y;
                env->astar.nodes[x][y][z].z = z;
                nodes_neighbours(&env->astar, x, y, z);
            }
        }
    }
}
