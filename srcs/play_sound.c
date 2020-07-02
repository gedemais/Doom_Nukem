#include "main.h"

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
    	{
    		free(sources);
    		return (-1);
    	}
	}
	free(sources);
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

static int 		stop_sounds(t_dynarray *sounds, int source)
{
	int 	i;

	i = -1;
	while (++i < sounds->nb_cells)
		if (i != source && stop_sound(sounds, i))
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

static int 		fork_sound(t_dynarray *sounds, int source)
{
	ALuint 	tmp;
	t_sound	*sound;

	sound = dyacc(sounds, source);
	if (sound == NULL)
		return (0);
	alGenSources(1, &tmp);
	alSourcei(tmp, AL_BUFFER, (ALint)sound->samples->buffer);
	alSourcePlay(tmp);
	return (0);
}

static int 		sound_volume(t_dynarray *sounds, int source, t_sparam param)
{
	t_sound	sound;

	sound = dyacc(sounds, source);
	if (sound == NULL)
		return (0);
	alSourcef(sound->ambient, AL_GAIN, param.volume);
	return (0);
}

int				sound_system(t_env *env, int source, t_sparam param)
{
	static t_dynarray	sounds;

	if (sounds.byte_size == 0 && init_sound_system(env, &sounds))
		return (-1);
	if (source < 0 || source > sounds.nb_cells - 1)
	{
		free_dynarray(&sounds);
		return (1);
	}
	if (param.overall && stop_sounds(&sounds, source))
		return (-1);
	if (!param.overall && param.stop && stop_sound(&sounds, source))
		return (-1);
	if (!param.stop && !param.fork && play_sound(&sounds, source))
		return (-1);
	if (param.fork && fork_sound(&sounds, source))
		return (-1);
	return (0);
}
