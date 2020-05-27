#include "main.h"

int		handle_enemys(t_env *env)
{
	t_vec3d	pos;

	pos = (t_vec3d){0, -2, 0, 0};
	if (env->mobs.nb_cells == 0)
		create_mob(env, &env->edit_env.map, ENEMY_CUBE, pos);
	return (0);
}
