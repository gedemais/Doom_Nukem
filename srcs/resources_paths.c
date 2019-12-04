#include "main.h"

char	*sprites_paths(unsigned int index)
{
	static char		*paths[SP_MAX] = {
					"resources/sprites/download.bmp"};

	return (paths[index]);
}

char	*samples_paths(unsigned int index)
{
	static char		*paths[SA_MAX] = {
					"resources/samples/ambiances/ambient_.wav"};

	return (paths[index]);
}

