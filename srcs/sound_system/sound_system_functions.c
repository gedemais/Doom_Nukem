#include "main.h"

static int		sound_param(t_env *env, ALuint *source, t_sparam p)
{
	float	angle;

	angle = xz_angle(env->cam.stats.dir, vec_sub(p.pos, env->cam.stats.pos));
	angle *= 180 / 3.1415;
	printf("angle: %f\n", angle);
	angle = angle > 0 ? 1 : -1;
	angle = -1;
	printf("angle: %d\n", (int)angle);
	alListener3f(AL_POSITION, env->cam.stats.pos.x * (int)angle,
		env->cam.stats.pos.y, env->cam.stats.pos.z);
	alListener3f(AL_VELOCITY, 0, 0, 0);
	alListener3f(AL_DIRECTION, p.pos.x * (int)angle, p.pos.y, p.pos.z);
	alSource3f(*source, AL_POSITION, p.pos.x * (int)angle, p.pos.y, p.pos.z);
	alSource3f(*source, AL_VELOCITY, 0, 0, 0);
	alSource3f(*source, AL_DIRECTION, env->cam.stats.pos.x * (int)angle,
		env->cam.stats.pos.y, env->cam.stats.pos.z);
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

int 			sound_volume(t_env *env, t_dynarray *s, int source, t_sparam p)
{
	ALint 	status;
	t_sound	*sound;

	sound = dyacc(s, source);
	if (sound == NULL || p.sound == false)
		return (0);
	alGetSourcei(sound->ambient, AL_SOURCE_STATE, &status);
	if (status == AL_PLAYING)
	{
		sound->volume += p.volume;
		sound->volume = sound->volume > env->volume
			? env->volume : sound->volume;
		sound->volume = sound->volume < 0 ? 0 : sound->volume;
		alSourcef(sound->ambient, AL_GAIN, sound->volume);
		sound->pitch += p.pitch;
		sound->pitch = sound->pitch > 2 ? 2 : sound->pitch;
		sound->pitch = sound->pitch < 0 ? 0 : sound->pitch;
		alSourcef(sound->ambient, AL_PITCH, sound->pitch);
	}
	return (0);
}
