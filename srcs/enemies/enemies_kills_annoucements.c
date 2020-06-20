#include "main.h"

static void		play_sound(t_sample *sound)
{
	ALint 			status;
	static ALuint	source = UINT_MAX;
	static t_sample	*tmp = NULL;

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
	if (env->custom_env.game.kill_delay == 1)
	{
		env->custom_env.game.kill_count = 0;
		env->custom_env.game.kill_delay = 0;
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
	if (sound)
		play_sound(sound);
}
