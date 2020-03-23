#include "main.h"

int		mapper_texture(t_env *env, t_map *map, t_mesh *m, char *tok)
{
	t_triangle	*t;
	char		*path;
	int			i;

	(void)map;
	i = -1;
	if (ft_strlen(tok) <= 2)
		return (0);
	if (!m->textured)
	{
		ft_putendl_fd("No texture vertexs for this mesh", 2);
		return (-1);
	}
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
	while ((t = dyacc(&m->tris, ++i)))
		t->sp = &m->sprite;
	return (0);
}

int		mapper_position(t_env *env, t_map *map, t_mesh *m, char *tok)
{
	t_vec3d		pos;

	(void)env;
	(void)map;
	if (ft_strlen(tok) <= 2)
		return (0);
	else
		pos = read_vec3d(tok, '{', '}');
	if (pos.x == INFINITY)
	{
		ft_putendl_fd("Invalid mesh position's vector", 2);
		return (-1);
	}
	tp_mesh(m, pos);
	return (0);
}

int		mapper_speed(t_env *env, t_map *map, t_mesh *m, char *tok)
{
	t_vec3d		speed;

	(void)env;
	(void)map;
	if (ft_strlen(tok) <= 2)
		return (0);
	else
		speed = read_vec3d(tok, '[', ']');
	if (speed.x == INFINITY)
	{
		ft_putendl_fd("Invalid mesh speed's vector", 2);
		return (-1);
	}
	m->corp.vo = speed;
	return (0);
}

int		mapper_static(t_env *env, t_map *map, t_mesh *m, char *tok)
{
	(void)env;
	(void)map;
	if (!ft_inbounds(ft_strlen(tok), 4, 5))
		return (-1);
	if (!ft_strcmp(tok, "false"))
		m->corp.stats = false;
	else if (!ft_strcmp(tok, "true"))
		m->corp.stats = true;
	else
	{
		ft_putendl_fd("Invalid static qualifier", 2);
		return (-1);
	}
	return (0);
}

int		mapper_deps(t_env *env, t_map *map, t_mesh *m, char *tok)
{
	(void)env;
	(void)map;
	(void)m;
	(void)tok;
	return (0);
}

