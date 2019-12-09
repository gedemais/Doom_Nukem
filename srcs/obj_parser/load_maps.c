#include "main.h"

static char	*maps_paths(unsigned int index)
{
	char	*paths[SCENE_MAX] = {"resources/maps/object.obj"};

	return (paths[index]);
}

static int	parse_line(t_map *map, char *line, int *mesh)
{
	static char		types[NB_LINES_TYPE] = {'o', 'v', 's', 'f', '#'};
	static int		(*obj_lines[NB_LINES_TYPE])(t_map *, char *, int*) = {
						&new_mesh, &new_vertex, &vertex_end, &new_face, &comment};
	unsigned int	i;

	i = 0;
	while (i < NB_LINES_TYPE)
	{
		if (line[0] == types[i])
			return (obj_lines[i](map, line, mesh));
		i++;
	}
	return (0);
}

static int	parse_map(t_map *map, char *path)
{
	char	*line;
	int		fd;
	int		mesh;

	mesh = 0;
	if ((fd = open(path, O_RDONLY)) == -1
		|| init_dynarray(&map->meshs, sizeof(t_mesh), 0))
		return (-1);
	map->pstate = PS_OBJ;
	while (get_next_line(fd, &line))
	{
		if (parse_line(map, line, &mesh))
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	return (0);
}

int			load_maps(t_env *env)
{
	unsigned int	i;

	i = 0;
	printf("Load maps\n");
	while (i < SCENE_MAX)
	{
		printf("%s\n", maps_paths(i));
		if (parse_map(&env->maps[i], maps_paths(i)) != 0)
			return (-1);
		i++;
	}
	return (0);
}
