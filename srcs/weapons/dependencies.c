#include "main.h"

// quand le joueur equipe une arme, son mesh est ajoute a la scene courante, et lie au cam_mesh
// player->current doit etre update pour afficher les stats de l'arme

static int		copy_weapon_to_scene(t_map *map, t_weapon *w)
{
	int		ret;

	ret = 0;
	if (w->mesh)
	{
		if (push_dynarray(&map->meshs, w->mesh, false))
			return (-1);
		w->mesh = dyacc(&map->meshs, map->meshs.nb_cells - 1);
		ret++;
	}
	if (w->charger)
	{
		if (push_dynarray(&map->meshs, w->charger, false))
			return (-1);
		w->charger = dyacc(&map->meshs, map->meshs.nb_cells - 1);
		ret++;
	}
	if (w->breech)
	{
		if (push_dynarray(&map->meshs, w->breech, false))
			return (-1);
		w->breech = dyacc(&map->meshs, map->meshs.nb_cells - 1);
		ret++;
	}
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
	translate_mesh(map, w->mesh, w->p_offset);
	return (0);
}

// supprime le mesh de la scene (quand le personnage switch d'arme)

int		unlink_weapon(t_map *map, t_weapon *w)
{
	(void)map;
	(void)w;
	return (0);
}
