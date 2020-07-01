#include "main.h"

int		handle_jukeboxs(t_env *env, t_event_block *block)
{
	t_events	*e;
	char		*track;

	e = &env->events;
	if (block->id != BE_JUKEBOX)
		return (0);
	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) < EVENT_DIST)
	{
		track = &block->param.c;
		textual_hint(env, "F", "turn on / off", 0);
		textual_hint(env, "{", "play previous track ( cost x)", 1);
		textual_hint(env, "}", "play next track ( cost x)", 2);
		if (e->keys[KEY_F])
			*track = *track >= 0 ? -1 : 0; // on / off
		else if (e->keys[KEY_LEFT])
			*track = *track == 0 ? MT_MAX - 1 : *track - 1; // previous
		else if (e->keys[KEY_RIGHT])
			*track = *track == MT_MAX ? 0 : *track + 1; // next
		//*track >= 0 ? play_ambience(NULL, false, true, false) : 0; Stop the current track if one
		//*track >= 0 ? play_ambience(env->) : 0; Play the new track
		return (1);
	}
	return (0);
}

static int	add_random_weapon(t_env *env)
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

int		handle_mystery_boxs(t_env *env, t_event_block *block)
{
	static float	delay = 1.0f;

	if (block->id != BE_CHEST)
		return (0);
	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) < EVENT_DIST)
	{
		textual_hint(env, "F", "get a random weapon ( cost 1000)", 0);
		if (env->events.keys[KEY_F] && env->custom_env.game.moula >= 1000 && delay < 0)
		{
			delay = 1.0f;
			env->custom_env.game.moula -= 1000;
			add_random_weapon(env);
			// sound
		}
		else
			delay -= env->data.spent;
		return (1);
	}
	return (0);
}

int			handle_doors(t_env *env, t_event_block *block)
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
			play_ambience(&env->sound.samples[SA_DOOR], true, false, false);
		}
		return (1);
	}
	return (0);
}

int		handle_lavas(t_env *env, t_event_block *block)
{
	static int		delay = LAVA_DELAY;

	if (block->id != BE_LAVA)
		return (0);
	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) < EVENT_DIST)
	{
		delay--;
		if (delay == 0)
		{
			env->player.hp--;
			delay = LAVA_DELAY;
		}
		return (1);
	}
	return (0);
}
