#include "main.h"

int		new_mesh(t_parser *p, t_map *map, char **toks)
{
	static char		zone[sizeof(t_mesh)] = {0};
	t_mesh			*m;
	unsigned int	i;

	(void)p;
	i = 1;
	if (ft_tablen(toks) != 2)
		return (-1);
	if (push_dynarray(&map->meshs, &zone[0], false)
		|| !(m = dyacc(&map->meshs, map->nmesh))
		|| !(m->name = ft_strdup(toks[1]))
		|| init_dynarray(&m->faces, sizeof(t_face), 0))
		return (-1);
	map->nmesh++;
	// ajouter un mesh a map->meshs et initialiser
	// ses tableaux dynamiques de vertexs et de faces
	return (0);
}

int		new_vertex(t_parser *p, t_map *map, char **toks)
{
	t_vec3d		new;

	(void)p;
	if (ft_tablen(toks) != 4
		|| !check_float(toks[1]) || !check_float(toks[2])
		|| !check_float(toks[3]))
		return (-1);
	new.x = atof(toks[1]);
	new.y = atof(toks[2]);
	new.z = atof(toks[3]);
	if (push_dynarray(&map->pool, &new, false))
		return (-1);
	return (0);
}

int		new_face(t_parser *p, t_map *map, char **toks)
{
	t_face			face;
	t_mesh			*m;
	(void)p;
	if (ft_tablen(toks) != 4
		|| !check_number(toks[1]) || !check_number(toks[2])
		|| !check_number(toks[3]))
		return (-1);
	face.x = ft_atoi(toks[1]);
	face.y = ft_atoi(toks[2]);
	face.z = ft_atoi(toks[3]);
	if (!(m = dyacc(&map->meshs, map->nmesh - 1))
		|| push_dynarray(&m->faces, &face, false))
		return (-1);
	return (0);
}

int		vertex_end(t_parser *p, t_map *map, char **toks)
{
	(void)p;
	(void)map;
	(void)toks;
	return (0);
}

int		comment(t_parser *p, t_map *map, char **toks)
{
	(void)p;
	(void)map;
	(void)toks;
	return (0);
}
