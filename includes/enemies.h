#ifndef ENEMIES_H
# define ENEMIES_H

# include "main.h"

# define MOB_PEACE_TIME 30
# define INTER_WAVE 10
# define SPAWN_SPEED_SUB 0.1f
# define HIT_REWARD 10
# define KILL_REWARD 60
# define KILL_DELAY 120

# define MOB_START_HP 50
# define MOB_START_SPEED 0.05f
# define MOB_LSTART 6
# define MOB_PV_COEFF 1.3f
# define MOB_SPEED_COEFF 1.1f
# define MOB_NB_ADD 4

# define MAX_ENEMIES 12
# define LOOT_FREQ 12
# define RESPAWN_DELAY 3.0f
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


int				handle_enemies(t_env *env);

int				create_mob(t_env *env, t_map *map, char type, t_vec3d pos);

int				handle_loots(t_env *env);
void			enemies_animations(t_enemy *mob);

void			enemies_movements(t_env *env, t_pf *a);
void			enemies_do_movement(t_enemy *mob);

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
