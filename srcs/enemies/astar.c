#include "main.h"

static void     astar_stock_neighbour(t_dynarray *arr, t_node *ngbhr)
{
    int     i;

    i = -1;
    while (++i < arr->nb_cells)
    {
        if (((t_node *)dyacc(arr, i))->i == ngbhr->i)
            return ;
    }
    push_dynarray(arr, ngbhr, 0);
}

static void     astar_neighbour(t_pf *env, t_node **c, int i)
{
    float   plowergoal;
    t_node  *nghbr;

    nghbr = dyacc(&env->d_nodes, (*c)->nghbr[i]);
    if (nghbr == NULL)
        return ;
    plowergoal = (*c)->localgoal + vec3d_dist((*c)->pos, nghbr->pos);
    if (plowergoal < nghbr->localgoal)
    {
        nghbr->localgoal = plowergoal;
        nghbr->globalgoal = nghbr->localgoal
            + vec3d_dist(nghbr->pos, env->end->pos);
        nghbr->parent = dyacc(&env->d_nodes, (*c)->i);
    }
    if (nghbr->bvisited == 0 && nghbr->bobstacle == 0)
        astar_stock_neighbour(&env->d_astar, nghbr);
    *c = env->d_astar.c;
}

static bool     astar_exit(t_pf *env, t_node *current)
{
    if (vec3d_dist(env->start->pos, current->pos) > ASTAR_MAX_DIST)
    {
        env->end = NULL;
        return (true);
    }
    return (current->i == env->end->i
        || env->d_astar.nb_cells < 1);
}

static int      astar_solve(t_pf *env, t_node *c)
{
    int     i;

    astar_sort_dynarray(&env->d_astar, astar_compare);
    astar_delvisited_nodes(&env->d_astar);
    c = env->d_astar.c;
    c->bvisited = 1;
    ((t_node *)dyacc(&env->d_nodes, c->i))->bvisited = 1;
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

    if (env->start == NULL || env->end == NULL)
        return ;
    astar_reset(env);
    push_dynarray(&env->d_astar, env->start, 0);
    current = env->d_astar.c;
    if (current == NULL)
        return ;
    current->localgoal = 0;
    current->globalgoal = vec3d_dist(env->start->pos, env->end->pos);
    while (astar_solve(env, current) == 0)
        ;
}
