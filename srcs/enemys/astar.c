#include "main.h"

static void     stock_neighbour(t_dynarray *arr, t_node *ngbhr)
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

static void     neighbour(t_pf *env, t_node **c, int i)
{
    float   plowergoal;
    t_node  *ngbhr;

    ngbhr = (*c)->ngbhr[i];
    if (ngbhr == NULL)
        return ;
    plowergoal = (*c)->localgoal + distance(**c, *ngbhr);
    if (plowergoal < ngbhr->localgoal)
    {
        ngbhr->parent = &env->nodes[(*c)->x][(*c)->y][(*c)->z];
        ngbhr->localgoal = plowergoal;
        ngbhr->globalgoal = ngbhr->localgoal + distance(*ngbhr, *env->end);
    }
    if (ngbhr->bvisited == 0 && ngbhr->bobstacle == 0)
        stock_neighbour(&env->d_astar, ngbhr);
    *c = env->d_astar.c;
}

static int      exit_astar(t_pf *env, t_node *current)
{
    return ((current->x == env->end->x
        && current->y == env->end->y
        && current->z == env->end->z)
        || env->d_astar.nb_cells < 1);
}

static void     solve_astar(t_pf *env, t_node *current)
{
    int     i;

    sort_dynarray(&env->d_astar);
    delvisited_nodes(&env->d_astar);
    current = env->d_astar.c;
    current->bvisited = 1;
    env->nodes[current->x][current->y][current->z].bvisited = 1;
    if (exit_astar(env, current))
        return ;
    i = -1;
    while (++i < NEIGHBOURG)
        neighbour(env, &current, i);
}

void            astar(t_pf *env)
{
    t_node  *current;

    resetdata(env);
    push_dynarray(&env->d_astar, env->start, 0);
    current = env->d_astar.c;
    current->localgoal = 0;
    current->globalgoal = distance(*env->start, *env->end);
    while (1)
        solve_astar(env, current);
}
