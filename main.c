#include <stdio.h>
#include <time.h>
#include "libft/libft.h"

int		main(void)
{
	int		i = 0;
	int		len = 20;
	int		a;
	int		b;
	char	*str;
	char	c;
	int		j = 0;

	srand(time(NULL));
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (-1);

	while (true)
	{
		i = 0;
		while (i < len)
		{
			c = 0;
			while (!ft_isprint(c))
				c = rand() % 128;
			str[i] = c;
			i++;
		}
		str[i] = 0;
		printf("\ntry n%d\n", j);
		printf((const char*)str, 0);
		ft_printf((const char*)str);
		if ((a = ft_printf((const char*)str)) != (b = printf((const char*)str)))
		{
			printf("ft_printf and printf differs (%d vs %d) for format string |%s|\n", a, b, str);
			return (1);
		}
		j++;
	}
	free(str);
}
