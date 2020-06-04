#ifndef ENEMIES_H
# define ENEMIES_H

# include "main.h"

# define MAX_ENEMIES 5

enum				e_enemies
{
	ENEMY_CUBE,
	ENEMY_MAX
};

struct				s_enemy
{
	int			pv;
	int			damages;
	int			map_start;
	int			map_end;
	float		speed;
	t_vec3d		pas;
	t_vec3d		pos;
	t_node		*goal;
	t_map		*map;
};

int				handle_enemies(t_env *env);

int				create_mob(t_env *env, t_map *map, char type, t_vec3d pos);

void			enemies_movements(t_env *env);
void			enemies_do_movement(t_pf *a, t_enemy *mob);

#endif
