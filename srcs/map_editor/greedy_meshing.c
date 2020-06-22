#include "main.h"

static t_node	*get_end(t_ed_map *m, t_dynarray *n, t_vec3d dim, t_vec3d pos)
{
	char	type;

	type = m->map[(int)pos.x][(int)pos.y][(int)pos.z];
	while (pos.z < m->depth - 1
		&& type == m->map[(int)pos.x][(int)pos.y][(int)pos.z])
		++pos.z;
	return (dyacc(n, nodes_3d_1d(dim, pos)));
}

static void		new_bloc(t_map *map, t_node *start, t_node *end)
{
	int 	i = -1;
	t_mesh	*mstart = NULL;
	t_mesh	*mend = NULL;
	t_mesh	*mesh;

	while (++i < map->nmesh)
	{
		mesh = dyacc(&map->meshs, i);
		if (mesh->m_pos[0] == (int)start->pos.x
			&& mesh->m_pos[1] == (int)start->pos.y
			&& mesh->m_pos[2] == (int)start->pos.z)
			mstart = mesh;
		if (mesh->m_pos[0] == (int)end->pos.x
			&& mesh->m_pos[1] == (int)end->pos.y
			&& mesh->m_pos[2] == (int)end->pos.z)
			mend = mesh;
	}
	printf("start: ");
	print_vec(start->pos);
	printf("%d %d %d\n", mstart->m_pos[0], mstart->m_pos[1], mstart->m_pos[2]);
	printf("end: ");
	print_vec(end->pos);
	printf("%d %d %d\n", mend->m_pos[0], mend->m_pos[1], mend->m_pos[2]);

	if (mstart && mend)
	{
		t_triangle	*tri;
		for (int j = 0; j < mstart->tris.nb_cells; j++)
		{
			tri = dyacc(&mstart->tris, j);
			if (tri->sp > BTXT_NONE)
			{
				printf("start");
				for (int k = 0; k < 3; k++)
				{
					print_vec(tri->points[k]);
				}
				printf("\n");
			}
		}
		for (int j = 0; j < mend->tris.nb_cells; j++)
		{
			tri = dyacc(&mend->tris, j);
			if (tri->sp > BTXT_NONE)
			{
				printf("end ");
				for (int k = 0; k < 3; k++)
				{
					print_vec(tri->points[k]);
				}
				printf("\n");
			}
		}
	}
	exit(0);
}

static void		fusion()
{

}

void			greedy_meshing(t_env *env, t_map *map)
{
	return ;
	t_dynarray	nodes;
	t_ed_map	*matrix = &env->edit_env.new_map;

	init_dynarray(&nodes, sizeof(t_node), env->astar.d_nodes.nb_cells);
	nodes.nb_cells = env->astar.d_nodes.nb_cells;
	ft_memcpy(nodes.c, env->astar.d_nodes.c, nodes.byte_size);

	int 	x;
	int 	y;
	int 	z;
	t_vec3d	dim = (t_vec3d){ matrix->width, matrix->height, matrix->depth, 0 };
	t_vec3d	pos;
	t_node	*node;
	t_node	*end;

	x = -1;
	while (++x < matrix->width)
	{
		y = -1;
		while (++y < matrix->height)
		{
			z = -1;
			while (++z < matrix->depth)
			{
				pos = (t_vec3d){ x, y, z, 0 };
				node = dyacc(&nodes, nodes_3d_1d(dim , pos)); 
				if (node && ft_inbounds(matrix->map[x][y][z], 1, 31))
				{
					printf("%d %d %d\n", x, y, z);
					end = get_end(matrix, &nodes, dim, pos);
					if (node->i != end->i)
					{
						printf("ni: %d ei: %d\n",
							node->i, end->i);
						new_bloc(map, node, end);
						fusion();
					}
				}
			}
		}
	}
	exit(0);
}
