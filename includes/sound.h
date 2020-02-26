#ifndef SOUND_H
# define SOUND_H

# include "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenAL.framework/Versions/A/Headers/al.h"
# include "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenAL.framework/Versions/A/Headers/alc.h"
# include <sndfile.h>
enum	e_sample_id
{
	SA_TITLE_SCREEN_S,
	SA_TITLE_SCREEN_L,
	SA_MAX
};

typedef struct	s_sample
{
	ALuint		buffer;
	ALshort		*sample;
	SNDFILE		*file;
	SF_INFO		infos;
	ALenum		format;
	ALsizei		sample_rate;
	ALsizei		nb_samples;
	float		length;
}				t_sample;

typedef struct	s_sound
{
	ALCdevice	*device;
	ALCcontext	*context;
	t_sample	*samples;
	ALuint		ambient;
}				t_sound;

char	*samples_paths(unsigned int index);
int		play_ambience(t_sample sample, bool play, bool stop, bool keep);
void	loop_sample(t_sample sample, bool launch, bool stop, bool keep);

#endif
