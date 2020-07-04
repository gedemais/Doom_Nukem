#include "main.h"

static void	wound(t_env *env, t_enemy *mob)
{
	env->player.hp -= mob->damages;
}

static void	check_wounds(t_env *env)
{
	t_enemy	*mob;
	int		i;

	i = 0;
	while (i < env->custom_env.mobs.nb_cells)
	{
		mob = dyacc(&env->custom_env.mobs, i);
		if (vec3d_dist(env->cam.stats.pos, mob->pos) < EVENT_DIST)
		{
			mob->peace--;
			if (mob->peace <= 0)
			{
				mob->peace = MOB_PEACE_TIME;
				wound(env, mob);
			}
		}
		i++;
	}
}

static void	godmode(t_env *env)
{
	static bool	end = true;
	int			fade;

	fade = 10;
	if (env->player.hp < 142 && env->player.god > (GOD_TIME / fade))
		env->player.hp++;
	if (env->player.hp > 100 && env->player.god < (GOD_TIME / fade))
	{
		sound_system(env, SA_LGODEND, end
			? sp_fork(env->volume, env->cam.stats.pos)
			: sp_play(env->volume, env->cam.stats.pos));
		end = true;
		env->player.hp--;
	}
	env->player.god -= env->data.spent;
	if (env->player.god <= 0.0f)
		end = true;
}

void	handle_player(t_env *env)
{
	static int	heal = HEAL_SPEED;
	int			i;

	i = 0;
	heal--;
	if (env->player.god > 0.0f)
	{
		godmode(env);
		return ;
	}
	if (env->player.hp < 1)
		switch_custom_context(env, CUSTOM_SC_GAME_OVER);
	if (heal <= 0)
	{
		if (env->player.hp < START_HP)
			env->player.hp++;
		heal = HEAL_SPEED;
	}
	check_wounds(env);
}
