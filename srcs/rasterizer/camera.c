#include "main.h"

void	map_spawn(t_cam *cam, t_map *map)
{
	static t_map	*add = NULL;

	if (add != map)
	{
		cam->stats.pos = map->spawn;
		cam->stats.yaw = map->cam_dir.u;
		cam->stats.pitch = map->cam_dir.v;
		add = map;
	}
}

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

int		init_cameras_meshs(t_env *env, t_cam *cam)
{
	t_mesh		cam;
	int			i;

	i = 0;
	while (i < SCENE_MAX)
	{
		cam.corp.o = vec_sub(cam.corp.pos, vec_fdiv(cam.corp.dims, 2.0f))
		cam.corp.pos = env->maps[i].spawn;
		cam.corp.dims = (t_vec3d){1.0f, 2.0f, 1.0f, 1.0f};
		print_vec(cam.pos);
		i++;
	}
	return (0);
}

int		init_camera(t_env *env, t_cam *cam)
{
	cam->stats.aspect_ratio = (float)HGT / (float)WDT;
	cam->stats.fnear = 0.01f;
	cam->stats.ffar = 1000.0f;
	cam->stats.fovd = 70.0f;
	cam->stats.fovr = (float)(1.0f / tan(cam->stats.fovd * 0.5f / 180.0f * 3.14159f));
	cam->stats.fdelta = cam->stats.ffar - cam->stats.fnear;
	cam->stats.pos = (t_vec3d){0, 0, 0, 0};
	cam->stats.dir = (t_vec3d){10.0f, 40.0f, 0.0f, 0.0f};
	cam->stats.pitch = 0;
	cam->stats.yaw = 0;
	cam->light = (t_vec3d){0.0f, 2.0f, 0.0f, 0.0f};
	cam->light = vec_normalize(cam->light);
	init_matrices(cam);
	if (allocate_clipping_arrays(cam->clip_arrs)
		|| init_dynarray(&cam->to_clip, sizeof(t_triangle), MIN_TO_RASTER)
		|| init_dynarray(&cam->to_raster, sizeof(t_triangle), MIN_TO_RASTER)
		|| !(cam->z_buffer = (float*)malloc(sizeof(float) * (HGT * WDT))))
		return (-1);
	return (0);
}
