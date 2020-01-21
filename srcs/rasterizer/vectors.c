#include "main.h"

void		vec_swap(t_vec3d *a, t_vec3d *b)
{
	t_vec3d		t;

	t = *a;
	*a = *b;
	*b = t;
}

t_vec3d		vec_add(t_vec3d a, t_vec3d b)
{
	t_vec3d		ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}

t_vec3d		vec_sub(t_vec3d a, t_vec3d b)
{
	t_vec3d		ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}

t_vec3d		vec_fmult(t_vec3d a, float n)
{
	t_vec3d		ret;

	ret.x = a.x * n;
	ret.y = a.y * n;
	ret.z = a.z * n;
	return (ret);
}

t_vec3d		vec_cross(t_vec3d a, t_vec3d b)
{
	t_vec3d	ret;

	ret.x = (a.y * b.z) - (a.z * b.y);
	ret.y = (a.z * b.x) - (a.x * b.z);
	ret.z = (a.x * b.y) - (a.y * b.x);
	return (ret);
}

void	vec_normalize(t_vec3d *vec)
{
	float	l;

	l = sqrtf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	vec->x /= l;
	vec->y /= l;
	vec->z /= l;
}

float	vec_dot(t_vec3d a, t_vec3d b)
{
	float	ret;

	ret = 0.0f;
	ret += a.x * b.x;
	ret += a.y * b.y;
	ret += a.z * b.z;
	return (ret);
}

t_vec3d	vec_mult(t_vec3d a, t_vec3d b)
{
	t_vec3d		ret;

	ret.x = a.x * b.x;
	ret.y = a.y * b.y;
	ret.z = a.z * b.z;
	return (ret);
}

t_vec3d	vec_intersect_plane(t_vec3d plane_p, t_vec3d plane_n, t_vec3d l_start,
																t_vec3d l_end)
{
	float	plane_d;
	float	ad;
	float	bd;
	float	t;
	t_vec3d	l_s_end;
	t_vec3d	l_to_int;

	vec_normalize(&plane_n);

	plane_d = -vec_dot(plane_n, plane_p);
	ad = vec_dot(l_start, plane_n);
	bd = vec_dot(l_end, plane_n);

	t = (-plane_d - ad) / (bd - ad);

	l_s_end = vec_sub(l_end, l_start);
	l_to_int = vec_fmult(l_s_end, t);
	return (vec_add(l_start, l_to_int));
}

float	distance_to_plane(t_vec3d plane_n, t_vec3d plane_p, t_vec3d p)
{
	float	ret;

	vec_normalize(&plane_n);
	ret = plane_n.x * p.x + plane_n.y * p.y + plane_n.z * p.z;
	ret -= vec_dot(plane_n, plane_p);
	return (ret);
}

float	vec_sdist(t_vec3d o, t_vec3d v)
{
	float	ret;

	ret = 0.0f;
	ret += o.x * v.x;
	ret += o.y * v.y;
	ret += o.z * v.z;
	return (ret);
}
