#include "main.h"

int		handle_jukeboxs(t_env *env, t_event_block *block, int index)
{
	t_events	*e;
	char		*track;

	(void)index;
	e = &env->events;
	if (block->id != BE_JUKEBOX)
		return (0);
	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) < EVENT_DIST)
	{
		track = &block->param.c;
		textual_hint(env, 'F', "turn on / off", 0);
		textual_hint(env, '{', "play previous track ( cost x)", 1);
		textual_hint(env, '}', "play next track ( cost x)", 2);
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

int		handle_mystery_boxs(t_env *env, t_event_block *block, int index)
{
	(void)index;
	if (block->id != BE_CHEST)
		return (0);
	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) < EVENT_DIST)
	{
		textual_hint(env, 'F', "get a random weapon ( cost x)", 0);
		return (1);
	}
	return (0);
}

int		handle_doors(t_env *env, t_event_block *block, int index)
{
	(void)index;
	if (block->id != BE_DOOR)
		return (0);
	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) < EVENT_DIST)
	{
		textual_hint(env, 'F', "open the door ( cost x)", 0);
		if (env->events.keys[KEY_F])
		{
		//	del_door(env);
	//		extract_door_blocks(env, &env->custom_env.events, block);
			play_ambience(&env->sound.samples[SA_DOOR], true, false, false);
		}
		return (1);
	}
	return (0);
}

int		handle_lavas(t_env *env, t_event_block *block, int index)
{
	static int		delay = LAVA_DELAY;

	(void)index;
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
