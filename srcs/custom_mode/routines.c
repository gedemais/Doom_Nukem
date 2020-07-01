#include "main.h"

int				custom_menu_to_play(t_env *env)
{
	t_map	*map;

	map = &env->edit_env.map;
	if (init_dynarray(&env->custom_env.mobs, sizeof(t_enemy), MAX_CUSTOM_MOBS)
		|| astar_init(env) || init_map_physics(&env->edit_env.map)
		|| (init_cameras_mesh(map, &map->cam)) || init_sky(env))
		return (-1);

	env->weapons[W_GLOCK_18].ammos = 80;
	push_dynarray(&env->player.weapons, &env->weapons[W_GLOCK_18], false);

	env->player.current_w = 0;
	env->player.current = dyacc(&env->player.weapons, 0);
	env->player.current->ammos = env->player.current->max_ammos;
	env->player.hp = START_HP;
	env->custom_env.game.moula = START_MOULA;

	mlx_mouse_hide();
	return (0);
}

int				custom_play_to_menu(t_env *env)
{
	free_dynarray(&env->custom_env.mobs);
	free_dynarray(&env->astar.d_nodes);
	free_dynarray(&env->astar.d_astar);
	// free new_map
	return (0);
}
