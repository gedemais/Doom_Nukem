#include "main.h"

static void	wound(t_env *env, t_enemy *mob)
{
	static float	sndelay = 1.0f;

	env->player.hp -= mob->damages;
	if (sndelay >= 1.0f)
	{
		sound_system(env, SA_PLAYER_DAMAGE,
			sp_fork(env->sound.volume, 1, env->cam.stats.pos));
		sndelay = 1.0f;
	}
	else
		sndelay -= env->data.spent;
}

static void	animate_wound(t_env *env, float *t)
{
	static t_vec3d	offset;
	float			ratio;

	ratio = *t + 0.5f;
	if (ratio > 0)
	{
		offset.x = 0.5f;
		offset.y = 0.5f;
	}
	else if (ratio <= 0)
	{
		offset.x = -0.5f;
		offset.y = -0.5f;
	}
	*t -= 0.1f;
	env->cam.stats.pos = vec_add(env->cam.stats.pos, offset);
	translate_mesh(&env->edit_env.map, &env->edit_env.map.cam, offset);
}

static void	check_wounds(t_env *env)
{
	static float	wound_t = -0.5f;
	t_enemy			*mob;
	int				i;

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
				wound_t = 0.5f;
			}
		}
		i++;
	}
	if (wound_t > -0.5f)
		animate_wound(env, &wound_t);
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
			? sp_fork(env->sound.volume, PITCH, env->cam.stats.pos)
			: sp_play(env->sound.volume, PITCH, env->cam.stats.pos));
		end = true;
		env->player.hp--;
	}
	env->player.god -= env->data.spent;
	if (env->player.god <= 0.0f)
		end = true;
}

int		handle_player(t_env *env)
{
	static int	heal = HEAL_SPEED;
	int			i;

	i = 0;
	heal--;
	if (env->player.god > 0.0f)
	{
		godmode(env);
		return (0);
	}
	if (env->player.hp < 1 && switch_custom_context(env, CUSTOM_SC_GAME_OVER))
		return (-1);
	if (heal <= 0)
	{
		if (env->player.hp < START_HP)
			env->player.hp++;
		heal = HEAL_SPEED;
	}
	check_wounds(env);
	return (0);
}
