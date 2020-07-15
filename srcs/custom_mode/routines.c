#include "main.h"

int				custom_menu_to_play(t_env *env)
{
	t_map	*map;

	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	map = &env->edit_env.map;
	if (map_to_scene(env) || parse_events_blocks(env)
		|| init_dynarray(&env->custom_env.mobs, sizeof(t_enemy), MAX_ENEMIES)
		|| astar_init(env) || init_map_physics(&env->edit_env.map)
		|| (init_cameras_mesh(map, &map->cam)) || init_sky(env)
		|| init_loots(env))
		return (-1);
	set_game_stats(env);
	env->data.wireframe = false;
	mlx_mouse_hide();
	return (0);
}

int				custom_play_to_menu(t_env *env)
{
	mlx_mouse_show();
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	ft_strdel(&env->custom_env.map_path);
	free_maped(env);
	free_dynarray(&env->player.weapons);
	free_dynarray(&env->custom_env.mobs);
	free_dynarray(&env->custom_env.events);
	free_dynarray(&env->astar.d_nodes);
	free_dynarray(&env->astar.d_astar);
	env->custom_env.loot.m = NULL;
	return (0);
}

int			custom_play_to_game_over(t_env *env)
{
	mlx_mouse_show();
	free_maped(env);
	free_dynarray(&env->player.weapons);
	free_dynarray(&env->custom_env.mobs);
	free_dynarray(&env->custom_env.events);
	free_dynarray(&env->astar.d_nodes);
	free_dynarray(&env->astar.d_astar);
	env->custom_env.loot.m = NULL;
	return (0);
}

int			custom_game_over_to_play(t_env *env)
{
	t_map	*map;

	map = &env->edit_env.map;
	if (import_maped_map(&env->edit_env, env->custom_env.map_path)
		|| map_to_scene(env) || parse_events_blocks(env)
		|| init_dynarray(&env->custom_env.mobs, sizeof(t_enemy), MAX_ENEMIES)
		|| astar_init(env) || init_map_physics(&env->edit_env.map)
		|| (init_cameras_mesh(map, &map->cam)) || init_sky(env)
		|| init_loots(env))
		return (-1);
	set_game_stats(env);
	env->data.wireframe = false;
	mlx_mouse_hide();
	env->phy_env.type_move = true;
	return (0);
}

int			custom_game_over_to_menu(t_env *env)
{
	free(env->custom_env.map_path);
	return (0);
}
