#include "main.h"

static void		play_sound(t_sample *sound, int delay)
{
	ALint 			status;
	static ALuint	source = UINT_MAX;
	static t_sample	*tmp = NULL;

	if (delay == KILL_DELAY - 1)
		tmp = NULL;
	if (sound == NULL || tmp == sound)
		return ;
	if (source == UINT_MAX)
		alGenSources(1, &source);
	alGetSourcei(source, AL_SOURCE_STATE, &status);
	if (status == AL_PLAYING)
	{
		if (tmp == sound)
			return ;
		alSourceStop(source);
	}
	alSourcei(source, AL_BUFFER, (ALint)sound->buffer);
	alSourcePlay(source);
	tmp = sound;
}

void			enemies_kills_annoucements(t_env *env)
{
	t_sample		*sound = NULL;

	if (env->custom_env.game.kill_delay > 0)
		--env->custom_env.game.kill_delay;
	if (env->custom_env.game.kill_delay == 0)
	{	
		env->custom_env.game.kill_count = 0;
		return ;
	}
	if (env->custom_env.game.kill_count == 2)
		sound = &env->sound.samples[SA_DOUBLEKILL];
	else if (env->custom_env.game.kill_count == 3)
		sound = &env->sound.samples[SA_TRIPLEKILL];
	else if (env->custom_env.game.kill_count == 4)
		sound = &env->sound.samples[SA_RAMPAGE];
	else if (env->custom_env.game.kill_count == 5)
		sound = &env->sound.samples[SA_GODLIKE];
	else if (env->custom_env.game.kill_count > 5)
		sound = &env->sound.samples[SA_WICKEDSICK];
	play_sound(sound, env->custom_env.game.kill_delay);
}
