#include "main.h"

static void	init_projection_matrix(t_cam *cam)
{
	cam->p_m[0][0] = cam->aspect_ratio * cam->fovr;
	cam->p_m[1][1] = cam->fovr;
	cam->p_m[2][2] = cam->ffar / cam->fdelta;
	cam->p_m[3][2] = (-cam->ffar * cam->fnear) / cam->fdelta;
	cam->p_m[2][3] = 1.0f;
	cam->p_m[3][3] = 0.0f;
}

void	update_xrotation_matrix(float m[4][4], float theta)
{
	float	c;
	float	s;

	c = cosf(theta * 0.5f);
	s = sinf(theta * 0.5f);
	m[0][0] = 1.0f;
    m[1][1] = c;
    m[1][2] = -s;
    m[2][1] = s;
    m[2][2] = c;
    m[3][3] = 1.0f;
}

void	update_yrotation_matrix(float m[4][4], float theta)
{
	float	c;
	float	s;

	c = cosf(theta);
	s = sinf(theta);
	m[0][0] = c;
    m[0][2] = s;
    m[1][1] = 1.0f;
    m[2][0] = -s;
    m[2][2] = c;
    m[3][3] = 1.0f;
}

void	update_zrotation_matrix(float m[4][4], float theta)
{
	float	c;
	float	s;

	c = cosf(theta);
	s = sinf(theta);
	m[0][0] = c;
    m[0][1] = s;
    m[1][0] = -s;
    m[1][1] = c;
    m[2][2] = 1.0f;
    m[3][3] = 1.0f;
}

void	init_matrices(t_cam *cam)
{
	unsigned int	i;

	i = 0;
	while (i < 4)
	{
		ft_memset(&cam->p_m[0][0], 0, sizeof(float) * 4);
		ft_memset(&cam->rx_m[0][0], 0, sizeof(float) * 4);
		i++;
	}
	init_projection_matrix(cam);
}
