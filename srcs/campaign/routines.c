#include "main.h"

void	cmp_menu_to_game(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	mlx_mouse_hide();
}

void	cmp_game_to_menu(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0, SA_MAX, sp_stop()));
	mlx_mouse_show();
}
