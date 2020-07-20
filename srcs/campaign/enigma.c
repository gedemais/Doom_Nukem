#include "main.h"

void	handle_enigma(t_env *env)
{
	static bool		answer[NB_BUZZERS] = {1, 0, 1, 0, 1, 0};
	bool			try[NB_BUZZERS];
	int				i;

	i = 0;
	while (i < NB_BUZZERS)
	{
		try[i] = env->cmp_env.buzzers[i].on;
		i++;
	}
	if (!ft_memcmp(answer, try))
		env->cmp_env.done = true;
}
