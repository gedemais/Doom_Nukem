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
	printf("There\n");
	if (!m->textured) // no UVs
		return (-1);
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
	(void)env;
	(void)map;
	(void)m;
	(void)tok;
	return (0);
}

int		mapper_speed(t_env *env, t_map *map, t_mesh *m, char *tok)
{
	(void)env;
	(void)map;
	(void)m;
	(void)tok;
	return (0);
}

int		mapper_static(t_env *env, t_map *map, t_mesh *m, char *tok)
{
	(void)env;
	(void)map;
	(void)m;
	(void)tok;
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

