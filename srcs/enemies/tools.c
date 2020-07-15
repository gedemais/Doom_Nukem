#include "main.h"

float           xz_angle(t_vec3d a, t_vec3d b)
{
    float   cross;
    float   dot;

    cross = a.x * b.z - a.z * b.x;
    dot = a.x * b.x + a.z * b.z;
    return (atan2(cross, dot));
}

int             nodes_3d_1d(t_vec3d dim, t_vec3d pos)
{
    return ((pos.z * dim.x * dim.y) + (pos.y * dim.x) + pos.x);
}

void            assign_meshs(t_mesh *m)
{
	t_triangle	*t;
	int			i;

	if (!m)
		return ;
	i = 0;
	while (i < m->tris.nb_cells)
	{
		t = dyacc(&m->tris, i);
		t->mesh = m;
		i++;
	}
}

