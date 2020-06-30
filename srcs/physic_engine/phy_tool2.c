#include "main.h"

bool	key_move(bool keys[NB_KEYS])
{
	if ((keys[KEY_W] || keys[KEY_S] || keys[KEY_A] || keys[KEY_D]) || keys[KEY_E]) 
		return (true);
	else
		return (false);
}

void	stop_position_cam(t_env *env, t_map *maps, t_mesh *cam)
{
	(void)maps;
	if (env->cam.stats.pos.y < -10 || env->cam.stats.onfloor == 1)
	{
		env->phy_env.tps = 0;
		cam->corp.v = zero_vector();
		if (env->cam.stats.pos.y < -10)
			translate_mesh(maps, cam, vec_sub(zero_vector(), cam->corp.o));
	}
}

