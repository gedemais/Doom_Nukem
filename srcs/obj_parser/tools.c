#include "main.h"

int		cross_whitespaces(char *line, int *i)
{
	int		j;

	j = *i;
	while (line[j] && ft_is_whitespace(line[j]))
		j++;
	*i = j;
	return (line[j] && line[j] != '\n' ? 0 : 1);
}

int		cross_floats(char *line, int *i)
{
	int		j;

	j = *i;
	if (line[j] == '-' || line[j] == '+')
		j++;
	while (line[j] && (ft_isdigit(line[j]) || line[j] == '.'))
		j++;
	*i = j;
	return (line[j] && line[j] != '\n' ? 0 : 1);
}

t_vec3d	read_vec3d(char *tok, char start_sep, char end_sep)
{
	t_vec3d	ret;
	int		i;

	ret = (t_vec3d){};
	if (tok[0] != start_sep || tok[ft_strlen(tok) - 1] != end_sep)
	{
		ft_putendl_fd("Missing brace", 2);
		return ((t_vec3d){INFINITY, INFINITY, INFINITY, INFINITY});
	}
	i = 1;
	if (cross_whitespaces(tok, &i) || (ret.x = ft_atof(&tok[i])) == INFINITY
		|| cross_floats(tok, &i) || cross_whitespaces(tok, &i) || tok[i++] != ','
		|| cross_whitespaces(tok, &i) || (ret.y = ft_atof(&tok[i])) == INFINITY
		|| cross_floats(tok, &i) || cross_whitespaces(tok, &i) || tok[i++] != ','
		|| cross_whitespaces(tok, &i) || (ret.z = ft_atof(&tok[i])) == INFINITY)
		return ((t_vec3d){INFINITY, INFINITY, INFINITY, INFINITY});
	return (ret);
}

t_vec2d	read_vec2d(char *tok, char start_sep, char end_sep)
{
	t_vec2d	ret;
	int		i;

	ret = (t_vec2d){};
	if (tok[0] != start_sep || tok[ft_strlen(tok) - 1] != end_sep)
	{
		ft_putendl_fd("Missing brace", 2);
		return ((t_vec2d){INFINITY, INFINITY, INFINITY});
	}
	i = 1;
	if (cross_whitespaces(tok, &i) || (ret.u = ft_atof(&tok[i])) == INFINITY
		|| cross_floats(tok, &i) || cross_whitespaces(tok, &i) || tok[i++] != ','
		|| cross_whitespaces(tok, &i) || (ret.v = ft_atof(&tok[i])) == INFINITY)
		return ((t_vec2d){INFINITY, INFINITY, INFINITY});
	return (ret);
}

void	swap_bytes(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}
