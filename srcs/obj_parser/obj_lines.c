#include "main.h"

int		new_mesh(t_map *map, char *line, int *mesh)
{
	static char	zone[sizeof(t_mesh)] = "";

	free_dynarray(&map->pool);
	map->pstate = PS_OBJ;
	if (init_dynarray(&map->pool, sizeof(t_vec3d), 0))
		return (-1);
	if (push_dynarray(&map->meshs, &zone[0], false))
		return (-1);
	(*mesh)++;
	printf("new_mesh : %s\n", line);
	return (0);
}

int		new_vertex(t_map *map, char *line, int *mesh)
{
	t_vec3d			v;
	unsigned int	i;

	(void)mesh;
	i = 1;
	if (map->pstate != PS_VERTEXS)
	{
		printf("%d\n", map->pstate);
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
	if (push_dynarray(&map->pool, &v, false))
		return (-1);
	printf("new_vertex : %s (%f %f %f)\n", line, v.x, v.y, v.z);
	return (0);
}

int		new_face(t_map *map, char *line, int *mesh)
{
	t_mesh			*obj;
	unsigned int	i;

	i = 0;
	if (map->pstate != PS_FACES)
	{
		obj = dyacc(&map->meshs, *mesh);
		if (map->pstate != PS_END_VERTEXS)
			return (-1);
		map->pstate = PS_FACES;
	}
	printf("new_face : %s\n", line);
	return (0);
}

int		comment(t_map *map, char *line, int *mesh)
{
	(void)map;
	(void)mesh;
	(void)line;
	printf("comment : %s\n", line);
	return (0);
}

int		vertex_end(t_map *map, char *line, int *mesh)
{
	(void)line;
	(void)mesh;
	map->pstate = PS_END_VERTEXS;
	printf("vertex_end : %s\n", line);
	return (0);
}
