#ifndef WEAPONS_H
# define WEAPONS_H

# define ACC_START 16 // a remplacer par le calcul de precision
# define ACC_SPREAD 0.6f // a remplacer par l'accuracy de l'arme
# define AMMO_FONT_SIZE 24

enum	e_weapons
{
	W_FAMAS,
	W_AK47,
	W_SAWED_OFF,
	W_GLOCK_18,
	W_AUG,
	W_UMP45,
	W_MAX
};

struct	s_weapon
{
	char	*name;
	t_mesh	*mesh; // Mesh central de l'arme
	t_vec3d	p_offset; // Offset de la position de l'arme au joueur
	float	pitch; // Angles de l'arme dans le referentiel du joueur
	float	yaw; // ___
	float	accuracy; // 0-1
	float	damages; // 0-100
	int		magazine; // Capacite du chargeur
	int		loaded; // Nombre de balles dans le chargeur
	int		ammos; // Nombre de balles en stock
	//	Son
	//	Cadence de tir
	//	sprite de flamme ?
};

struct	s_ttf_config
{
	int		color;
	int		size;
};

int			init_weapons(t_env *env);

int			handle_weapons(t_env *env);
void		draw_reticule(t_env *env);
int			print_ammos(t_env *env, t_weapon w);

#endif
