#include "main.h"

int		setup_custom(t_env *env)
{
	env->custom_env.env = env;
	env->custom_env.sub_context = CUSTOM_SC_MENU;
	return (0);
}
