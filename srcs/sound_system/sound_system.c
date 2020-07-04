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
	//alDistanceModel(AL_INVERSE_DISTANCE_CLAMPED);
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

static int 		sound_overall(t_env *env, t_dynarray *s, int source, t_sparam p)
{
	int 	i;
	ALint 	status;
	t_sound	*sound;

	i = p.start - 1;
	while (++i <= p.end && i < s->nb_cells)
	{
		sound = dyacc(s, i);
		alGetSourcei(sound->ambient, AL_SOURCE_STATE, &status);
		if (status == AL_PLAYING && p.no_sound)
			return (1);
		if (p.sound && sound_volume(env, s, sound->ambient, p))
			return (-1);
		if (!p.no_sound && !p.sound
			&& stop_sound(s, sound->ambient))
			return (-1);
	}
	if (p.fork && fork_sound(env, s, source, p))
		return (-1);
	if (p.play && play_sound(env, s, source, p))
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
		return (sound_overall(env, &sounds, source, param));
	if (param.sound)
		return (sound_volume(env, &sounds, source, param));
	if ((param.fork && fork_sound(env, &sounds, source, param))
		|| (param.play && play_sound(env, &sounds, source, param))
		|| (param.stop && stop_sound(&sounds, source)))
		return (-1);
	return (0);
}
