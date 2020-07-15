#include "main.h"

static int 		volume_events(t_env *env)
{
	if (env->events.keys[KEY_F])
	{
		env->sound.volume += 0.01f;
		env->sound.volume = env->sound.volume > 1 ? 1 : env->sound.volume;
		if (sound_system(env, 0,
				sp_overall(0, SA_MAX - 1, sp_volume(0.01f, 0))))
			return (-1);
	}
	else if (env->events.keys[KEY_V])
	{
		env->sound.volume -= 0.01f;
		env->sound.volume = env->sound.volume < 0 ? 0 : env->sound.volume;
		if (sound_system(env, 0,
				sp_overall(0, SA_MAX - 1, sp_volume(-0.01f, 0))))
			return (-1);
	}
	return (0);
}

static int 		pitch_events(t_env *env)
{
	if (env->events.keys[KEY_G])
	{
		if (sound_system(env, 0,
				sp_overall(0, SA_MAX - 1, sp_volume(0, 0.01f))))
			return (-1);
	}
	else if (env->events.keys[KEY_B])
	{
		if (sound_system(env, 0,
				sp_overall(0, SA_MAX - 1, sp_volume(0, -0.01f))))
			return (-1);
	}
	return (0);
}

static int 		sound_events(t_env *env, int source)
{
	(void)source;
	if (volume_events(env)
		|| pitch_events(env))
		return (-1);
	return (0);
}

int				sound_manager(t_env *env, int source)
{
	if (sound_events(env, source))
		return (-1);
	if (source >= SA_MAX || source < 0)
		return (0);
	if (sound_system(env, 0, sp_no_sound(0, SA_PNL)) == 0)
		if (sound_system(env, source,
				sp_play(env->sound.volume, PITCH, env->cam.stats.pos)))
			return (-1);
	return (0);
}
