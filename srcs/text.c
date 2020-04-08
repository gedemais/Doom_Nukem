#include "main.h"

int		load_fonts(t_env *env)
{
	unsigned int	i;

	i = 0;
	if (FT_Init_FreeType(&env->ttfs.fontlib)
		&& write(2, FT_LIB, ft_strlen(FT_LIB)))
		return (-1);
	while (i < FONT_MAX)
	{
		i++;
	}
	return (0);
}
