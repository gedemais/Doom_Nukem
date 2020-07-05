#include "main.h"

t_sparam		sp_fork(float volume, t_vec3d pos)
{
	t_sparam	param;

	volume = volume > 1 ? 1 : volume;
	volume = volume < 0 ? 0 : volume;
	ft_memset(&param, 0, sizeof(t_sparam));
	param.fork = true;
	param.volume = volume;
	param.pos = pos;
	return (param);
}

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

t_sparam		sp_overall(int start, int end, t_sparam p)
{
	int			tmp;
	t_sparam	param;

	param = p;
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
	param.overall = true;
	return (param);
}

t_sparam		sp_play(float volume, t_vec3d pos)
{
	t_sparam	param;

	volume = volume > 1 ? 1 : volume;
	volume = volume < 0 ? 0 : volume;
	ft_memset(&param, 0, sizeof(t_sparam));
	param.play = true;
	param.volume = volume;
	param.pos = pos;
	return (param);
}

t_sparam		sp_stop()
{
	t_sparam	param;

	ft_memset(&param, 0, sizeof(t_sparam));
	param.stop = true;
	return (param);
}

t_sparam		sp_volume(float voffset, t_vec3d pos)
{
	t_sparam	param;

	voffset = voffset > 1 ? 1 : voffset;
	voffset = voffset < -1 ? -1 : voffset;
	ft_memset(&param, 0, sizeof(t_sparam));
	param.sound = true;
	param.volume = voffset;
	param.pos = pos;
	return (param);
}
