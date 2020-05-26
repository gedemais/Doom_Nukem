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
		printf("mesh copied\n");
		if (push_dynarray(&map->meshs, w->mesh, false) || !(++ret))
			return (-1);
		w->mesh = dyacc(&map->meshs, map->meshs.nb_cells - 1);
	}
	if (w->charger)
	{
		printf("charger copied\n");
		if (push_dynarray(&map->meshs, w->charger, false) || !(++ret))
			return (-1);
		w->charger = dyacc(&map->meshs, map->meshs.nb_cells - 1);
	}
	if (w->breech)
	{
		printf("breech copied\n");
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

	printf("%s\n---------------------\n", __FUNCTION__);
	printf("%d meshs in the map (%d cells)\n", map->nmesh, map->meshs.nb_cells);
	if ((wmesh = copy_weapon_to_scene(map, w)) <= 0)
		return (-1);
	printf("%d meshs to copy\n", wmesh);
	w->scene_start = map->meshs.nb_cells - wmesh;
	w->scene_end = map->meshs.nb_cells;
	printf("scene start : %d | scene_end : %d\n", w->scene_start, w->scene_end);
	index = map->meshs.nb_cells;
	index -= wmesh;
	map->nmesh += wmesh;
	printf("%d meshs in the map (%d cells)\n", map->nmesh, map->meshs.nb_cells);
	if (map->cam.deps.byte_size == 0 // Check si le buffer du dynarray a ete alloue
		&& init_dynarray(&map->cam.deps, sizeof(int), 16)) // Sinon, l'init
		return (-1);
	if (push_dynarray(&map->cam.deps, &index, false))
		return (-1);
	w->dep_index = map->cam.deps.nb_cells - 1;

	offset = vec_add(w->p_offset, map->cam.corp.pos);
	translate_mesh(map, dyacc(&map->meshs, index), offset);
	printf("----------------------------\n");
	return (0);
}

int		unlink_weapon(t_map *map, t_weapon *w)
{
	int		i;

	printf("%s\n---------------------\n", __FUNCTION__);
	printf("previous map->nmesh = %d (%d cells)\n", map->nmesh, map->meshs.nb_cells);
	i = w->scene_start;
	map->nmesh -= (w->scene_end - w->scene_start);
	printf("new map->nmesh = %d\n", map->nmesh);
	printf("scene start : %d | scene_end : %d\n", w->scene_start, w->scene_end);
	while (i < w->scene_end)
	{
		PUT
		extract_dynarray(&map->meshs, w->scene_start);
		i++;
	}
	extract_dynarray(&map->cam.deps, w->dep_index);
	printf("final nb_cells : %d\n---------------------\n", map->meshs.nb_cells);
	return (0);
}
