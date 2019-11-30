#include "main.h"

char	*sprites_paths(unsigned int index)
{
	static char		*paths[SAMPLE_MAX] = {
					"resources/sprites/download.XPM"};

	return (paths[index]);
}

char	*samples_paths(unsigned int index)
{
	static char		*paths[SAMPLE_MAX] = {
					"resources/samples/mobs/walking_1.wav",
					"resources/samples/ambiances/ambient_.wav"};

	return (paths[index]);
}

