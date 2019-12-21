#include "libft.h"

void	ft_free_ctab(char **tab)
{
	unsigned int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
