#ifndef SOUND_H
# define SOUND_H

# include "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenAL.framework/Versions/A/Headers/al.h"
# include "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenAL.framework/Versions/A/Headers/alc.h"
# include <sndfile.h>

# define NB_SAMPLES 1

/*
enum	e_sample_id
{
	
}		t_sample_id;
*/

typedef struct	s_sample
{
	ALuint		buffer;
	int			pada;
	ALshort		*sample;
	SNDFILE		*file;
	SF_INFO		infos;
	ALenum		format;
	int			pad;
	ALsizei		sample_rate;
	ALsizei		nb_samples;
}				t_sample;

typedef struct	s_sound
{
	ALCdevice	*device;
	ALCcontext	*context;
	t_sample		*samples;
}				t_sound;

#endif
