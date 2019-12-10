#include "main.h"

void		matrix_m_matrix(float a[4][4], float b[4][4], float ret[4][4])
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)

		i++;
	}
}

t_vec3d		multiply_matrix(float m[4][4], t_vec3d o)
{
	t_vec3d			ret;
	float			w;

	ret.x = o.x * m[0][0] + o.y * m[1][0] + o.z * m[2][0] + m[3][0];
	ret.y = o.x * m[0][1] + o.y * m[1][1] + o.z * m[2][1] + m[3][1];
	ret.z = o.x * m[0][2] + o.y * m[1][2] + o.z * m[2][2] + m[3][2];
	w = o.x * m[0][3] + o.y * m[1][3] + o.z * m[2][3] + m[3][3];
	if (w != 0.0f)
	{
		ret.x /= w;
		ret.y /= w;
		ret.z /= w;
	}
	return (ret);
}
