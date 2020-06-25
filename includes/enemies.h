#ifndef ENEMIES_H
# define ENEMIES_H

# include "main.h"

# define MAX_ENEMIES 6
# define RESPAWN_DELAY 3.0f
# define MOB_ANIMATION_DOWN 0.1f
# define MOB_ANIMATION_UP 0.1f

enum				e_enemies
{
	ENEMY_CUBE,
	ENEMY_MAX
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

void			enemies_animations(t_enemy *mob);

void			enemies_movements(t_env *env, t_pf *a);
void			enemies_do_movement(t_enemy *mob);

void			enemies_death(t_dynarray *mobs);
void			enemies_damages(t_env *env);
void			enemies_kills_annoucements(t_env *env);

void			enemies_last_rotation(t_enemy *mob, t_vec3d cam);
void			enemies_rotate_mob(t_enemy *mob, float fcos, float fsin,
		void (*rotation)(t_vec3d *v, t_vec3d m, float fcos, float fsin));

float           enemies_xz_angle(t_vec3d a, t_vec3d b);

#endif
