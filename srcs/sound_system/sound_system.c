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

static int 		sound_overall(t_dynarray *sounds, int source, t_sparam param)
{
	int 	i;
	ALint 	status;
	t_sound	*sound;

	i = param.start - 1;
	while (++i <= param.end && i < sounds->nb_cells)
	{
		sound = dyacc(sounds, i);
		alGetSourcei(sound->ambient, AL_SOURCE_STATE, &status);
		if (param.no_sound && status == AL_PLAYING)
			return (1);
		if (param.sound && sound_volume(sounds, sound->ambient, param))
			return (-1);
		else if (!param.no_sound && stop_sound(sounds, sound->ambient))
			return (-1);
	}
	if (param.fork && fork_sound(sounds, source, param))
		return (-1);
	if (param.play && play_sound(sounds, source, param))
		return (-1);
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
	if (param.overall || param.no_sound)
		return (sound_overall(&sounds, source, param));
	if (param.sound)
		return (sound_volume(&sounds, source, param));
	if (param.fork && fork_sound(&sounds, source, param))
		return (-1);
	if (param.play && play_sound(&sounds, source, param))
		return (-1);
	if (param.stop && stop_sound(&sounds, source))
		return (-1);
	return (0);
}
