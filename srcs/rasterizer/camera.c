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
	cam->aspect_ratio = (float)HGT / (float)WDT;
	cam->fnear = 0.1f;
	cam->ffar = 1000.0f;
	cam->fovd = 70.0f;
	cam->fovr = (float)(1.0f / tan(cam->fovd * 0.5f / 180.0f * 3.14159f));
	cam->fdelta = cam->ffar - cam->fnear;
	cam->pos = (t_vec3d){4.925508, 6.739945, -16.410669, 0.0f};
	cam->light = (t_vec3d){5.0f, 8.0f, 8.0f, 0.0f};
	vec_normalize(&cam->light);
	init_matrices(cam);
	if (allocate_clipping_arrays(cam->clip_arrs)
		|| init_dynarray(&cam->to_clip, sizeof(t_triangle), MIN_TO_RASTER)
		|| init_dynarray(&cam->to_raster, sizeof(t_triangle), MIN_TO_RASTER)
		|| !(cam->z_buffer = (float*)malloc(sizeof(float) * (HGT * WDT))))
		return (-1);
	return (0);
}
