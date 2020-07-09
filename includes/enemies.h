#ifndef ENEMIES_H
# define ENEMIES_H

# include "main.h"

# define MAX_ENEMIES 1
# define LOOT_FREQ 12
# define RESPAWN_DELAY 3.0f
# define ENEMIES_NOISE_DELAY 50
# define MOB_ANIMATION_DOWN 0.1f
# define MOB_ANIMATION_UP 0.1f

# define DIST_TO_PLAYER 1.8f

enum				e_enemies
{
	ENEMY_CORONA,
	//ENEMY_MAGE,
	ENEMY_MAX
};

enum				e_damages
{
	EDAMAGES_CORONA = 10,
	EDAMAGES_MAGE = 35
};

enum				e_loots_id
{
	LOOT_NUKE,
	LOOT_MONEY,
	LOOT_SHIELD,
	LOOT_AMMOS,
	LOOT_MAX
};

struct				s_loot
{
	t_mesh			*m;
	t_vec3d			pos;
	int				index;
	char			id;
};

struct				s_enemy
{
	int 		i;
	int			hp;
	int			damages;
	int			map_start;
	int			map_end;
	int			peace;
	int			noise;
	float		down;
	float		up;
	float		sum_angle;
	float		speed;
	float		yaw;
	bool		dead;
	bool		up_token;
	t_vec3d		head;
	t_vec3d		offset;
	t_vec3d		pitch;
	t_vec3d		pos;
	t_node		*goal;
	t_node		*end;
	t_map		*map;
};

void			print_mobs(t_env *env); // a tej

int				handle_enemies(t_env *env);

int				create_mob(t_env *env, t_map *map, char type, t_vec3d pos);

void			enemies_animations(t_env *env, t_enemy *mob);
void			enemies_movements(t_env *env, t_pf *a);
void			enemies_do_movement(t_env *env, t_enemy *mob);

int				enemies_death(t_env *env, t_dynarray *mobs);
int				enemies_damages(t_env *env);
void			enemies_kills_annoucements(t_env *env);

int				spawn_loot(t_env *env, t_vec3d pos);
int				loot_nuke(t_env *env);
int				loot_money(t_env *env);
int				loot_shield(t_env *env);
int				loot_ammos(t_env *env);

void			enemies_last_rotation(t_enemy *mob, t_vec3d cam);
void			enemies_rotate_mob(t_enemy *mob, float fcos, float fsin,
		void (*rotation)(t_vec3d *v, t_vec3d m, float fcos, float fsin));

float           xz_angle(t_vec3d a, t_vec3d b);

#endif
