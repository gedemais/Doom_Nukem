#include "main.h"

int				custom_menu_to_play(t_env *env)
{
	t_map	*map;

	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	map = &env->edit_env.map;
	if (init_dynarray(&env->custom_env.mobs, sizeof(t_enemy), MAX_CUSTOM_MOBS)
		|| astar_init(env) || init_map_physics(&env->edit_env.map)
		|| (init_cameras_mesh(map, &map->cam)) || init_sky(env))
		return (-1);

	env->weapons[W_GLOCK_18].ammos = 80;
	if (push_dynarray(&env->player.weapons, &env->weapons[W_GLOCK_18], false))
		return (-1);

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
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	mlx_mouse_show();
	free_maped(env);
	free_dynarray(&env->player.weapons);
	free_dynarray(&env->custom_env.mobs);
	free_dynarray(&env->custom_env.loots);
	free_dynarray(&env->custom_env.events);
	free_dynarray(&env->astar.d_nodes);
	free_dynarray(&env->astar.d_astar);
	return (0);
}

int			custom_play_to_game_over(t_env *env)
{
	mlx_mouse_show();
	free_maped(env);
	free_dynarray(&env->player.weapons);
	free_dynarray(&env->custom_env.mobs);
	free_dynarray(&env->custom_env.loots);
	free_dynarray(&env->custom_env.events);
	free_dynarray(&env->astar.d_nodes);
	free_dynarray(&env->astar.d_astar);
	return (0);
}

int			custom_game_over_to_play(t_env *env)
{
	t_map	*map;

	mlx_mouse_hide();
	map = &env->edit_env.map;
	if (import_maped_map(&env->edit_env, env->custom_env.map_path)
		|| map_to_scene(env) || parse_events_blocks(env)
		|| init_dynarray(&env->custom_env.mobs, sizeof(t_enemy), MAX_CUSTOM_MOBS)
		|| astar_init(env) || init_map_physics(&env->edit_env.map)
		|| (init_cameras_mesh(map, &map->cam)) || init_sky(env))
		return (-1);
	set_game_stats(env);
	return (0);
}

int			custom_game_over_to_menu(t_env *env)
{
	(void)env;
	return (0);
}
