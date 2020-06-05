#include "main.h"

int				custom_menu_to_play(t_env *env)
{
	if (init_dynarray(&env->mobs, sizeof(t_enemy), MAX_CUSTOM_MOBS)
		|| astar_init(env) || init_map_physics(&env->edit_env.map))
		return (-1);
	mlx_mouse_hide();
	return (0);
}

int				custom_play_to_menu(t_env *env)
{
	free_dynarray(&env->mobs);
	// free new_map
	return (0);
}
