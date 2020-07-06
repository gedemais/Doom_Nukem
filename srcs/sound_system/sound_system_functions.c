#include "main.h"

int 			fork_sound(t_env *env, t_dynarray *s, int source, t_sparam p)
{
	ALuint 	tmp;
	t_sound	*sound;

	sound = dyacc(s, source);
	if (sound == NULL)
		return (0);
	alGenSources(1, &tmp);
	alListener3f(AL_POSITION, -env->cam.stats.pos.x,
		env->cam.stats.pos.y, env->cam.stats.pos.z);
	alSource3f(tmp, AL_POSITION, -p.pos.x, p.pos.y, p.pos.z);
	alSourcef(tmp, AL_REFERENCE_DISTANCE, 1);
	alSourcef(tmp, AL_ROLLOFF_FACTOR, 1);
	alSourcef(tmp, AL_MAX_DISTANCE, 50);
	alSourcef(tmp, AL_GAIN, p.volume);
	alSourcef(tmp, AL_PITCH, p.pitch);
	alSourcei(tmp, AL_BUFFER, (ALint)sound->samples->buffer);
	alSourcePlay(tmp);
	return (0);
}

int 			play_sound(t_env *env, t_dynarray *s, int source, t_sparam p)
{
	ALint 	status;
	t_sound	*sound;

	sound = dyacc(s, source);
	if (sound == NULL)
		return (0);
	sound->volume = p.volume;
	sound->pitch = p.pitch;
	alGetSourcei(sound->ambient, AL_SOURCE_STATE, &status);
	if (status == AL_PLAYING)
		return (0);
	alListener3f(AL_POSITION, -env->cam.stats.pos.x,
		env->cam.stats.pos.y, env->cam.stats.pos.z);
	alSource3f(sound->ambient, AL_POSITION, -p.pos.x, p.pos.y, p.pos.z);
	alSourcef(sound->ambient, AL_GAIN, p.volume);
	alSourcef(sound->ambient, AL_PITCH, p.pitch);
	alSourcei(sound->ambient, AL_BUFFER, (ALint)sound->samples->buffer);
	alSourcePlay(sound->ambient);
	return (0);
}

int 			sound_volume(t_env *env, t_dynarray *s, int source, t_sparam p)
{
	ALint 	status;
	t_sound	*sound;

	sound = dyacc(s, source);
	if (sound == NULL)
		return (0);
	alGetSourcei(sound->ambient, AL_SOURCE_STATE, &status);
	if (status == AL_PLAYING)
	{
		sound->volume += p.volume;
		sound->volume = sound->volume > env->volume
			? env->volume : sound->volume;
		sound->volume = sound->volume < 0 ? 0 : sound->volume;
		alSourcef(sound->ambient, AL_GAIN, sound->volume);
		sound->pitch += p.pitch;
		sound->pitch = sound->pitch > 2 ? 2 : sound->pitch;
		sound->pitch = sound->pitch < 0 ? 0 : sound->pitch;
		alSourcef(sound->ambient, AL_PITCH, sound->pitch);
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
