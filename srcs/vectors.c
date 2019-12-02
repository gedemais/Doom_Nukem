#include "main.h"

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
