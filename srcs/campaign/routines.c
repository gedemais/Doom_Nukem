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
	mlx_mouse_show();
}

void	cmp_menu_to_intro(t_env *env)
{
	env->cmp_env.countdown = COUNTDOWN;
	env->cmp_env.sector = SECTOR_START_ROOM;
	if (sound_system(env, 0, sp_overall(0, SA_MAX, sp_stop())))
		exit_doom(env, "error sound_system", 0, -1);
	if (sound_system(env, SA_BUTTON, sp_play(1, PITCH, env->cam.stats.pos)))
		exit_doom(env, "error sound_system", 0, -1);
	mlx_mouse_hide();
}

void	cmp_intro_to_game(t_env *env)
{
	(void)env;
	rasterizer(env, &env->maps[SCENE_START_ROOM], false);
	rasterizer(env, &env->maps[SCENE_DUST], false);
	mlx_mouse_hide();
}
