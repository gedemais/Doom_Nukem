#include "main.h"

int				custom_menu_to_play(t_env *env)
{
	if (init_dynarray(&env->mobs, sizeof(t_enemy), MAX_CUSTOM_MOBS)
		|| astar_init(env) || init_map_physics(&env->edit_env.map) 
		|| (!(env->edit_env.map.colls = (bool*)malloc(sizeof(bool) * env->edit_env.map.nmesh)))
		|| (init_cameras_mesh(&env->edit_env.map, &env->edit_env.map.cam)))
		return (-1);

	print_mesh_corp(env->edit_env.map.cam);
	mlx_mouse_hide();
	return (0);
}

int				custom_play_to_menu(t_env *env)
{
	free_dynarray(&env->mobs);
	// free new_map
	return (0);
}
