#include "main.h"


int		handle_weapons(t_env *env)
{
	// Determiner la taille du reticule :
	draw_reticule(env);
	if (print_ammos(env, env->cmp_env.player.current))
		return (-1);
	// Deplacer l'arme avec le joueur
	// (Position du joueur (up, crouch, jump) | Vitesse du joueur)

	// Dessiner le reticule

	// Si nb_bullets_loaded == 0 && nb_bullets_tot > 0
		// Recharger
	// Si le clic gauche est appuye, tirer
	return (0);
}
