#include "main.h"

int				background_sound(t_env *env, int source)
{
	if (env->events.keys[KEY_T])
	{
		env->volume += 0.01f;
		if (sound_system(env, source,
			sp_overall(0, SA_MAX - 1, sp_change_volume(0.01f))))
			return (-1);
	}
	else if (env->events.keys[KEY_G])
	{
		env->volume -= 0.01f;
		if (sound_system(env, source,
			sp_overall(0, SA_MAX - 1, sp_change_volume(-0.01f))))
			return (-1);
	}
	if (sound_system(env, 0, sp_no_sound(0, SA_PNL)) == 0)
		if (sound_system(env, source, sp_play(env->volume)))
			return (-1);
	return (0);
}

int 			fork_sound(t_dynarray *sounds, int source, t_sparam param)
{
	ALuint 	tmp;
	t_sound	*sound;

	sound = dyacc(sounds, source);
	if (sound == NULL)
		return (0);
	alGenSources(1, &tmp);
	sound->volume = param.volume;
	sound->volume = sound->volume > 1 ? 1 : sound->volume;
	sound->volume = sound->volume < 0 ? 0 : sound->volume;
	alSourcef(tmp, AL_GAIN, sound->volume);
	alSourcei(tmp, AL_BUFFER, (ALint)sound->samples->buffer);
	alSourcePlay(tmp);
	return (0);
}

int 			play_sound(t_dynarray *sounds, int source, t_sparam param)
{
	ALint 	status;
	t_sound	*sound;

	sound = dyacc(sounds, source);
	if (sound == NULL)
		return (0);
	alGetSourcei(sound->ambient, AL_SOURCE_STATE, &status);
	if (status == AL_PLAYING)
		return (0);
	sound->volume = param.volume;
	sound->volume = sound->volume > 1 ? 1 : sound->volume;
	sound->volume = sound->volume < 0 ? 0 : sound->volume;
	alSourcef(sound->ambient, AL_GAIN, sound->volume);
	alSourcei(sound->ambient, AL_BUFFER, (ALint)sound->samples->buffer);
	alSourcePlay(sound->ambient);
	return (0);
}

int 			sound_volume(t_dynarray *sounds, int s, t_sparam p, float v)
{
	ALint 	status;
	t_sound	*sound;

	sound = dyacc(sounds, s);
	if (sound == NULL)
		return (0);
	alGetSourcei(sound->ambient, AL_SOURCE_STATE, &status);
	if (status == AL_PLAYING)
	{
		sound->volume += p.volume;
		sound->volume = sound->volume < 0 ? 0 : sound->volume;
		sound->volume = sound->volume > v ? v : sound->volume;
		alSourcef(sound->ambient, AL_GAIN, sound->volume);
	}
	return (0);
}

int 			stop_sound(t_dynarray *sounds, int source)
{
	t_sound	*sound;

	sound = dyacc(sounds, source);
	if (sound == NULL)
		return (0);
	alSourceStop(sound->ambient);	
	return (0);
}
