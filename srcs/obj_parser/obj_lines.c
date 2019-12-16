#include "main.h"

int		new_mesh(t_map *map, char *line, int *mesh)
{
	static char	zone[sizeof(t_triangle)] = {0};

//	printf("line %d in %s\n", __LINE__, __FILE__);
	printf("%s\n", __FUNCTION__);
	if (map->pstate != PS_FACES && map->pstate != PS_OBJ)
		return (-1);
	map->tri = MAGIC_VAL;
	map->pstate = PS_OBJ;
	if (push_dynarray(&map->meshs, &zone[0], false))
		return (-1);
	(*mesh)++;
	(void)line;
	return (0);
}

int		new_vertex(t_map *map, char *line, int *mesh)
{
	t_vec3d			v;
	unsigned int	i;

	(void)mesh;
	printf("%s\n", __FUNCTION__);
	i = 1;

	if (map->pstate != PS_VERTEXS)
	{
		if (map->pstate != PS_OBJ)
			return (-1);
		map->pstate = PS_VERTEXS;
	}
	if (cross_whites(line, &i))
		return (-1);
	v.x = atof(&line[i]);
	if (cross_floats(line, &i) || cross_whites(line, &i))
		return (-1);
	v.y = atof(&line[i]);
	if (cross_floats(line, &i) || cross_whites(line, &i))
		return (-1);
	v.z = atof(&line[i]);
	v.w = 1.0f;
	if (push_dynarray(&map->pool, &v, false)
		|| !(cross_floats(line, &i)))
		return (-1);
	return (0);
}

int		new_face(t_map *map, char *line, int *mesh)
{
	t_mesh			*obj;
	unsigned int	i;
	int				n;

	i = 1;
	obj = dyacc(&map->meshs, *mesh);
	printf("%s\n", __FUNCTION__);

	if (map->pstate != PS_FACES)
	{
		if (map->pstate != PS_END_VERTEXS
			|| !(obj->tris = (t_triangle*)malloc(sizeof(t_triangle)
			* map->pool.nb_cells * 50)))
			return (-1);
		obj->nb_tris = 0;
		map->pstate = PS_FACES;
	}

	if (cross_whites(line, &i))
		return (-1);
	n = ft_atoi(&line[i]) - 1;
	ft_memcpy(&obj->tris[map->tri].points[0], dyacc(&map->pool, n), sizeof(t_vec3d));
	if (cross_floats(line, &i) || cross_whites(line, &i))
		return (-1);

	n = ft_atoi(&line[i]) - 1;
	ft_memcpy(&obj->tris[map->tri].points[1], dyacc(&map->pool, n), sizeof(t_vec3d));
	if (cross_floats(line, &i) || cross_whites(line, &i))
		return (-1);

	n = ft_atoi(&line[i]) - 1;
	ft_memcpy(&obj->tris[map->tri].points[2], dyacc(&map->pool, n), sizeof(t_vec3d));
	if (!(cross_floats(line, &i)))
		return (-1);

	map->tri++;
	obj->nb_tris++;
	return (0);
}

int		comment(t_map *map, char *line, int *mesh)
{
	(void)map;
	(void)mesh;
	(void)line;
	printf("%s\n", __FUNCTION__);
	//printf("comment : %s\n", line);
	return (0);
}

int		vertex_end(t_map *map, char *line, int *mesh)
{
	(void)line;
	(void)mesh;
	printf("%s\n", __FUNCTION__);
	map->pstate = PS_END_VERTEXS;
	map->tri = 0;
	//printf("vertex_end : %s\n", line);
	return (0);
}
