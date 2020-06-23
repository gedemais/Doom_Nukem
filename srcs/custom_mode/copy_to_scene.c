#include "main.h"

int		copy_to_scene(t_map *dest, t_map *src, t_vec3d pos)
{
	t_mesh		new;
	t_mesh		*m;
	int			i;

	i = 0;
	while (i < src->meshs.nb_cells)
	{
		ft_memset(&new, 0, sizeof(t_mesh));
		m = dyacc(&src->meshs, i);
		new.type = 1;
		new.index = dest->nmesh;
		if (init_dynarray(&new.tris, sizeof(t_triangle), 12)
			|| copy_triangles(dest, src, m, &new)
			|| push_dynarray(&dest->meshs, &new, false))
			return (-1);
		assign_meshs(dyacc(&dest->meshs, dest->nmesh));
		translate_mesh(dest, dyacc(&dest->meshs, dest->nmesh), pos);
		dest->nmesh++;
		i++;
	}
	return (0);
}
