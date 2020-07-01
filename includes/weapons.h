#ifndef WEAPONS_H
# define WEAPONS_H

# define ACC_START 24 // a remplacer par le calcul de precision
# define ACC_SPREAD 0.6f // a remplacer par l'accuracy de l'arme
# define AMMO_FONT_SIZE 24
# define W_NAME_FONT_SIZE 16

# define RELOAD_TIME 2.5f // seconds
# define RELOAD_SPEED 0.05f;
# define HITMARKER_T 5

enum	e_weapons
{
	W_FAMAS,
	W_AK47,
	W_SAWED_OFF,
	W_GLOCK_18,
	W_AUG,
	W_UMP45,
	W_MAG7,
	W_GALIL,
	W_NEGEV,
	W_TEC9,
	W_MAX
};

enum	e_shoot_mode
{
	SMODE_SBS,
	SMODE_SINGLE,
	SMODE_FULL_AUTO,
	SMODE_MAX
};

struct	s_weapon
{
	t_vec3d		start;
	t_map		*w_map; // map du .obj de l'arme
	t_mesh		*mesh; // Mesh central de l'arme
	t_mesh		*breech; // Mesh culasse de l'arme
	t_sample	*shoot;
	t_sample	*reload;
	char		*name;
	float		accuracy; // 0-1
	int			reticle;
	int			damages; // 0-100
	int			magazine; // Capacite du chargeur
	int			loaded; // Nombre de balles dans le chargeur
	int			ammos; // Nombre de balles en stock
	int			max_ammos;
	int			cadency;
	int			index;
	float		reloading;
	float		shooting;
	float		recoil;
	bool		ready;
	bool		shot;
	char		shoot_mode;
	//	Cadence de tir
	//	sprite de flamme ?
};

int			init_weapons(t_env *env);

int			shoot_current_weapon(t_env *env);
void		shoot_animation(t_env *env, t_weapon *w);
int			reload_current_weapon(t_env *env);
void		reload_animation(t_env *env, t_weapon *w);

int			handle_weapons(t_env *env);
void		draw_reticule(t_env *env);
int			print_ammos(t_env *env, t_weapon *w);
int			weapons_hud(t_env *env);
void		assign_weapons_stats(t_env *env);
void		assign_meshs(t_mesh *m);

#endif
