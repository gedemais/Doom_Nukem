#include "main.h"

// quand le joueur equipe une arme, son mesh est ajoute a la scene courante, et lie au cam_mesh
// player->current doit etre update pour afficher les stats de l'arme

static void		replace_dependencies(t_map *map, int start, int ndeps)
{
	t_mesh	*m;
	int		*d;
	int		i;
	int		j;

	i = 0;
	while (i < ndeps)
	{
		j = 0;
		m = dyacc(&map->meshs, start + i);
		while (j < m->deps.nb_cells)
		{
			d = dyacc(&m->deps, j);
			*d += start;
			j++;
		}
		i++;
	}
}

static int		copy_weapon_to_scene(t_map *map, t_weapon *w)
{
	int		start;
	int		ret;

	ret = 0;
	start = map->meshs.nb_cells;
	if (w->mesh)
	{
		if (push_dynarray(&map->meshs, w->mesh, false) || !(++ret))
			return (-1);
		w->mesh = dyacc(&map->meshs, map->meshs.nb_cells - 1);
	}
	if (w->charger)
	{
		if (push_dynarray(&map->meshs, w->charger, false) || !(++ret))
			return (-1);
		w->charger = dyacc(&map->meshs, map->meshs.nb_cells - 1);
	}
	if (w->breech)
	{
		if (push_dynarray(&map->meshs, w->breech, false) || !(++ret))
			return (-1);
		w->breech = dyacc(&map->meshs, map->meshs.nb_cells - 1);
	}
	replace_dependencies(map, start, ret);
	return (ret);
}
/*
static int		delete_weapon_from_scene(t_map *map, t_weapon *w)
{
	extract_dynarray()
	return (0);
}*/

int		link_weapon_to_cam(t_map *map, t_weapon *w)
{
	t_vec3d	offset;
	int		wmesh;
	int		index;

	printf("%s\n", __FUNCTION__);
	if ((wmesh = copy_weapon_to_scene(map, w)) <= 0)
		return (-1);
	w->scene_start = map->meshs.nb_cells - wmesh;
	w->scene_end = map->meshs.nb_cells;
	index = map->meshs.nb_cells;
	index -= wmesh;
	map->nmesh += wmesh;
	if (map->cam.deps.byte_size == 0 // Check si le buffer du dynarray a ete alloue
		&& init_dynarray(&map->cam.deps, sizeof(int), 16)) // Sinon, l'init
		return (-1);
	if (push_dynarray(&map->cam.deps, &index, false))
		return (-1);
	w->dep_index = map->cam.deps.nb_cells - 1;

	offset = vec_add(w->p_offset, map->cam.corp.pos);
	translate_mesh(map, dyacc(&map->meshs, index), offset);
	return (0);
}

int		unlink_weapon(t_map *map, t_weapon *w)
{
	int		i;

	printf("%s\n", __FUNCTION__);
	i = w->scene_start;
	map->nmesh -= (w->scene_end - w->scene_start);
	while (i < w->scene_end)
	{
		extract_dynarray(&map->meshs, w->scene_start);
		i++;
	}
	extract_dynarray(&map->cam.deps, w->dep_index);
	return (0);
}
