#include "main.h"

static unsigned char	*make_string(t_weapon w)
{
	unsigned char	*dest;
	char			*l;
	char			*m;
	char			*tmp;

	if (!(l = ft_itoa(w.loaded)))
		return (NULL);
	if (!(tmp = ft_strjoin(l, " /")))
	{
		free(l);
		return (NULL);
	}
	free(l);
	if (!(m  = ft_itoa(w.ammos)))
	{
		free(tmp);
		return (NULL);
	}
	if (!(dest = (unsigned char*)ft_strjoin(tmp, m)))
	{
		free(m);
		free(tmp);
		return (NULL);
	}
	free(m);
	free(tmp);
	return (dest);
}

int					print_ammos(t_env *env, t_weapon w)
{
	unsigned char	*s;
	t_ttf_config	*conf;

	if (!(s = make_string(w)))
		return (-1);
	conf = ttf_config();
	conf->size = AMMO_FONT_SIZE;
	my_string_put(env, (t_point){900, 670}, FONT_AMMOS, s);
	free(s);
	return (0);
}
