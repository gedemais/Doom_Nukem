#include "main.h"

static void     astar_stock_neighbour(t_dynarray *arr, t_node *ngbhr)
{
    int     i;
    t_node  *d;

    i = -1;
    while (++i < arr->nb_cells)
    {
        d = dyacc(arr, i);
        if (d->pos.x == ngbhr->pos.x
            && d->pos.y == ngbhr->pos.y
            && d->pos.z == ngbhr->pos.z)
            return ;
    }
    push_dynarray(arr, ngbhr, 0);
}

static void     astar_neighbour(t_pf *env, t_node **c, int i)
{
    float   plowergoal;
    t_node  *nghbr;

    nghbr = (*c)->nghbr[i];
    if (nghbr == NULL)
        return ;
    plowergoal = (*c)->localgoal + astar_distance((*c)->pos, nghbr->pos);
    if (plowergoal < nghbr->localgoal)
    {
        nghbr->parent
            = &env->nodes[(int)(*c)->pos.x][(int)(*c)->pos.y][(int)(*c)->pos.z];
        nghbr->localgoal = plowergoal;
        nghbr->globalgoal = nghbr->localgoal
            + astar_distance(nghbr->pos, env->end->pos);
    }
    if (nghbr->bvisited == 0 && nghbr->bobstacle == 0)
        astar_stock_neighbour(&env->d_astar, nghbr);
    *c = env->d_astar.c;
}

static int      astar_exit(t_pf *env, t_node *current)
{
    return ((current->pos.x == env->end->pos.x
        && current->pos.y == env->end->pos.y
        && current->pos.z == env->end->pos.z)
        || env->d_astar.nb_cells < 1);
}

static int      astar_solve(t_pf *env, t_node *c)
{
    int     i;

    astar_sort_dynarray(&env->d_astar);
    astar_delvisited_nodes(&env->d_astar);
    c = env->d_astar.c;
    c->bvisited = 1;
    env->nodes[(int)c->pos.x][(int)c->pos.y][(int)c->pos.z].bvisited = 1;
    if (astar_exit(env, c))
        return (1);
    i = -1;
    while (++i < NEIGHBOURG)
        astar_neighbour(env, &c, i);
    return (0);
}

void            astar(t_pf *env)
{
    t_node  *current;

    astar_reset(env);
    push_dynarray(&env->d_astar, env->start, 0);
    current = env->d_astar.c;
    current->localgoal = 0;
    current->globalgoal = astar_distance(env->start->pos, env->end->pos);
    while (astar_solve(env, current) == 0)
        ;
}
