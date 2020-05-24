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
	int		wmesh;
	int		index;

	t_mesh	*m;

	m = w->w_map->meshs.c;

	if ((wmesh = copy_weapon_to_scene(map, w)) <= 0)
		return (-1);
	index = map->meshs.nb_cells;
	index -= wmesh;
	map->nmesh += wmesh;
	if (map->cam.deps.byte_size == 0 // Check si le buffer du dynarray a ete alloue
		&& init_dynarray(&map->cam.deps, sizeof(int), 16)) // Sinon, l'init
		return (-1);
	if (push_dynarray(&map->cam.deps, &index, false))
		return (-1);
	translate_mesh(map, dyacc(&map->meshs, index), w->p_offset);
	return (0);
}

// supprime le mesh de la scene (quand le personnage switch d'arme)

int		unlink_weapon(t_map *map, t_weapon *w)
{
	(void)map;
	(void)w;
	return (0);
}
