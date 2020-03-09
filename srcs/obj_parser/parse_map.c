/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 03:27:58 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/09 14:09:26 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static inline int	get_line_type(char *c, t_parser *p, char states[PS_MAX][PS_MAX])
{
	char			*qualis[PS_MAX] = {"o", "v", "vt", "s", "f", "#", "mtllib",
										"usemtl"};
	unsigned int	i;

	i = 0;
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
	int				(*lines_fts[PS_MAX])(t_map*, char**) = {
					new_mesh, new_vertex, new_txt_vertex, vertex_end, new_face,
					comment, mtllib, usemtl};
	unsigned int	j;

	j = 0;
	if (!(p->toks = ft_strsplit(p->lines[i], "\n\t\r "))
		|| get_line_type(p->toks[0], p, states))
	{
		printf("Line %d\n", i);
		return (-1);
	}
	if (p->state == PS_COMMENT)
		return (0);
	if (!(*init_parser()) && lines_fts[(int)p->state](map, p->toks))
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
		new->txt[0].w = 1.0f;

		t = dyacc(&map->txt_pool, f->ty - 1);
		new->txt[1].u = t->u;
		new->txt[1].v = t->v;
		new->txt[1].w = 1.0f;

		t = dyacc(&map->txt_pool, f->tz - 1);
		new->txt[2].u = t->u;
		new->txt[2].v = t->v;
		new->txt[2].w = 1.0f;

		new->mesh = m;
		new->textured = true;
	}
	else
	{
		new->textured = false;
		if (map->mtls.nb_cells > 0)
			new->color = f->color;
		else
			new->color = 0xffffff;
	}

}

static int	load_map_data(t_map *map)
{
	t_triangle	new;
	t_mesh		*m;
	t_face		*f;
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
//			new.color = 0xffffff;

			if (push_dynarray(&m->tris, &new, false))
				return (-1);
		}
		//printf("mesh [%d] : %d triangles\n", i, m->tris.nb_cells);
	}
	return (0);
}

static int	init_map_parser(t_map *map, t_parser *parser, char *path, char states[PS_MAX][PS_MAX])
{
	unsigned int	i;
	int				fd;

	i = 0;
	map->nmesh = 0;
	if ((fd = open(path, O_RDONLY)) == -1
		|| !(parser->file = read_file(fd))
		|| !(parser->lines = ft_strsplit(parser->file, "\n"))
		|| init_dynarray(&map->pool, sizeof(t_vec3d), 0)
		|| init_dynarray(&map->txt_pool, sizeof(t_vec2d), 0)
		|| init_dynarray(&map->meshs, sizeof(t_mesh), 0))
		return (-1);
	parser->state = PS_COMMENT;
	while (parser->lines[i] && parser->state == PS_COMMENT)
	{
		if (parse_line(parser, map, i, states))
			return (-1);
		i++;
	}
	if (!parser->lines[i]
		|| (parser->state != PS_OBJ && parser->state != PS_MTLLIB))
		return (-1);
	return (0);
}

int			parse_map(t_map *map, char *path, char states[PS_MAX][PS_MAX])
{
	t_parser		parser;
	unsigned int	i;

	i = 0;

	*init_parser() = true;
	if (init_map_parser(map, &parser, path, states))
		return (-1);
	*init_parser() = false;

	while (parser.lines[i])
	{
		//printf("%s (line %d)\n", parser.lines[i], i);
		if (parse_line(&parser, map, i, states))
			return (-1);
		i++;
	}
	if (load_map_data(map))
		return (-1);
	ft_free_ctab(parser.lines);
	free(parser.file);
//	exit(0);
	return (0);
}
