#include "main.h"

static int 		init_sound(t_env *env, t_dynarray *s, ALuint *sources, int i)
{
	t_sound	sound;

    ft_memset(&sound, 0, sizeof(t_sound));
    sound.samples = &env->sound.samples[i];
	sound.ambient = sources[i];
	alSourcef(sound.ambient, AL_REFERENCE_DISTANCE, 1);
	alSourcef(sound.ambient, AL_ROLLOFF_FACTOR, 1);
	alSourcef(sound.ambient, AL_MAX_DISTANCE, 60);
    return (push_dynarray(s, &sound, 0));
}

static int 		init_sound_system(t_env *env, t_dynarray *sounds)
{
	int 	i;
	ALuint 	*sources;

	env->volume = VOLUME;
	env->sound.sounds = sounds;
	if (SA_MAX < 1 || init_dynarray(sounds, sizeof(t_sound), SA_MAX))
		return (-1);
	if (!(sources = (ALuint *)malloc(sizeof(ALuint) * SA_MAX)))
		return (-1);
	alGenSources(SA_MAX - 1, sources);
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

static int 		quit_sound_system(t_env *env)
{
	int		i;
	t_sound	*sound;

	i = -1;
	while (++i < env->sound.sounds->nb_cells)
	{
		sound = dyacc(env->sound.sounds, i);
		alDeleteSources(1, &sound->ambient);
	}
	free_dynarray(env->sound.sounds);
	i = -1;
	while (++i < env->sound.fork->nb_cells)
	{
		sound = dyacc(env->sound.fork, i);
		alDeleteSources(1, &sound->ambient);
	}
	free_dynarray(env->sound.fork);
	return (-1);
}

static int 		sound_overall(t_env *env, int source, t_sparam p)
{
	int 		i;
	ALint 		status;
	t_sound		*sound;
	t_dynarray	*sounds;

	sounds = p.fork ? env->sound.fork : env->sound.sounds;
	i = p.start - 1;
	while (++i <= p.end && i < sounds->nb_cells)
	{
		sound = dyacc(sounds, i);
		if (p.no_sound)
		{
			alGetSourcei(sound->ambient, AL_SOURCE_STATE, &status);
			if (status == AL_PLAYING)
				return (1);
			continue ;
		}
		if ((sound_volume(env, sound->ambient, p))
			|| ((p.play || p.fork || p.stop)
				&& stop_sound(env, sound->ambient)))
			return (quit_sound_system(env));
	}
	if ((fork_sound(env, source, p)) || (play_sound(env, source, p)))
		return (quit_sound_system(env));
	return (0);
}

static int		init_fork(t_env *env, t_dynarray *fork)
{
	int 	i;
	t_sound	sound;
	ALuint 	*sources;

	if (SA_BUFFER < 1 || init_dynarray(fork, sizeof(t_sound), SA_BUFFER))
		return (-1);
	if (!(sources = (ALuint *)malloc(sizeof(ALuint) * SA_BUFFER)))
		return (-1);
	env->sound.fork = fork;
	alGenSources(SA_BUFFER - 1, sources);
	i = -1;
	while (++i < SA_BUFFER)
	{
    	ft_memset(&sound, 0, sizeof(t_sound));
		sound.ambient = sources[i];
		alSourcef(sound.ambient, AL_REFERENCE_DISTANCE, 1);
		alSourcef(sound.ambient, AL_ROLLOFF_FACTOR, 1);
		alSourcef(sound.ambient, AL_MAX_DISTANCE, 60);
		if (push_dynarray(fork, &sound, 0))
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
	static t_dynarray	fork;

	if (sounds.byte_size == 0
		&& (init_sound_system(env, &sounds) || init_fork(env, &fork)))
		return (quit_sound_system(env));
	if (source < 0 || source > sounds.nb_cells - 1)
		return (!quit_sound_system(env));
	if (param.overall || param.no_sound)
		return (sound_overall(env, source, param));
	if ((sound_volume(env, source, param))
		|| (fork_sound(env, source, param))
		|| (play_sound(env, source, param))
		|| (param.stop && stop_sound(env, source)))
		return (quit_sound_system(env));
	return (0);
}
