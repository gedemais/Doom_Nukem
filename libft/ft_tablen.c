#include "libft.h"

int		ft_tablen(char **tab)
{
	int		ret;

	ret = 0;
	if (!tab)
		return (-1);
	while (tab[ret])
		ret++;
	return (ret);
}
