#include "main.h"

static char	*maps_paths(unsigned int index)
{
	char	*paths[SCENE_MAX] = {	"resources/maps/object.obj",
									"resources/maps/ut.obj",
									"resources/maps/ut2.obj"};

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
	return (-1);
}

static int	parse_map(t_map *map, char *path)
{
	char	*line;
	int		fd;

	map->nmesh = -1;
	if ((fd = open(path, O_RDONLY)) == -1
		|| init_dynarray(&map->meshs, sizeof(t_mesh), 0)
		|| init_dynarray(&map->pool, sizeof(t_vec3d), 0))
		return (-1);
	map->tri = MAGIC_VAL;
	map->pstate = PS_OBJ;
	while (get_next_line(fd, &line))
		if (parse_line(map, line, &map->nmesh))
		{
			ft_putstr_fd(OBJ_LINE_FORMAT, 2);
			ft_putendl_fd(path, 2);
			free(line);
			return (-1);
		}
		else
			free(line);
	map->nmesh++;
	return (0);
}

int			load_maps(t_env *env)
{
	unsigned int	i;

	i = 0;
	printf("Load maps\n");
	while (i < SCENE_MAX)
	{
		if (parse_map(&env->maps[i], maps_paths(i)) != 0)
			return (-1);
		printf("%s (%d meshs)\n", maps_paths(i), env->maps[i].nmesh);
		i++;
	}
	return (0);
}
