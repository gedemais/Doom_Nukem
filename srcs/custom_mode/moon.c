#include "main.h"

void			handle_moon(t_env *env)
{
	t_vec3d	map_center;
	t_mesh	*moon;

	map_center = (t_vec3d){ env->edit_env.new_map.width,
						env->edit_env.new_map.height,
						env->edit_env.new_map.depth, 0 };
	moon = env->custom_env.moon;
	env->cam.light = vec_fdiv(vec_normalize(moon->corp.pos), 2.0f);
	rotate_mesh(moon, map_center, 0.001f, rotate_y);
}
