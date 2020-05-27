#include "main.h"

static void     astar_stock_neighbour(t_dynarray *arr, t_node *ngbhr)
{
    int     i;
    t_node  *d;

    i = -1;
    while (++i < arr->nb_cells)
    {
        d = dyacc(arr, i);
        if (d->x == ngbhr->x
            && d->y == ngbhr->y
            && d->z == ngbhr->z)
            return ;
    }
    push_dynarray(arr, ngbhr, 0);
}

static void     astar_neighbour(t_pf *env, t_node **c, int i)
{
    float   plowergoal;
    t_node  *ngbhr;

    ngbhr = (*c)->ngbhr[i];
    if (ngbhr == NULL)
        return ;
    plowergoal = (*c)->localgoal + astar_distance(**c, *ngbhr);
    if (plowergoal < ngbhr->localgoal)
    {
        ngbhr->parent = &env->nodes[(*c)->x][(*c)->y][(*c)->z];
        ngbhr->localgoal = plowergoal;
        ngbhr->globalgoal = ngbhr->localgoal
            + astar_distance(*ngbhr, *env->end);
    }
    if (ngbhr->bvisited == 0 && ngbhr->bobstacle == 0)
        astar_stock_neighbour(&env->d_astar, ngbhr);
    *c = env->d_astar.c;
}

static int      astar_exit(t_pf *env, t_node *current)
{
    return ((current->x == env->end->x
        && current->y == env->end->y
        && current->z == env->end->z)
        || env->d_astar.nb_cells < 1);
}

static void     astar_solve(t_pf *env, t_node **c)
{
    int     i;

    astar_sort_dynarray(&env->d_astar);
    astar_delvisited_nodes(&env->d_astar);
    *(c) = env->d_astar.c;
    *(c)->bvisited = 1;
    env->nodes[(*c)->x][(*c)->y][(*c)->z].bvisited = 1;
    if (astar_exit(env, *c))
        return ;
    i = -1;
    while (++i < NEIGHBOURG)
        astar_neighbour(env, c, i);
}

void            astar(t_pf *env)
{
    t_node  *current;

    astar_reset(env);
    push_dynarray(&env->d_astar, env->start, 0);
    current = env->d_astar.c;
    current->localgoal = 0;
    current->globalgoal = astar_distance(*env->start, *env->end);
    while (1)
        astar_solve(env, &current);
}
