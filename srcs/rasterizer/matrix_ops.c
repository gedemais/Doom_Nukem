#include "main.h"

void		translate_matrix(float m[4][4], t_vec3d p)
{
	m[0][0] = 1.0f;
	m[1][1] = 1.0f;
	m[2][2] = 1.0f;
	m[3][3] = 1.0f;
	m[3][0] = p.x;
	m[3][1] = p.y;
	m[3][2] = p.z;
}

void		matrix_m_matrix(float a[4][4], float b[4][4], float ret[4][4])
{
	unsigned int	r;
	unsigned int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			ret[r][c] = a[r][0] * b[0][c] + a[r][1] * b[1][c] + a[r][2] * b[2][c] + a[r][3] * b[3][c];
			c++;
		}
		r++;
	}
}

void		matrix_point_at(float m[4][4], t_vec3d pos, t_vec3d target, t_vec3d up)
{
	t_vec3d		new_f;
	t_vec3d		new_u;
	t_vec3d		new_r;
	t_vec3d		t;

	new_f = vec_sub(target, pos);
	vec_normalize(&new_f);

	t = vec_fmult(new_f, vec_dot(up, new_f));
	new_u = vec_sub(up, t);
	vec_normalize(&new_u);

	new_r = vec_cross(new_u, new_f);
	m[0][0] = new_r.x;
	m[1][0] = new_u.x;
	m[2][0] = new_f.x;
	m[3][0] = pos.x;

	m[0][1] = new_r.y;
	m[1][1] = new_u.y;
	m[2][1] = new_f.y;
	m[3][1] = pos.y;

	m[0][1] = new_r.z;
	m[1][1] = new_u.z;
	m[2][1] = new_f.z;
	m[3][1] = pos.z;

	m[0][3] = 0.0f;
	m[1][3] = 0.0f;
	m[2][3] = 0.0f;
	m[3][3] = 1.0f;
}

void		quick_inverse_matrix(float m[4][4], float ret[4][4])
{
	ret[0][0] = m[0][0]; ret[0][1] = m[1][0]; ret[0][2] = m[2][0]; ret[0][3] = 0.0f;
	ret[1][0] = m[0][1]; ret[1][1] = m[1][1]; ret[1][2] = m[2][1]; ret[1][3] = 0.0f;
	ret[2][0] = m[0][2]; ret[2][1] = m[1][2]; ret[2][2] = m[2][2]; ret[2][3] = 0.0f;
	ret[3][0] = -(m[3][0] * ret[0][0] + m[3][1] * ret[1][0] + m[3][2] * ret[2][0]);
	ret[3][1] = -(m[3][0] * ret[0][1] + m[3][1] * ret[1][1] + m[3][2] * ret[2][1]);
	ret[3][2] = -(m[3][0] * ret[0][2] + m[3][1] * ret[1][2] + m[3][2] * ret[2][2]);
	ret[3][3] = 1.0f;
}

t_vec3d		multiply_matrix(float m[4][4], t_vec3d o)
{
	t_vec3d			ret;

	ret.x = o.x * m[0][0] + o.y * m[1][0] + o.z * m[2][0] + o.w * m[3][0];
	ret.y = o.x * m[0][1] + o.y * m[1][1] + o.z * m[2][1] + o.w * m[3][1];
	ret.z = o.x * m[0][2] + o.y * m[1][2] + o.z * m[2][2] + o.w * m[3][2];
	ret.w = o.x * m[0][3] + o.y * m[1][3] + o.z * m[2][3] + o.w * m[3][3];
	return (ret);
}
