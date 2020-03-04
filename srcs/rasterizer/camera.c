#include "main.h"

int		allocate_clipping_arrays(t_dynarray arrays[4])
{
	unsigned int	i;

	i = 0;
	while (i < 4)
	{
		if (init_dynarray(&arrays[i], sizeof(t_triangle), MIN_TO_CLIP))
			return (-1);
		i++;
	}
	return (0);
}

int		init_camera(t_cam *cam)
{
	cam->stats.aspect_ratio = (float)HGT / (float)WDT;
	cam->stats.fnear = 0.1f;
	cam->stats.ffar = 1000.0f;
	cam->stats.fovd = 70.0f;
	cam->stats.fovr = (float)(1.0f / tan(cam->stats.fovd * 0.5f / 180.0f * 3.14159f));
	cam->stats.fdelta = cam->stats.ffar - cam->stats.fnear;
	cam->stats.pos = (t_vec3d){0.0f, 0.0f, 0.0f, 0.0f};
	cam->stats.dir = (t_vec3d){0.0f, 0.0f, 0.0f, 0.0f};
	cam->stats.pitch = 0;
	cam->stats.yaw = 0;
	cam->light = (t_vec3d){0.0f, 5.0f, -8.0f, 0.0f};
	cam->light = vec_normalize(cam->light);
	init_matrices(cam);
	if (allocate_clipping_arrays(cam->clip_arrs)
		|| init_dynarray(&cam->to_clip, sizeof(t_triangle), MIN_TO_RASTER)
		|| init_dynarray(&cam->to_raster, sizeof(t_triangle), MIN_TO_RASTER)
		|| !(cam->z_buffer = (float*)malloc(sizeof(float) * (HGT * WDT))))
		return (-1);
	return (0);
}
