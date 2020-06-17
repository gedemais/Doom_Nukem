#include "main.h"

int		handle_jukeboxs(t_env *env, t_event_block *block)
{
	t_events	*e;
	char		*track;

	e = &env->events;
	if (block->id != BE_JUKEBOX)
		return (0);
	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) > EVENT_DIST)
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

int		handle_mystery_boxs(t_env *env, t_event_block *block)
{
	if (block->id != BE_CHEST)
		return (0);
	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) > EVENT_DIST)
	{
		textual_hint(env, 'F', "get a random weapon ( cost x)", 0);
		return (1);
	}
	return (0);
}

int		handle_doors(t_env *env, t_event_block *block)
{
	if (block->id != BE_DOOR)
		return (0);
	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) > EVENT_DIST)
	{
		textual_hint(env, 'F', "open the door ( cost x)", 0);
		return (1);
	}
	return (0);
}
