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
