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
	return (handle_sound(env, source, param));
	if (param.sound)
		return (sound_volume(&sounds, source, param));
	if (param.overall && stop_sounds(&sounds, source))
		return (-1);
	if (!param.overall && param.stop && stop_sound(&sounds, source))
		return (-1);
	if (!param.stop && !param.fork && play_sound(&sounds, source, param))
		return (-1);
	if (param.fork && fork_sound(&sounds, source, param))
		return (-1);
	return (0);
}
