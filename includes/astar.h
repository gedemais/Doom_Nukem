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
    t_dynarray  *d_astar;
    t_node      *start;
    t_node      *end;
    t_node      ***nodes;
}               t_pf;

#endif
