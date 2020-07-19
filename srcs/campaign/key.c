#include "main.h"

int		handle_key(t_env *env)
{
	t_mesh			*key;
	t_map			*map;

	map = &env->maps[env->cmp_env.sector];
	key = env->cmp_env.key[env->cmp_env.sector];
//	printf("at %f from key\n", vec3d_dist(env->cam.stats.pos, key->corp.pos));
	//translate_mesh(map, key, (t_vec3d){0.1f, 0, 0, 0});
	//rotate_mesh(key, key->corp.pos, theta, rotate_y);
	return (0);
}
