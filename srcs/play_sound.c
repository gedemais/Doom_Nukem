#include "main.h"

void			loop_sample(t_sample *sample, bool launch, bool stop, bool keep)
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

int				play_ambience(t_sample *sample, bool play, bool stop, bool keep)
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
	if (keep)
	{
		alGetSourcei(source, AL_SOURCE_STATE, &status);
		return (status == AL_PLAYING ? 1 : 0);
	}
	if (play)
	{
		alSourcei(source, AL_BUFFER, (ALint)sample->buffer);
		alSourcePlay(source);
	}
	return (0);
}

static int 		init_sound_system(t_env *env, t_dynarray *sounds)
{
	int 	i;
	t_sound	sound;
	ALuint 	*sources;

	if (init_dynarray(sounds, sizeof(t_sound), SA_MAX))
		return (-1);
	if (!(sources = (ALuint *)malloc(sizeof(ALuint) * SA_MAX)))
		return (-1);
	alGenSources(SA_MAX - 1, sources);
	i = -1;
	while (++i < SA_MAX)
	{
    	ft_memset(&sound, 0, sizeof(t_sound));
    	sound.samples = &env->sound.samples[i];
    	sound.ambient = sources[i];
    	if (push_dynarray(sounds, &sound, 0))
    		return (-1);
	}
	return (0);
}

static int 		stop_sound(t_dynarray *sounds, int source)
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

static int 		stop_sounds(t_dynarray *sounds)
{
	int 	i;

	i = -1;
	while (++i < sounds->nb_cells)
		if (stop_sound(sounds, i))
			return (-1);
	return (0);
}

static int 		play_sound(t_dynarray *sounds, int source)
{
	ALint 	status;
	t_sound	*sound;

	sound = dyacc(sounds, source);
	if (sound == NULL)
		return (0);
	alGetSourcei(sound->ambient, AL_SOURCE_STATE, &status);
	if (status == AL_PLAYING)
		return (0);
	alSourcei(sound->ambient, AL_BUFFER, (ALint)sound->samples->buffer);
	alSourcePlay(sound->ambient);
	return (0);
}

int				sound_system(t_env *env, int source, bool stop, bool overall)
{
	static t_dynarray	sounds;

	if (sounds.byte_size == 0 && init_sound_system(env, &sounds))
		return (-1);
	if (source < 0 || source > sounds.nb_cells - 1)
		return (0);
	if (overall == true && stop_sounds(&sounds))
		return (-1);
	if (overall == false && stop == true && stop_sound(&sounds, source))
		return (-1);
	if (stop == false && play_sound(&sounds, source))
		return (-1);
	return (0);
}
