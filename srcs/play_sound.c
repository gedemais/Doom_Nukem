#include "main.h"

void	play_sound(t_sample sample, ALfloat pos[3])
{
	static ALuint	source = UINT_MAX;

	if (source == UINT_MAX)
		alGenSources(1, &source);
	alSourcei(source, AL_BUFFER, (ALint)sample.buffer);
	alSourcei(source, AL_POSITION, (ALint)pos);
	alSourcePlay(source);
}
