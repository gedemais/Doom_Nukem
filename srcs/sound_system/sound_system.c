#include "main.h"

static int 		init_sound(t_env *env, t_dynarray *s, ALuint *sources, int i)
{
	t_sound	sound;

    ft_memset(&sound, 0, sizeof(t_sound));
    sound.samples = &env->sound.samples[i];
	sound.ambient = sources[i];
	alSourcef(sound.ambient, AL_REFERENCE_DISTANCE, 1);
	alSourcef(sound.ambient, AL_ROLLOFF_FACTOR, 1);
	alSourcef(sound.ambient, AL_MAX_DISTANCE, 50);
    return (push_dynarray(s, &sound, 0));
}

static int 		init_sound_system(t_env *env, t_dynarray *sounds)
{
	int 	i;
	ALuint 	*sources;

	env->volume = VOLUME;
	if (init_dynarray(sounds, sizeof(t_sound), SA_MAX))
		return (-1);
	if (!(sources = (ALuint *)malloc(sizeof(ALuint) * SA_MAX)))
		return (-1);
	alGenSources(SA_MAX - 1, sources);

	//AL_INVERSE_DISTANCE 1/0.3
	//AL_EXPONENT_DISTANCE R 1/0.3
	//AL_LINEAR_DISTANCE 1/1
	alDistanceModel(AL_LINEAR_DISTANCE);
	i = -1;
	while (++i < SA_MAX)
		if (init_sound(env, sounds, sources, i))
		{
			free(sources);
			return (-1);
		}
	free(sources);
	return (0);
}

static int 		quit_sound_system(t_dynarray *sounds)
{
	int		i;
	t_sound	*sound;

	i = -1;
	while (++i < sounds->nb_cells)
	{
		sound = dyacc(sounds, i);
		stop_sound(sounds, i);
		alDeleteSources(1, &sound->ambient);
	}
	free_dynarray(sounds);
	return (0);
}

static int 		sound_overall(t_env *env, t_dynarray *s, int source, t_sparam p)
{
	int 	i;
	ALint 	status;
	t_sound	*sound;

	i = p.start - 1;
	while (++i <= p.end && i < s->nb_cells)
	{
		sound = dyacc(s, i);
		if (p.no_sound)
		{
			alGetSourcei(sound->ambient, AL_SOURCE_STATE, &status);
			if (status == AL_PLAYING)
				return (1);
			continue ;
		}
		if ((p.sound && sound_volume(env, s, sound->ambient, p))
			|| ((p.play || p.fork || p.stop) && stop_sound(s, sound->ambient)))
			return (-1);
	}
	if ((p.fork && fork_sound(env, s, source, p))
		|| (p.play && play_sound(env, s, source, p)))
		return (-1);
	return (0);
}

int				sound_system(t_env *env, int source, t_sparam param)
{
	static t_dynarray	sounds;

	if (sounds.byte_size == 0 && init_sound_system(env, &sounds))
		return (-1);
	if (source < 0 || source > sounds.nb_cells - 1)
		return (quit_sound_system(&sounds));
	if (param.overall || param.no_sound)
		return (sound_overall(env, &sounds, source, param));
	if ((param.sound && sound_volume(env, &sounds, source, param))
		|| (param.fork && fork_sound(env, &sounds, source, param))
		|| (param.play && play_sound(env, &sounds, source, param))
		|| (param.stop && stop_sound(&sounds, source)))
		return (-1);
	return (0);
}
