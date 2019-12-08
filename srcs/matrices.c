#include "main.h"

static void	flush_matrices(t_cam *cam)
{
	unsigned int	i;

	i = 0;
	while (i < 4)
	{
		ft_memset(&cam->p_m[0][0], 0, sizeof(float) * 4);
		ft_memset(&cam->rx_m[0][0], 0, sizeof(float) * 4);
		i++;
	}
}

static void	init_projection_matrix(t_cam *cam)
{
	cam->p_m[0][0] = cam->aspect_ratio * cam->fovr;
	cam->p_m[1][1] = cam->fovr;
	cam->p_m[2][2] = cam->ffar / cam->fdelta;
	cam->p_m[3][2] = (-cam->ffar * cam->fnear) / cam->fdelta;
	cam->p_m[2][3] = 1.0f;
	cam->p_m[3][3] = 0.0f;
}

void	update_xrotation_matrix(t_cam *cam, float theta)
{
	float	c;
	float	s;

	c = cosf(theta);
	s = sinf(theta);
	cam->rx_m[0][0] = 1.0f;
    cam->rx_m[1][1] = c;
    cam->rx_m[1][2] = -s;
    cam->rx_m[2][1] = s;
    cam->rx_m[2][2] = c;
    cam->rx_m[3][3] = 1.0f;
}

void	update_yrotation_matrix(t_cam *cam, float theta)
{
	float	c;
	float	s;

	c = cosf(theta);
	s = sinf(theta);
	cam->ry_m[0][0] = c;
    cam->ry_m[0][2] = s;
    cam->ry_m[1][1] = 1.0f;
    cam->ry_m[2][0] = -s;
    cam->ry_m[2][2] = c;
    cam->ry_m[3][3] = 1.0f;
}

void	update_zrotation_matrix(t_cam *cam, float theta)
{
	float	c;
	float	s;

	c = cosf(theta);
	s = sinf(theta);
	cam->rz_m[0][0] = c;
    cam->rz_m[0][1] = s;
    cam->rz_m[1][0] = -s;
    cam->rz_m[1][1] = c;
    cam->rz_m[2][2] = 1.0f;
    cam->rz_m[3][3] = 1.0f;
}

void	init_matrices(t_cam *cam)
{
	flush_matrices(cam);
	init_projection_matrix(cam);
}
