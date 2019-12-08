#include "main.h"

bool	cross_line(char *file, unsigned int *i)
{
	while (file[*i] && file[*i] != '\n')
		(*i)++;
	return (file[*i] ? false : true);
}

bool	cross_whites(char *file, unsigned int *i)
{
	while (file[*i] && ft_is_whitespace(file[*i]))
		(*i)++;
	return (file[*i] ? false : true);
}

bool	cross_floats(char *file, unsigned int *i)
{
	while (file[*i] && (ft_isdigit(file[*i])
		|| file[*i] == '.' || file[*i] == '-' || file[*i] == '+'))
		(*i)++;
	return (file[*i] ? false : true);
}
