#ifndef WEAPONS_H
# define WEAPONS_H

# define ACC_START 16

struct	s_weapon
{
	t_mesh	*mesh; // Mesh central de l'arme
	t_vec3d	p_offset; // Offset de la position de l'arme au joueur
	float	pitch; // Angles de l'arme dans le referentiel du joueur
	float	yaw; // ___
	float	accuracy;
	float	damages; // 0-1
	int		magazine; // Capacite du chargeur
	int		ammos; // Nombre de balles total
};

int			handle_weapons(t_env *env);
void		draw_reticule(t_env *env);

#endif
