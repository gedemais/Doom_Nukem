#include "main.h"

static int		astar_init(t_env *env)
{
	t_pf		*astar;
	t_ed_map	map;

	astar = &env->astar;
	map = env->edit_env.new_map;
	if (init_dynarray(&astar->d_astar, sizeof(t_node), 1))
		return (-1);
	if (astar_get_custom_nodes(map, astar))
		return (-1);
	return (0);
}

int				custom_menu_to_play(t_env *env)
{
	if (init_dynarray(&env->mobs, sizeof(t_enemy), MAX_CUSTOM_MOBS))
		return (-1);
	if (astar_init(env))
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
