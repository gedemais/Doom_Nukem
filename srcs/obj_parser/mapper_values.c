#include "main.h"

static int	get_static_or_not(t_map *map, char *s, t_mesh *m)
{
	if (!ft_inbounds(ft_strlen(s), 4, 5))
		return (-1);
	if (ft_strcmp(s, "true") && ft_strcmp(s, "false"))
		return (-1);
	map->stats[m->index] = (bool)(!ft_strcmp(s, "true"));
	return (0);
}

static int	get_txt_path(t_env *env, char *s, t_mesh *m)
{
	int			i;

	i = 0;
	if (s[0] != '(' || s[ft_strlen(s) - 1] != ')')
		return (-1);
	while (s[i] && s[i] != ')')
		i++;
	s[ft_strlen(s) - 1] = 0;
	if (load_texture(&env->mlx, &s[1], &m->sprite))
	{
		printf("%s : no such file or directory\n", s);
		return (-1);
	}
	i = -1;
	while (++i < m->tris.nb_cells)
		((t_triangle*)dyacc(&m->tris, i))->sp = &m->sprite;
	return (0);
}

static int	get_pos_speed(t_mesh *m, char *s, bool pos)
{
	t_vec3d			p;
	unsigned int	i;

	i = 1;
	if (s[0] != (pos ? '{' : '[') || s[ft_strlen(s) - 1] != (pos ? '}' : ']')
		|| check_float(&s[1]) || (p.x = atof(&s[1]) == INFINITY))
		return (-1);
	while (ft_isdigit(s[i]) || s[i] == '.' || s[i] == '-' || s[i] == '+')
		i++;
	if (s[i++] != ',')
		return (-1);
	while (ft_is_whitespace(s[i]))
		i++;
	if (check_float(&s[i]) || (p.y = atof(&s[i]) == INFINITY))
		return (-1);
	while (ft_isdigit(s[i]) || s[i] == '.' || s[i] == '-' || s[i] == '+')
		i++;
	if (s[i++] != ',')
		return (-1);
	while (ft_is_whitespace(s[i]))
		i++;
	if (check_float(&s[i]) || (p.z = atof(&s[i]) == INFINITY))
		return (-1);
	tp_mesh(m, p);
	return (0);
}

int			check_line(t_env *env, t_map *map, t_mesh *m, char **stats)
{
	t_triangle	*t;
	int			i;

	i = 0;
	if ((ft_strlen(stats[1]) > 2 && get_pos_speed(m, stats[1], true))
		|| (ft_strlen(stats[2]) > 2 && get_pos_speed(m, stats[2], false)))
		return (-1);
	if (get_static_or_not(map, stats[3], m)
		|| (ft_strlen(stats[4]) > 2 && get_txt_path(env, stats[4], m)))
		return (-1);
	if (ft_strlen(stats[4]) == 2)
		while (i < m->tris.nb_cells)
		{
			t = dyacc(&m->tris, i);
			t->textured = false;
			i++;
		}
	return (0);
}
