#include "main.h"

void	switch_current_weapon(t_camp_env *cmp_env, int button)
{
	int		index;

	index = cmp_env->player.current->index;
	if (button == BUTTON_SCROLL_UP)
	{
		index = (index == W_MAX - 1) ? 0 : index + 1;
		// unlink current weapon
		cmp_env->player.current = dyacc(&cmp_env->player.weapons, index);
		// link current weapon
	}
	else if (button == BUTTON_SCROLL_DOWN)
	{
		index = (index == 0) ? W_MAX - 1 : index - 1;
		// unlink current weapon
		cmp_env->player.current = dyacc(&cmp_env->player.weapons, index);
		// link current weapon
	}
}

int		handle_weapons(t_env *env)
{
	t_camp_env	*cmp_env;

	cmp_env = &env->cmp_env;
	// Deplacer l'arme avec le joueur

	// Dessiner le reticule

	// Si nb_bullets_loaded == 0 && nb_bullets_tot > 0
		// Recharger
	// Si le clic gauche est appuye, tirer
	return (0);
}
