#include "main.h"

void	loop_sample(t_sample *sample, bool launch, bool stop, bool keep)
{
	static bool		play = false;

	if (keep && play_ambience(sample, false, false, true) == 0)
		play_ambience(sample, true, false, false);
	else if (launch && !stop)
	{
		play = true;
		play_ambience(sample, true, false, false);
	}
	else if (stop)
	{
		play_ambience(sample, false, true, false);
		play = false;
	}
}

int		play_ambience(t_sample *sample, bool play, bool stop, bool keep)
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
	else if (keep)
	{
		alGetSourcei(source, AL_SOURCE_STATE, &status);
		return (status == AL_PLAYING ? 1 : 0);
	}
	else if (play)
	{
		alSourcei(source, AL_BUFFER, (ALint)sample->buffer);
		alSourcePlay(source);
	}
	return (0);
}
