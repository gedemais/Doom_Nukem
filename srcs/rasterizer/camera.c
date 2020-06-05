#include "main.h"

void	map_spawn(t_env *env, t_cam *cam, t_map *map, bool respawn)
{
	static t_map	*address = NULL;

	(void)env;
	if (address != map && !map->init)
	{
		map->init = true;
		cam->stats.pos = map->spawn;
		cam->stats.pos = vec_add(map->spawn, (t_vec3d){0, map->cam.corp.dims.y, 0, 0});
		map->cam.corp.pos = map->spawn;
		map->cam.corp.o = vec_sub(map->cam.corp.pos, vec_fdiv(map->cam.corp.dims, 2.0f));
		cam->stats.yaw = map->cam_dir.u;
		cam->stats.pitch = map->cam_dir.v;
	}
	else if (address != map)
	{
		cam->stats.pos = respawn ? map->spawn : map->cam.corp.pos;
		map->cam.corp.pos = respawn ? map->spawn : map->cam.corp.pos;
		map->cam.corp.o = vec_sub(map->cam.corp.pos, vec_fdiv(map->cam.corp.dims, 2.0f));
		cam->stats.yaw = respawn ? map->cam.yaw : cam->stats.yaw;
		cam->stats.pitch = respawn ? map->cam.pitch : cam->stats.pitch;
	}
	address = map;
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

void		print_first_mesh(t_env *env)
{
	t_mesh		*m;
	int			i;
	
	i = 0;
	while (i < SCENE_MAX)
	{
		m = dyacc(&env->maps[i].meshs, 0);
		printf("scene %d : mesh 0 : %d triangles\n", i, m->tris.nb_cells);
		i++;
	}
}

static int	init_cameras_meshs(t_env *env)
{
	t_mesh		*cam;
	int			i;

	i = 0;
	while (i < SCENE_MAX)
	{
		cam = &env->maps[i].cam;
		cam->yaw = env->maps[i].cam_dir.u;
		cam->pitch = env->maps[i].cam_dir.v;
		cam->corp.pos = env->maps[i].spawn;
		cam->corp.o = vec_sub(cam->corp.pos, vec_fdiv(cam->corp.dims, 2.0f));
		cam->corp.dims = (t_vec3d){2, 3.0f, 2, 1.0f};
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
	if (init_cameras_meshs(env) || allocate_clipping_arrays(cam->clip_arrs)
		|| init_dynarray(&cam->to_clip, sizeof(t_triangle), MIN_TO_RASTER)
		|| init_dynarray(&cam->to_raster, sizeof(t_triangle), MIN_TO_RASTER)
		|| !(cam->z_buffer = (float*)malloc(sizeof(float) * (HGT * WDT))))
		return (-1);
	return (0);
}
