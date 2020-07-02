#include "main.h"

void			enemies_kills_annoucements(t_env *env)
{
	int			source;
	static int	tmp = 0;

	if (env->custom_env.game.kill_delay > 0)
		--env->custom_env.game.kill_delay;
	if (env->custom_env.game.kill_delay == 0)
	{	
		env->custom_env.game.kill_count = 0;
		return ;
	}
	if (env->custom_env.game.kill_delay == KILL_DELAY - 1)
		tmp = 0;
	source = env->custom_env.game.kill_count;
	source = source < 2 ? 0 : source;
	source = source > 5 ? 6 : source;
	if (source)
	{
		source += SA_DOUBLEKILL - 2;
		if (tmp == source)
			return ;
		tmp = source;
		sound_system(env, source,
			sp_overall(0.5f, SA_DOUBLEKILL, SA_WICKEDSICK, false));
	}
}
