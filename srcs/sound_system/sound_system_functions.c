#include "main.h"

static int		listener_param(t_env *env)
{
	float	vec[6];
	t_vec3d	dir;

	alListener3f(AL_POSITION, env->cam.stats.pos.x,
		env->cam.stats.pos.y, env->cam.stats.pos.z);
	alListener3f(AL_VELOCITY, 0, 0, 0);
	dir = vec_add(env->cam.stats.pos, env->cam.stats.dir);
	alListener3f(AL_DIRECTION, dir.x, dir.y, dir.z);
	vec[0] = dir.x;
	vec[1] = dir.y;
	vec[2] = dir.z;
	vec[3] = env->cam.stats.pos.x;
	vec[4] = env->cam.stats.pos.y + 1;
	vec[5] = env->cam.stats.pos.z;
	alListenerfv(AL_ORIENTATION, vec);
	return (0);
}

static int		source_param(ALuint *source, t_sparam p)
{
	float	vec[6];

	alSource3f(*source, AL_POSITION, p.pos.x, p.pos.y, p.pos.z);
	alSource3f(*source, AL_VELOCITY, 0, 0, 0);
	alSource3f(*source, AL_DIRECTION, p.pos.x, p.pos.y, p.pos.z + 1);
	vec[0] = p.pos.x;
	vec[1] = p.pos.y;
	vec[2] = p.pos.z + 1;
	vec[3] = p.pos.x;
	vec[4] = p.pos.y + 1;
	vec[5] = p.pos.z;
	alSourcefv(*source, AL_ORIENTATION, vec);
	return (0);
}

static int		sound_param(t_env *env, ALuint *source, t_sparam p)
{
	if (listener_param(env))
		return (-1);
	if (source_param(source, p))
		return (-1);
	if (p.fork)
	{
		alSourcef(*source, AL_REFERENCE_DISTANCE, 1);
		alSourcef(*source, AL_ROLLOFF_FACTOR, 1);
		alSourcef(*source, AL_MAX_DISTANCE, 100);
	}
	alSourcef(*source, AL_GAIN, p.volume);
	alSourcef(*source, AL_PITCH, p.pitch);
	return (0);
}

int 			fork_sound(t_env *env, t_dynarray *s, int source, t_sparam p)
{
	ALuint 	tmp;
	t_sound	*sound;

	sound = dyacc(s, source);
	if (sound == NULL || p.fork == false)
		return (0);
	alGenSources(1, &tmp);
	if (sound_param(env, &tmp, p))
		return (-1);
	alSourcei(tmp, AL_BUFFER, (ALint)sound->samples->buffer);
	alSourcePlay(tmp);
	return (0);
}

int 			play_sound(t_env *env, t_dynarray *s, int source, t_sparam p)
{
	ALint 	status;
	t_sound	*sound;

	sound = dyacc(s, source);
	if (sound == NULL || p.play == false)
		return (0);
	sound->volume = p.volume;
	sound->pitch = p.pitch;
	alGetSourcei(sound->ambient, AL_SOURCE_STATE, &status);
	if (status == AL_PLAYING)
		return (0);
	if (sound_param(env, &sound->ambient, p))
		return (-1);
	alSourcei(sound->ambient, AL_BUFFER, (ALint)sound->samples->buffer);
	alSourcePlay(sound->ambient);
	return (0);
}
