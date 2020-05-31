#include "main.h"

static void     nodes_neighbourgs_diagonals(t_pf *env, int x, int y, int z)
{
    t_node  ***nodes;

    nodes = env->nodes;
    // x && y
    if (x > 0 && y > 0) 
        nodes[x][y][z].nghbr[6] = &nodes[x - 1][y - 1][z];
    if (x < env->width - 1 && y < env->height - 1)
        nodes[x][y][z].nghbr[7] = &nodes[x + 1][y + 1][z];
    if (x < env->width - 1 && y > 0)
        nodes[x][y][z].nghbr[8] = &nodes[x + 1][y - 1][z];
    if (x > 0 && y < env->height - 1)
        nodes[x][y][z].nghbr[9] = &nodes[x - 1][y + 1][z];

    // x && z
    if (x > 0 && z > 0)
        nodes[x][y][z].nghbr[10] = &nodes[x - 1][y][z - 1];
    if (x < env->width - 1 && z < env->depth - 1)
        nodes[x][y][z].nghbr[11] = &nodes[x + 1][y][z + 1];
    if (x < env->width - 1 && z > 0)
        nodes[x][y][z].nghbr[12] = &nodes[x + 1][y][z - 1];
    if (x > 0 && z < env->depth - 1)
        nodes[x][y][z].nghbr[13] = &nodes[x - 1][y][z + 1];

    // y && z
    if (y > 0 && z > 0)
        nodes[x][y][z].nghbr[14] = &nodes[x][y - 1][z - 1];
    if (y < env->height - 1 && z < env->depth - 1)
        nodes[x][y][z].nghbr[15] = &nodes[x][y + 1][z + 1];
    if (y < env->height - 1 && z > 0)
        nodes[x][y][z].nghbr[16] = &nodes[x][y + 1][z - 1];
    if (y > 0 && z < env->depth - 1)
        nodes[x][y][z].nghbr[17] = &nodes[x][y - 1][z + 1];
}

static void     nodes_neighbours(t_pf *env, int x, int y, int z)
{
    int     i;
    t_node  ***nodes;

    nodes = env->nodes;
    i = -1;
    while (++i < NEIGHBOURG)
        nodes[x][y][z].nghbr[i] = NULL;
    if (x > 0)
        nodes[x][y][z].nghbr[0] = &nodes[x - 1][y][z];
    if (x < env->width - 1)
        nodes[x][y][z].nghbr[1] = &nodes[x + 1][y][z];
    if (y > 0)
        nodes[x][y][z].nghbr[2] = &nodes[x][y - 1][z];
    if (y < env->height - 1)
        nodes[x][y][z].nghbr[3] = &nodes[x][y + 1][z];
    if (z > 0)
        nodes[x][y][z].nghbr[4] = &nodes[x][y][z - 1];
    if (z < env->depth - 1)
        nodes[x][y][z].nghbr[5] = &nodes[x][y][z + 1];
    if (NEIGHBOURG > 6)
        nodes_neighbourgs_diagonals(env, x, y, z);
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
                env->nodes[x][y][z].pos.x = x;
                env->nodes[x][y][z].pos.y = y;
                env->nodes[x][y][z].pos.z = z;
                if (map.map[x][y][z])
                    env->nodes[x][y][z].bobstacle = 1;
                nodes_neighbours(env, x, y, z);
            }
        }
    }
    return (0);
}
