#ifndef ENEMYS_H
# define ENEMYS_H

enum				e_enemys
{
	ENEMY_CUBE,
	ENEMY_MAX
};

struct				s_enemy
{
	t_vec3d		pos;
	t_map		*map; // map contenant le mob
	t_mesh		*mesh;
	int			pv;
	int			damages;
	float		speed;
	int			map_start;
	int			map_end;
};

int			handle_enemys(t_env *env);
int			create_mob(t_env *env, t_map *map, char type, t_vec3d pos);

#endif
