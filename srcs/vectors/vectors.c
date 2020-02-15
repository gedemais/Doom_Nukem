#include "main.h"

t_vec3d	vec_intersect_plane(t_vec3d plane_p, t_vec3d plane_n, t_vec3d s_e[2], float *tmp)
{
	float	plane_d;
	float	ad;
	float	bd;
	float	t;
	t_vec3d	l_s_end;
	t_vec3d	l_to_int;

	vec_normalize(&plane_n);

	plane_d = -vec_dot(plane_n, plane_p);
	ad = vec_dot(s_e[0], plane_n);
	bd = vec_dot(s_e[1], plane_n);

	t = (-plane_d - ad) / (bd - ad);
	*tmp = t;

	l_s_end = vec_sub(s_e[1], s_e[0]);
	l_to_int = vec_fmult(l_s_end, t);
	return (vec_add(s_e[0], l_to_int));
}

float	distance_to_plane(t_vec3d plane_n, t_vec3d plane_p, t_vec3d p)
{
	float	ret;

	vec_normalize(&plane_n);
	ret = plane_n.x * p.x + plane_n.y * p.y + plane_n.z * p.z;
	ret -= vec_dot(plane_n, plane_p);
	return (ret);
}
