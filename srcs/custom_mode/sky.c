#include "main.h"

static void		spread_stars(t_env *env)
{
	t_ed_map	*map;
	t_vec3d		spawn;
	t_vec3d		box;
	t_vec3d		o;
	int			i;

	i = 0;
	map = &env->edit_env.new_map;
	o = (t_vec3d){};
	box = (t_vec3d){};
	while (i < NB_STARS)
	{
		spawn.x = (rand() % (int)box.x) - o.x;
		spawn.y = (rand() % (int)box.y) - o.y;
		spawn.z = (rand() % (int)box.z) - o.z;
		copy_to_scene(&env->edit_env.map, &env->maps[SCENE_STAR], spawn);
		i++;
	}
}

int		init_sky(t_env *env)
{
	spread_stars(env);
	return (0);
}
