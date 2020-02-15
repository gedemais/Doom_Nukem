#include "main.h"

void	init_projection_matrix(t_cam *cam)
{
	cam->p_m[0][0] = cam->stats.aspect_ratio * cam->stats.fovr;
	cam->p_m[1][1] = cam->stats.fovr;
	cam->p_m[2][2] = cam->stats.ffar / cam->stats.fdelta;
	cam->p_m[3][2] = (-cam->stats.ffar * cam->stats.fnear) / cam->stats.fdelta;
	cam->p_m[2][3] = 1.0f;
	cam->p_m[3][3] = 0.0f;
}

void	init_matrices(t_cam *cam)
{
	unsigned int	i;

	i = 0;
	while (i < 4)
	{
		ft_memset(&cam->p_m[i][0], 0, sizeof(float) * 4);
		ft_memset(&cam->rx_m[i][0], 0, sizeof(float) * 4);
		ft_memset(&cam->ry_m[i][0], 0, sizeof(float) * 4);
		ft_memset(&cam->rz_m[i][0], 0, sizeof(float) * 4);
		ft_memset(&cam->crx_m[i][0], 0, sizeof(float) * 4);
		ft_memset(&cam->cry_m[i][0], 0, sizeof(float) * 4);
		i++;
	}
	for (int i = 0; i < 4; i++){
		cam->p_m[i][i] = 1.0f;
		cam->rx_m[i][i] = 1.0f;
		cam->ry_m[i][i] = 1.0f;
		cam->rz_m[i][i] = 1.0f;
		cam->crx_m[i][i] = 1.0f;
		cam->cry_m[i][i] = 1.0f;
	};
	init_projection_matrix(cam);
}
