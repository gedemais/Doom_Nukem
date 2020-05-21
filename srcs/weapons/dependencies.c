#include "main.h"

// quand le joueur equipe une arme, son mesh est ajoute a la scene courante, et lie au cam_mesh
// player->current doit etre update pour afficher les stats de l'arme
int		link_weapon_to_cam_cmp(t_env *env, t_weapon *w)
{

	// Test suivi de position :
	// Appliquer les dependances aux meshs poignees des armes
	// Appeler move_mesh lors d'un deplacement de la camera
	// Appliquer une dependance entre le mesh camera 
	// et la poignee de l'arme
	

	return (0);
}

// supprime le mesh de la scene (quand le personnage switch d'arme)
int		unlink_weapon(t_env *env, t_weapon w)
{
	return (0);
}
