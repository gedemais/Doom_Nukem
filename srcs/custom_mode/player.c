#include "main.h"
/*
static void	check_wounds(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->mobs.)
}*/

void	handle_player(t_env *env)
{
	static int	heal = HEAL_SPEED;
	int			i;

	i = 0;
	heal--;
	if (heal <= 0)
	{
		if (env->player.hp < START_HP)
			env->player.hp++;
		heal = HEAL_SPEED;
	}
//	check_wounds(env);
}

