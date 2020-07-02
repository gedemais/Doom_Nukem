#include "main.h"

t_sparam		sp_fork(float volume)
{
	t_sparam	param;

	volume = volume > 1 ? 1 : volume;
	volume = volume < 0 ? 0 : volume;
	ft_memset(&param, 0, sizeof(t_sparam));
	param.stop = false;
	param.overall = false;
	param.fork = true;
	param.pause = 0;
	param.sound = false;
	param.volume = volume;
	return (param);
}

t_sparam		sp_play(float volume)
{
	t_sparam	param;

	volume = volume > 1 ? 1 : volume;
	volume = volume < 0 ? 0 : volume;
	ft_memset(&param, 0, sizeof(t_sparam));
	param.stop = false;
	param.overall = false;
	param.fork = false;
	param.pause = 0;
	param.sound = false;
	param.volume = volume;
	return (param);
}

t_sparam		sp_overall(float volume)
{
	t_sparam	param;

	ft_memset(&param, 0, sizeof(t_sparam));
	param.stop = false;
	param.overall = true;
	param.fork = false;
	param.pause = 0;
	param.sound = false;
	param.volume = volume;
	return (param);
}

t_sparam		sp_stop()
{
	t_sparam	param;

	ft_memset(&param, 0, sizeof(t_sparam));
	param.stop = true;
	param.overall = false;
	param.fork = false;
	param.pause = 0;
	param.sound = false;
	param.volume = 0;
	return (param);
}

t_sparam		sp_volume(float volume)
{
	t_sparam	param;

	volume = volume > 1 ? 1 : volume;
	volume = volume < 0 ? 0 : volume;
	ft_memset(&param, 0, sizeof(t_sparam));
	param.stop = false;
	param.overall = false;
	param.fork = true;
	param.pause = 0;
	param.sound = true;
	param.volume = volume;
	return (param);
}
