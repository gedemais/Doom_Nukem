#include "main.h"

void	init_camera(t_cam *cam)
{
	cam->aspect_ratio = (float)HGT / (float)WDT;
	cam->fnear = 0.1f;
	cam->ffar = 1000.0f;
	cam->fovd = 90.0f;
	cam->fovr = (float)(1.0f / tanf(cam->fovd * 0.5f / 180.0f * (float)M_PI));
	cam->fdelta = cam->ffar - cam->fnear;
	cam->pos = (t_vec3d){0.0f, 0.0f, 0.0f};
	init_matrices(cam);
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
