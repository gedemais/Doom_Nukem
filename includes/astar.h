#ifndef ASTAR_H
# define ASTAR_H

# define NEIGHBOURG 18

typedef union	u_rsqrt
{
	float		f;
	uint32_t	i;
}				t_rsqrt;

typedef struct  s_node
{
    int             bobstacle;
    int             bvisited;
    float           globalgoal;
    float           localgoal;
    t_vec3d         pos;
    struct s_node   *nghbr[NEIGHBOURG];
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

int             nodes_init(t_pf *env);
t_node          *nodes_get_closest(t_pf *a, t_vec3d pos);

float           astar_distance(t_vec3d a, t_vec3d b);
void            astar_delvisited_nodes(t_dynarray *arr);
void            astar_reset(t_pf *env);
void            astar_sort_dynarray(t_dynarray *arr);

#endif
