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
