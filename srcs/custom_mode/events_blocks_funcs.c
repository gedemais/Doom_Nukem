#include "main.h"

static int 		jukeboxs_play_sound(t_env *env)
{
	t_events	*e;
	static int	ambient = 0;
	static int	delay = 0;

	e = &env->events;
	if (e->keys[KEY_F] && env->custom_env.game.moula >= 1000 && delay == 0)
	{
		delay = 40;
		if (ambient < 0 || ambient > SA_MAPED)
			ambient = 0;
		sound_system(env, ambient, sp_overall(0, SA_MAPED,
			sp_play(env->sound.volume, PITCH, env->cam.stats.pos)));
		env->custom_env.game.moula -= 1000;
	}
	else if ((e->keys[KEY_LEFT] || e->keys[KEY_RIGHT]) && delay == 0)
	{
		delay = 5;
		ambient = e->keys[KEY_LEFT] ? ambient - 1 : ambient + 1;
		ambient = ambient < 0 ? SA_MAPED : ambient;
		ambient = ambient > SA_MAPED ? 0 : ambient;
	}
	delay = delay > 0 ? delay - 1 : delay;
	return (ambient);
}

int				handle_jukeboxs(t_env *env, t_event_block *block)
{
	if (block->id != BE_JUKEBOX)
		return (0);
	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) < EVENT_DIST)
	{
		textual_hint(env, "F", "PLAY ( 1000)", 0);
		textual_hint(env, "{", "PREVIOUS", 1);
		textual_hint(env, "}", "NEXT", 2);

		char	*current = ft_itoa(jukeboxs_play_sound(env));
		textual_hint(env, current, "current track", 3),
		ft_strdel(&current);
		return (1);
	}
	return (0);
}

static int		add_random_weapon(t_env *env)
{
	t_weapon	*w;
	int			index;
	int			i;
	bool		same;

	same = true;
	while (same)
	{
		i = -1;
		same = false;
		index = rand() % W_MAX;
		while (++i < env->player.weapons.nb_cells)
		{
			w = dyacc(&env->player.weapons, i);
			if (w->index == index && (same = true))
				break ;
		}
		if (i == env->player.weapons.nb_cells
			&& push_dynarray(&env->player.weapons, &env->weapons[index], 0))
				return (-1);
	}
	env->player.current = dyacc(&env->player.weapons, env->player.weapons.nb_cells - 1);
	env->player.current->ammos = env->player.current->max_ammos;
	return (0);
}

int				handle_mystery_boxs(t_env *env, t_event_block *block)
{
	static bool	button = false;

	if (block->id != BE_CHEST)
		return (0);
	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) < EVENT_DIST)
	{
		textual_hint(env, "F", "GET RANDOM WEAPON ( 1000)", 0);
		if (env->events.keys[KEY_F] && env->custom_env.game.moula >= 1000 && button)
		{
			button = false;
			env->custom_env.game.moula -= 1000;
			add_random_weapon(env);
			sound_system(env, SA_CHANGE,
				sp_fork(env->sound.volume, PITCH, env->cam.stats.pos));
		}
		button = !env->events.keys[KEY_F];
		return (1);
	}
	return (0);
}

int				handle_doors(t_env *env, t_event_block *block)
{
	if (block->id != BE_DOOR)
		return (0);
	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) < EVENT_DIST)
	{
		textual_hint(env, "F", "open the door ( cost 500)", 0);
		if (env->events.keys[KEY_F] && env->custom_env.game.moula >= 500)
		{
			env->custom_env.game.moula -= 500;
			del_door(env, block);
			sound_system(env, SA_DOOR,
				sp_fork(env->sound.volume, PITCH, env->cam.stats.pos));
		}
		return (1);
	}
	return (0);
}

int				handle_lavas(t_env *env, t_event_block *block)
{
	float			dst;
	t_vec3d			center;
	static int		delay = LAVA_DELAY;
	static int		delay2 = 10;

	if (block->id != BE_LAVA)
		return (0);
	center = get_block_center(block);
	dst = vec3d_dist(env->cam.stats.pos, center);
	sound_system(env, SA_LAVA, sp_play(env->sound.volume, PITCH, center));
	if (dst < EVENT_DIST)
	{
		if (--delay == 0)
		{
			if (delay2++ == 10)
			{
				sound_system(env, SA_PLAYER_DAMAGE,
					sp_fork(env->sound.volume, PITCH, env->cam.stats.pos));
				delay2 = 0;			
			}
			env->player.hp--;
			delay = LAVA_DELAY;
		}
		return (1);
	}
	return (0);
}
