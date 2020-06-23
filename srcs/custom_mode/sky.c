#include "main.h"

static void		tweek_y(t_env *env, t_vec3d star, float *y)
{
	t_vec3d		middle;
	t_ed_map	*map;

	map = &env->edit_env.new_map;
	middle = (t_vec3d){map->width, map->height, map->depth, 0};
	*y -= vec3d_dist(middle, star);
}

static void		spread_stars(t_env *env)
{
	t_ed_map	*map;
	t_vec3d		spawn;
	t_vec3d		box;
	t_vec3d		o;
	int			i;

	i = 0;
	map = &env->edit_env.new_map;
	o = (t_vec3d){map->width * STARS_SPREAD, -map->height * 20, map->depth * STARS_SPREAD, 0};
	box = (t_vec3d){map->width * 2 + o.x * 2, -map->height * 22, map->depth * 2 + o.z * 2, 0};
	while (i < NB_STARS)
	{
		spawn.x = (rand() % (int)box.x) - o.x;
		spawn.y = (rand() % (int)box.y) - o.y;
		spawn.z = (rand() % (int)box.z) - o.z;
		tweek_y(env, spawn, &spawn.y);
		copy_to_scene(&env->edit_env.map, &env->maps[SCENE_STAR], spawn);
		i++;
	}
}

int		init_sky(t_env *env)
{
	spread_stars(env);
	return (0);
}
