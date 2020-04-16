#include "main.h"

int		new_mesh(t_map *map, char **toks)
{
	static char		zone[sizeof(t_mesh)] = {};
	t_mesh			*m;

	map->cmtl = -1;
	if (ft_tablen(toks) != 2)
		return (-1);
	if (push_dynarray(&map->meshs, &zone[0], false)
		|| !(m = dyacc(&map->meshs, map->nmesh))
		|| !(m->name = ft_strdup(toks[1]))
		|| init_dynarray(&m->txts, sizeof(t_vec2d), 0)
		|| init_dynarray(&m->faces, sizeof(t_face), 0))
		return (-1);
	m->index = map->nmesh;
	map->nmesh++;
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
	t_mtl			*mtl;

	face.textured = false;
	if (ft_tablen(toks) != 4)
		return (-1);
	if (map->cmtl >= 0)
	{
		if (!(mtl = dyacc(&map->mtls, map->cmtl)))
			return (-1);
		mtl->color[3] = (1.0f - mtl->alpha) * 255;
		face.color = *(int*)&mtl->color[0];
		face.textured = mtl->textured;
	}
	if (load_face(toks, map, &face))
		return (-1);
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

int		mtllib(t_map *map, char **toks)
{
	unsigned int	i;

	i = 0;
	if (*init_parser())
		return (0);
	if (ft_tablen(toks) != 2 || (map->mtls.byte_size == 0
		&& init_dynarray(&map->mtls, sizeof(t_mtl), 0)))
		return (-1);
	if (parse_mtl(toks[1], &map->mtls))
		return (-1);
	return (0);
}

int		usemtl(t_map *map, char **toks)
{
	t_mtl	*m;
	int		i;

	i = 0;
	if (ft_tablen(toks) != 2)
		return (-1);
	while (i < map->mtls.nb_cells)
	{
		if ((m = dyacc(&map->mtls, i)) && !ft_strcmp(toks[1], m->name))
		{
			map->cmtl = i;
			return (0);
		}
		i++;
	}
	map->cmtl = -1;
	return (-1);
}
