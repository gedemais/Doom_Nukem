#include "main.h"

int		mapper_texture(t_env *env, t_mesh *m, char *tok)
{
	t_triangle	*t;
	char		*path;
	int			i;

	i = 0;
	while (i < m->tris.nb_cells)
	{
		t = dyacc(&m->tris, i);
		t->sp = NULL;
		i++;
	}
	if (ft_strlen(tok) <= 2)
		return (0);
	if (tok[0] != '(' || tok[ft_strlen(tok) - 1] != ')')
	{
		ft_putendl_fd("Missing parentheses", 2);
		return (-1);
	}
	if (!(path = ft_strndup(&tok[1], ft_strlen(&tok[1]) - 1)))
		return (-1);
	if (load_texture(&env->mlx, path, &m->sprite))
		return (-1);
	free(path);
	i = -1;
	while ((t = dyacc(&m->tris, ++i)))
		t->sp = t->textured ? &m->sprite : NULL;
	return (0);
}

int		mapper_position(t_env *env, t_mesh *m, char *tok)
{
	t_vec3d		pos;
	t_map		*map;

	(void)env;
	if (ft_strlen(tok) <= 2)
		return (0);
	else
		pos = read_vec3d(tok, '{', '}');
	map = *current_map();
	if (pos.x == INFINITY)
	{
		ft_putendl_fd("Invalid mesh position's vector", 2);
		return (-1);
	}
	tp_mesh(map, m, pos);
	return (0);
}

int		mapper_speed(t_env *env, t_mesh *m, char *tok)
{
	t_vec3d		speed;

	(void)env;
	if (ft_strlen(tok) <= 2)
		return (0);
	else
		speed = read_vec3d(tok, '[', ']');
	if (speed.x == INFINITY)
	{
		ft_putendl_fd("Invalid mesh speed's vector", 2);
		return (-1);
	}
	if (!strcmp(m->name, "Cube"))
		print_vec(speed);
	m->corp.v = speed;
	return (0);
}

int		mapper_static(t_env *env, t_mesh *m, char *tok)
{
	t_map	*map;

	(void)env;
	map = *current_map();
	if (!ft_inbounds(ft_strlen(tok), 4, 5))
		return (-1);
	if (!ft_strcmp(tok, "false"))
		map->stats[m->index] = false;
	else if (!ft_strcmp(tok, "true"))
		map->stats[m->index] = true;
	else
	{
		ft_putendl_fd("Invalid static qualifier", 2);
		return (-1);
	}
	map->stats_cpy[m->index]= map->stats[m->index];
	return (0);
}

int		mapper_deps(t_env *env, t_mesh *m, char *tok)
{
	t_mesh	*master;
	t_map	*map;
	int		i;

	(void)env;
	i = -1;
	if (!tok || !tok[0])
		return (0);
	map = *current_map();
	while (++i < map->meshs.nb_cells)
	{
		master = dyacc(&map->meshs, i);
		if (!ft_strcmp(master->name, tok))
			break ;
	}
	if (i == map->meshs.nb_cells || (!master->deps.byte_size
		&& init_dynarray(&master->deps, sizeof(int), 0)))
	{
		ft_putendl_fd("Mesh dependencie not found", 2);
		return (-1);
	}
	if (push_dynarray(&master->deps, &m->index, false))
		return (-1);
	return (0);
}
