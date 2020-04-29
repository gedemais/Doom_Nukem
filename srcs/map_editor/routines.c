#include "main.h"

int	me_menu_to_new_map(t_env *env)
{
	(void)env;
	// Enable les saisies de texte du menu new_map
	env->ttfs.fields[0].rendered = true;
	env->ttfs.fields[1].rendered = true;
	env->ttfs.fields[2].rendered = true;
	env->ttfs.fields[3].rendered = true;
	env->ttfs.fields[4].rendered = true;
	return (0);
}

int	me_menu_to_creative(t_env *env)
{
	(void)env;
	return (0);
}

int	me_new_map_to_creative(t_env *env)
{
	(void)env;
	return (0);
}

int	me_new_map_to_menu(t_env *env)
{
	(void)env;
	return (0);
}

int	me_creative_to_menu(t_env *env)
{
	(void)env;
	return (0);
}
