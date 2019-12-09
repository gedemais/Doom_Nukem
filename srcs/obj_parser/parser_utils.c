#include "main.h"

bool	cross_whites(char *line, unsigned int *i)
{
	while (line[*i] && ft_is_whitespace(line[*i]))
		*i += 1;
	return (line[*i] ? false : true);
}

bool	cross_floats(char *line, unsigned int *i)
{
	while (line[*i] && (ft_isdigit(line[*i])
		|| line[*i] == '-' || line[*i] == '.' || line[*i] == '+'))
		*i += 1;
	return (line[*i] ? false : true);
}
