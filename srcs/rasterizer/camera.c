#include "main.h"

int		init_camera(t_cam *cam)
{
	cam->aspect_ratio = (float)HGT / (float)WDT;
	cam->fnear = 0.1f;
	cam->ffar = 1000.0f;
	cam->fovd = 90.0f;
	cam->fovr = (float)(1.0f / tanf(cam->fovd * 0.5f / 180.0f * 3.14159f));
	cam->fdelta = cam->ffar - cam->fnear;
	cam->pos = (t_vec3d){0.0f, 3.0f, 0.0f, 0.0};
	init_matrices(cam);
	if (!(cam->z_buffer = (float*)malloc(sizeof(float) * HGT * WDT)))
		return (-1);
	return (0);
}
