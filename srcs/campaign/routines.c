#include "main.h"

void	cmp_menu_to_game(t_env *env)
{
	if (sound_system(env, 0, sp_overall(0, SA_MAX, sp_stop())))
		exit_doom(env, "error sound_system", 0, -1);
	if (sound_system(env, SA_BUTTON, sp_play(1, PITCH, env->cam.stats.pos)))
		exit_doom(env, "error sound_system", 0, -1);
	env->data.wireframe = false;
	mlx_mouse_hide();
}

void	cmp_game_to_menu(t_env *env)
{
	if (sound_system(env, 0, sp_overall(0, SA_MAX, sp_stop())))
		exit_doom(env, "error sound_system", 0, -1);
	if (sound_system(env, SA_BUTTON, sp_play(1, PITCH, env->cam.stats.pos)))
		exit_doom(env, "error sound_system", 0, -1);
	mlx_mouse_show();
}
