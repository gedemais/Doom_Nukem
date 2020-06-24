#include "main.h"

static void		tweek_stars_height(t_env *env, t_vec3d star, float *y)
{
	t_vec3d		middle;
	t_ed_map	*map;
	float		x;
	float		z;

	map = &env->edit_env.new_map;
	middle = (t_vec3d){map->width, map->height, map->depth, 0};

	x = star.x - middle.x;
	z = star.z - middle.z;
	x *= x;
	z *= z;
	*y -= 1 / astar_rsqrt(x + z) / 2;
}

static int		spawn_stars(t_env *env, t_vec3d o, t_vec3d box)
{
	t_vec3d		spawn;

	spawn.x = (rand() % (int)box.x) - o.x;
	spawn.y = (rand() % (int)box.y) - o.y;
	spawn.z = (rand() % (int)box.z) - o.z;
	tweek_stars_height(env, spawn, &spawn.y);
	return (copy_to_scene(&env->edit_env.map, &env->maps[SCENE_STAR], spawn));
}

static int		spawn_moon(t_env *env, t_vec3d o, t_vec3d box)
{
	t_vec3d	pos[4];
	float	s;
	int		p;

	s = 1.75f;
	p = rand() % 4;
	pos[0] = (t_vec3d){o.x / s, -box.y, o.z / s, 0};
	pos[1] = (t_vec3d){(o.x + box.x) / s, -box.y, o.z / s, 0};
	pos[2] = (t_vec3d){o.x / s, -box.y, (o.z + box.z) / s, 0};
	pos[3] = (t_vec3d){(o.x + box.x) / s, -box.y, (o.z + box.z) / s, 0};
	return (copy_to_scene(&env->edit_env.map, &env->maps[SCENE_MOON], pos[0]));
}

int				init_sky(t_env *env)
{
	int			i;
	int 		scale;
	t_vec3d		box;
	t_vec3d		o;
	t_ed_map	*map;

	map = &env->edit_env.new_map;
	scale = map->width > map->depth ? map->width : map->depth;
	scale = scale < STARS_SPREAD ? STARS_SPREAD : scale;
	o = (t_vec3d){scale * STARS_SPREAD, -map->height * 20,
		scale * STARS_SPREAD, 0};
	box = (t_vec3d){ scale * 2 + o.x * 2, -map->height * 22,
		scale * 2 + o.z * 2, 0};
	if (spawn_moon(env, o, box))
		return (-1);
	i = -1;
	while (++i < NB_STARS)
		if (spawn_stars(env, o, box))
			return (-1);
	return (0);
}
