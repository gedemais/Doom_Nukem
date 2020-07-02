#include "main.h"

int	me_menu_to_new_map(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0.5f, 0, SA_MAX, true));
	// Enable les saisies de texte du menu new_map
	env->ttfs.fields[0].rendered = true;
	env->ttfs.fields[1].rendered = true;
	env->ttfs.fields[2].rendered = true;
	env->ttfs.fields[3].rendered = true;
	return (0);
}

int	me_menu_to_creative(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0.5f, 0, SA_MAX, true));
	mlx_mouse_hide();
	return (0);
}

int	me_new_map_to_creative(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0.5f, 0, SA_MAX, true));
	mlx_mouse_hide();
	return (0);
}

int	me_new_map_to_menu(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0.5f, 0, SA_MAX, true));
	// Disable les saisies de texte du menu new_map
	env->ttfs.fields[0].rendered = false;
	env->ttfs.fields[1].rendered = false;
	env->ttfs.fields[2].rendered = false;
	env->ttfs.fields[3].rendered = false;
	return (0);
}

int	me_creative_to_menu(t_env *env)
{
	sound_system(env, SA_TITLE_SCREEN_L,
		sp_overall(0.5f, 0, SA_MAX, true));
	// free new_map
	return (0);
}
