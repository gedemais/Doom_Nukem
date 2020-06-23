#include "main.h"

static void		tweek_stars_height(t_env *env, t_vec3d star, float *y)
{
	t_vec3d		middle;
	t_ed_map	*map;

	map = &env->edit_env.new_map;
	middle = (t_vec3d){map->width, map->height, map->depth, 0};

	// tu peux pas faire un vec3d dist pcq ca prend en compte
	// le y et du coup ca augmente la dist pour R
	// spour ça que je t'ai dis de faire la dist entre 2 t_point
	*y -= vec3d_dist(middle, star);
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
	(void)env;
	(void)o;
	(void)box;
	return (0);
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
	o = (t_vec3d){ scale * STARS_SPREAD,
		-map->height * 20,
		scale * STARS_SPREAD, 0 };
	box = (t_vec3d){ scale * 2 + o.x * 2,
		-map->height * 22,
		scale * 2 + o.z * 2, 0 };
	if (spawn_moon(env, o, box))
		return (-1);
	i = -1;
	while (++i < NB_STARS)
		if (spawn_stars(env, o, box))
			return (-1);
	return (0);
}
