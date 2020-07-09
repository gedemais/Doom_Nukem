#include "main.h"

t_sparam		sp_no_sound(int start, int end)
{
	int			tmp;
	t_sparam	param;

	ft_memset(&param, 0, sizeof(t_sparam));
	start = start < 0 ? 0 : start;
	start = start > SA_MAX - 1 ? SA_MAX - 1 : start;
	end = end < 0 ? 0 : end;
	end = end > SA_MAX - 1 ? SA_MAX - 1 : end;
	if (end < start)
	{
		tmp = end;
		end = start;
		start = tmp;
	}
	param.start = start;
	param.end = end;
	param.no_sound = true;
	return (param);	
}

t_sparam		sp_stop()
{
	t_sparam	param;

	ft_memset(&param, 0, sizeof(t_sparam));
	param.stop = true;
	return (param);
}

int 			stop_sound(t_dynarray *sounds, int source)
{
	t_sound	*sound;

	sound = dyacc(sounds, source);
	if (sound == NULL)
		return (0);
	alSourceStop(sound->ambient);	
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
