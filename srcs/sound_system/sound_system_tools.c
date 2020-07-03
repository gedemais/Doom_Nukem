#include "main.h"

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

int 			sound_volume(t_dynarray *sounds, int source, t_sparam param)
{
	t_sound	*sound;

	sound = dyacc(sounds, source);
	if (sound == NULL)
		return (0);
	sound->volume += param.volume;
	sound->volume = sound->volume > 1 ? 1 : sound->volume;
	sound->volume = sound->volume < 0 ? 0 : sound->volume;
	alSourcef(sound->ambient, AL_GAIN, sound->volume);
	return (0);
}

int 			stop_sound(t_dynarray *sounds, int source)
{
	ALint 	status;
	t_sound	*sound;

	sound = dyacc(sounds, source);
	if (sound == NULL)
		return (0);
	alGetSourcei(sound->ambient, AL_SOURCE_STATE, &status);
	if (status == AL_PLAYING)
		alSourceStop(sound->ambient);	
	return (0);
}
