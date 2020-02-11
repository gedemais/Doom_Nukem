#include "main.h"

static inline int	get_line_type(char *c, t_parser *p, char states[PS_MAX][PS_MAX])
{
	char			*qualis[PS_MAX] = {"o", "v", "vt", "s", "f", "#"};
	unsigned int	i;

	i = 0;
	if (ft_strlen(c) != 1 && ft_strlen(c) != 2)
		return (-1);
	while (i < PS_MAX)
	{
		if (ft_strlen(c) == ft_strlen(qualis[i])
			&& !ft_strcmp(c, qualis[i]))
		{
			p->tstate = (char)i;
			if (!states[(int)p->state][(int)p->tstate])
				return (-1);
			p->state = p->tstate;
			return (0);
		}
		i++;
	}
	return (1);
}

static int	parse_line(t_parser *p, t_map *map, unsigned int i, char states[PS_MAX][PS_MAX])
{
	int				(*lines_fts[PS_MAX])(t_map*, char**) = {new_mesh,
						new_vertex, new_txt_vertex, vertex_end, new_face, comment};
	unsigned int	j;

	j = 0;
	if (!(p->toks = ft_strsplit(p->lines[i], "\n\t\r "))
		|| get_line_type(p->toks[0], p, states))
		return (-1);
	if (p->state == PS_COMMENT)
		return (0);
	if (lines_fts[(int)p->state](map, p->toks))
		return (-1);
	ft_free_ctab(p->toks);
	return (0);
}

static void	access_faces(t_triangle *new, t_map *map, t_face *f, t_mesh *m)
{
	t_vec2d	*t;

	ft_memcpy(&new->points[0], dyacc(&map->pool, f->x - 1), sizeof(t_vec3d));
	ft_memcpy(&new->points[1], dyacc(&map->pool, f->y - 1), sizeof(t_vec3d));
	ft_memcpy(&new->points[2], dyacc(&map->pool, f->z - 1), sizeof(t_vec3d));
	new->points[0].w = 1.0f;
	new->points[1].w = 1.0f;
	new->points[2].w = 1.0f;

	if (m->textured)
	{
		t = dyacc(&map->txt_pool, f->tx - 1);
		new->txt[0].u = t->u;
		new->txt[0].v = t->v;

		t = dyacc(&map->txt_pool, f->ty - 1);
		new->txt[1].u = t->u;
		new->txt[1].v = t->v;

		t = dyacc(&map->txt_pool, f->tz - 1);
		new->txt[2].u = t->u;
		new->txt[2].v = t->v;

		new->mesh = m;
	}
}

static int	load_map_data(t_map *map)
{
	t_mesh		*m;
	t_face		*f;
	t_triangle	new;
	int			i;
	int			j;

	i = -1;
	while (++i < map->nmesh)
	{
		j = -1;
		if (!(m = dyacc(&map->meshs, i))
			|| (init_dynarray(&m->tris, sizeof(t_triangle), m->faces.nb_cells)))
			return (-1);
		while (++j < m->faces.nb_cells)
		{
			if (!(f = dyacc(&m->faces, j)) || (f->x - 1 >= map->pool.nb_cells
				|| f->y - 1 >= map->pool.nb_cells || f->z - 1 >= map->pool.nb_cells))
				return (-1);

			access_faces(&new, map, f, m);

			if (push_dynarray(&m->tris, &new, false))
				return (-1);
		}
		printf("mesh [%d] : %d triangles\n", i, m->tris.nb_cells);
	}
	return (0);
}

int			parse_map(t_map *map, char *path, char states[PS_MAX][PS_MAX])
{
	t_parser		parser;
	char			*file;
	int				fd;
	unsigned int	i;

	i = 0;
	map->nmesh = 0;
	if ((fd = open(path, O_RDONLY)) == -1
		|| !(file = read_file(fd))
		|| !(parser.lines = ft_strsplit(file, "\n"))
		|| init_dynarray(&map->pool, sizeof(t_vec3d), 0)
		|| init_dynarray(&map->txt_pool, sizeof(t_vec2d), 0)
		|| init_dynarray(&map->meshs, sizeof(t_mesh), 0))
		return (-1);
	parser.state = PS_COMMENT;
	while (parser.lines[i] && parser.state == PS_COMMENT)
	{
		if (parse_line(&parser, map, i, states))
			return (-1);
		i++;
	}
	if (!parser.lines[i] || parser.state != PS_OBJ)
		return (-1);
	while (parser.lines[i])
	{
		if (parse_line(&parser, map, i, states))
		{
			printf("line %d\n", i);
			return (-1);
		}
		i++;
	}
	if (load_map_data(map))
		return (-1);
	ft_free_ctab(parser.lines);
	free(file);
	return (0);
}
