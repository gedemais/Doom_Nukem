#include "main.h"

// quand le joueur equipe une arme, son mesh est ajoute a la scene courante, et lie au cam_mesh
// player->current doit etre update pour afficher les stats de l'arme
int		link_weapon_to_cam(t_env *env, t_weapon w)
{
	// Push les meshs de w_map dans env->maps[env->scene]
	return (0);
}

// supprime le mesh de la scene (quand le personnage switch d'arme)
int		unlink_weapon(t_env *env, t_weapon w)
{
	return (0);
}
