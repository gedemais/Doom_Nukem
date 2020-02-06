#include "main.h"

int		new_mesh(t_map *map, char **toks)
{
	static char		zone[sizeof(t_mesh)] = {0};
	t_mesh			*m;
	unsigned int	i;

	i = 1;
	if (ft_tablen(toks) != 2)
		return (-1);
	if (push_dynarray(&map->meshs, &zone[0], false)
		|| !(m = dyacc(&map->meshs, map->nmesh))
		|| !(m->name = ft_strdup(toks[1]))
		|| init_dynarray(&m->txts, sizeof(t_vec2d), 0)
		|| init_dynarray(&m->faces, sizeof(t_face), 0))
		return (-1);
	map->nmesh++;
	// ajouter un mesh a map->meshs et initialiser
	// ses tableaux dynamiques de vertexs et de faces
	return (0);
}

int		new_vertex(t_map *map, char **toks)
{
	t_vec3d		new;

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

int		new_txt_vertex(t_map *map, char **toks)
{
	t_mesh		*m;
	t_vec2d		txt_coor;

	if (!(m = dyacc(&map->meshs, map->nmesh - 1)) || ft_tablen(toks) != 3
		|| !check_float(toks[1]) || !check_float(toks[2]))
		return (-1);
	if (!m->textured)
		m->textured = true;
	txt_coor.u = atof(toks[1]);
	txt_coor.v = atof(toks[2]);
	if (push_dynarray(&map->txt_pool, &txt_coor, false))
		return (-1);
	return (0);
}

int		new_face(t_map *map, char **toks)
{
	t_face			face;
	t_mesh			*m;

	if (ft_tablen(toks) != 4 || load_face(toks, map, &face))
		return (-1);
	//face.x = ft_atoi(toks[1]);
	//face.y = ft_atoi(toks[2]);
	//face.z = ft_atoi(toks[3]);
	if (!(m = dyacc(&map->meshs, map->nmesh - 1))
		|| push_dynarray(&m->faces, &face, false))
		return (-1);
	return (0);
}

int		vertex_end(t_map *map, char **toks)
{
	(void)map;
	(void)toks;
	return (0);
}

int		comment(t_map *map, char **toks)
{
	(void)map;
	(void)toks;
	return (0);
}
