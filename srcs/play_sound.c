#include "main.h"

void	play_ambience(t_sample sample, bool play, bool stop)
{
	static ALuint	source = UINT_MAX;
	ALint			status;

	if (source == UINT_MAX)
		alGenSources(1, &source);
	if (stop)
	{
		alGetSourcei(source, AL_SOURCE_STATE, &status);
		if (status == AL_PLAYING)
			alSourceStop(source);
	}
	else if (play)
	{
		alSourcei(source, AL_BUFFER, (ALint)sample.buffer);
		alSourcePlay(source);
	}
}
