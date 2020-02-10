#include "main.h"
/*
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
}*/

t_vec3d		multiply_matrix(float m[4][4], t_vec3d o)
{
	t_vec3d			ret;

	ret.x = o.x * m[0][0] + o.y * m[1][0] + o.z * m[2][0] + m[3][0];
	ret.y = o.x * m[0][1] + o.y * m[1][1] + o.z * m[2][1] + m[3][1];
	ret.z = o.x * m[0][2] + o.y * m[1][2] + o.z * m[2][2] + m[3][2];
	ret.w = o.x * m[0][3] + o.y * m[1][3] + o.z * m[2][3] + m[3][3];
	if (ret.w != 0.0f)
	{
		ret.x /= ret.w;
		ret.y /= ret.w;
		ret.z /= ret.w;
	}
	return (ret);
}

void	translation_matrix(float m[4][4], t_vec3d v)
{
	m[0][0] = 1.0f;
	m[1][1] = 1.0f;
	m[2][2] = 1.0f;
	m[3][3] = 1.0f;
	m[3][0] = v.x;
	m[3][1] = v.y;
	m[3][2] = v.z;
}

void	matrix_pointat(float m[4][4], t_vec3d pos, t_vec3d target, t_vec3d up)
{
	t_vec3d		new_f;
	t_vec3d		new_up;
	t_vec3d		new_r;
	t_vec3d		t;

	new_f = vec_sub(target, pos);
	vec_normalize(&new_f);

	t = vec_fmult(new_f, vec_dot(up, new_f));
	new_up = vec_sub(up, t);

	new_r = vec_cross(new_up, new_f);

	m[0][0] = new_r.x;
	m[0][1] = new_r.y;
	m[0][2] = new_r.z;
	m[0][3] = -vec_dot(new_r, pos);
	m[1][0] = new_up.x;
	m[1][1] = new_up.y;
	m[1][2] = new_up.z;
	m[1][3] = -vec_dot(new_up, pos);
	m[2][0] = new_f.x;
	m[2][1] = new_f.y;
	m[2][2] = new_f.z;
	m[2][3] = -vec_dot(new_f, pos);
	m[3][0] = pos.x;
	m[3][1] = pos.y;
	m[3][2] = pos.z;
	m[3][3] = 1;
}

void	inverse_matrix(float m[4][4], float ret[4][4]) // Only for Rotation/Translation Matrices
{
	ret[0][0] = m[0][0];
	ret[0][1] = m[1][0];
	ret[0][2] = m[2][0];
	ret[0][3] = 0.0f;
	ret[1][0] = m[0][1];
	ret[1][1] = m[1][1];
	ret[1][2] = m[2][1];
	ret[1][3] = 0.0f;
	ret[2][0] = m[0][2];
	ret[2][1] = m[1][2];
	ret[2][2] = m[2][2];
	ret[2][3] = 0.0f;
	ret[3][0] = -(m[3][0] * ret[0][0] + m[3][1] * ret[1][0]
		+ m[3][2] * ret[2][0]);
	ret[3][1] = -(m[3][0] * ret[0][1] + m[3][1] * ret[1][1]
		+ m[3][2] * ret[2][1]);
	ret[3][2] = -(m[3][0] * ret[0][2] + m[3][1] * ret[1][2]
		+ m[3][2] * ret[2][2]);
	ret[3][3] = 1.0f;
}

void	matrix_mult_matrix(float m1[4][4], float m2[4][4], float ret[4][4])
{
	unsigned int	c;
	unsigned int	r;

	c = 0;
	while (c < 4)
	{
		r = 0;
		while (r < 4)
		{
			ret[r][c] = m1[r][0] * m2[0][c] + m1[r][1] * m2[1][c] + m1[r][2] * m2[2][c] + m1[r][3] * m2[3][c];
			r++;
		}
		c++;
	}
}

t_vec3d matrix_mult_vec(float m[4][4], t_vec3d i)
{
	t_vec3d v;

	v.x = i.x * m[0][0] + i.y * m[1][0] + i.z * m[2][0] + i.w * m[3][0];
	v.y = i.x * m[0][1] + i.y * m[1][1] + i.z * m[2][1] + i.w * m[3][1];
	v.z = i.x * m[0][2] + i.y * m[1][2] + i.z * m[2][2] + i.w * m[3][2];
	v.w = i.x * m[0][3] + i.y * m[1][3] + i.z * m[2][3] + i.w * m[3][3];
	return (v);
}
