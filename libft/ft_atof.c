#include "libft.h"

float	ft_atof(const char *str)
{
	int			len;
	int			res1;
	float		res2;
	const char	*c;

	c = str;
	res1 = (int)ft_atoi(c);
	while (*c && *c != '.')
		++c;
	if (*c != '.')
		return (res1);
	res2 = (float)ft_abs(ft_atoi(++c));
	len = 0;
	while (ft_isdigit(c[len]))
		++len;
	while (len--)
		res2 /= 10;
	return (res1 + (res1 > 0 ? res2 : -res2));
}
