#include "main.h"

// quand le joueur equipe une arme, son mesh est ajoute a la scene courante, et lie au cam_mesh
// player->current doit etre update pour afficher les stats de l'arme
int		link_weapon_to_cam_cmp(t_env *env, t_weapon *w)
{
	// Push les meshs de w_map dans env->maps[env->scene]
	t_mesh		*m;
	t_weapon	*weapon;
	int			offset;
	int			i;

	i = 0;
	weapon = dyacc(&env->maps[env->scene].meshs, env->maps[env->scene].meshs.nb_cells - 1);
	while (i < w->meshs.nb_cells)
	{
		m = dyacc(&w->meshs, i);
		if (push_dynarray(&env->maps[env->scene].meshs, m, false))
			return (-1);
	}

	// Test suivi de position :
	// Appliquer les dependances aux meshs poignees des armes
	// creer une exception dans move_mesh pour la camera
	// Appliquer une dependance entre le mesh camera 
	// et la poignee de l'arme
	

	return (0);
}

// supprime le mesh de la scene (quand le personnage switch d'arme)
int		unlink_weapon(t_env *env, t_weapon w)
{
	return (0);
}
