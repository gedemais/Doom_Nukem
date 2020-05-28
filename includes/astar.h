#ifndef ASTAR_H
# define ASTAR_H

# define NEIGHBOURG 6

typedef union	u_rsqrt
{
	float		f;
	uint32_t	i;
}				t_rsqrt;

typedef struct  s_node
{
    int             bobstacle;
    int             bvisited;
    int             i;
    int             x;
    int             y;
    int             z;
    float           globalgoal;
    float           localgoal;
    struct s_node   *ngbhr[NEIGHBOURG];
    struct s_node   *parent;
}               t_node;

typedef struct  s_pathfinding
{
    int         width;
    int         height;
    int         depth;
    t_dynarray  d_astar;
    t_node      *start;
    t_node      *end;
    t_node      ***nodes;
}               t_pf;

void            astar(t_pf *env);

int             astar_get_custom_nodes(t_ed_map map, t_pf *env);

float           astar_distance(t_node a, t_node b);
void            astar_delvisited_nodes(t_dynarray *arr);
void            astar_reset(t_pf *env);
void            astar_sort_dynarray(t_dynarray *arr);

#endif
