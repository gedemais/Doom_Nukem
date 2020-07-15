#include "main.h"

static int		listener_param(t_env *env)
{
	float	vec[6];

	alListener3f(AL_POSITION, env->cam.stats.pos.x,
		env->cam.stats.pos.y, env->cam.stats.pos.z);
	alListener3f(AL_VELOCITY, 0, 0, 0);
	alListener3f(AL_DIRECTION, env->cam.stats.dir.x,
		env->cam.stats.dir.y, env->cam.stats.dir.z);
	vec[0] = env->cam.stats.dir.x;
	vec[1] = env->cam.stats.dir.y;
	vec[2] = env->cam.stats.dir.z;
	vec[3] = 0;
	vec[4] = 1;
	vec[5] = 0;
	alListenerfv(AL_ORIENTATION, vec);
	return (0);
}

static int		source_param(ALuint *source, t_sparam p)
{
	float	vec[6];

	alSource3f(*source, AL_POSITION, p.pos.x, p.pos.y, p.pos.z);
	alSource3f(*source, AL_VELOCITY, 0, 0, 0);
	alSource3f(*source, AL_DIRECTION, 0, 0, 1);
	vec[0] = 0;
	vec[1] = 0;
	vec[2] = 1;
	vec[3] = 0;
	vec[4] = 1;
	vec[5] = 0;
	alSourcefv(*source, AL_ORIENTATION, vec);
	return (0);
}

static int		sound_param(t_env *env, ALuint *source, t_sparam p)
{
	if (listener_param(env))
		return (-1);
	if (source_param(source, p))
		return (-1);
	alSourcef(*source, AL_GAIN, p.volume);
	alSourcef(*source, AL_PITCH, p.pitch);
	return (0);
}

int 			fork_sound(t_env *env, int source, t_sparam p)
{
	t_sound		*sound;
	t_sound		*fork;
	static int	current = 0;

	sound = dyacc(env->sound.sounds, source);
	current = current > SA_BUFFER - 1 ? 0 : current;
	fork = dyacc(env->sound.fork, current++);
	if (sound == NULL)
		return (-1);
	if (fork == NULL)
		return (-1);
	if (p.fork == false)
		return (0);
	if (sound_param(env, &fork->ambient, p))
		return (-1);
	alSourcei(fork->ambient, AL_BUFFER, (ALint)sound->samples->buffer);
	alSourcePlay(fork->ambient);
	return (0);
}

int 			play_sound(t_env *env, int source, t_sparam p)
{
	ALint 	status;
	t_sound	*sound;

	sound = dyacc(env->sound.sounds, source);
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
