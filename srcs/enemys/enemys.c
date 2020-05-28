#include "main.h"

static void		movement(t_pf *a, t_enemy *mob)
{
	t_node	*current;

	current = a->end;
	if (current == NULL)
		return ;
	while (current && current != a->start)
	{
		if (current->parent == a->start)
		{
			mob->pos.x = current->x * 2;
			mob->pos.y = current->y * 2;
			mob->pos.z = current->z * 2;
			return ;
		}
		current = current->parent;
	}
}

static void		enemys_movement(t_env *env)
{
	int		i;
	t_pf	*a;
	t_enemy	*mob;

	static int	j = 0;

	a = &env->astar;
	a->end = &a->nodes[a->width - 1][a->height - 1][a->depth - 1];
	i = -1;
	while (++i < env->mobs.nb_cells)
	{
		mob = dyacc(&env->mobs, i);
		int	x = mob->pos.x / 2;
		int	y = mob->pos.y / 2;
		int	z = mob->pos.z / 2;
		a->start = &a->nodes[x][y][z];
		if (j == 0)
		{
			astar(a);
			movement(a, mob);
		}
		else if (j > 10)
			j = -1;
		++j;
	}
}

static void		enemys_to_scene(t_env *env, t_map *map)
{
	int		i;
	t_enemy	*mob;

	i = -1;
	while (++i < env->mobs.nb_cells)
	{
		mob = dyacc(&env->mobs, i);
		t_mesh *d = dyacc(&map->meshs, mob->map_start);
		translate_mesh(map, d, vec_sub(mob->pos, d->corp.pos));
	}
}

int				handle_enemys(t_env *env)
{
	t_vec3d	pos;

	pos = (t_vec3d){0, 2, 0, 0};
	if (env->mobs.nb_cells == 0)
	{
		if (create_mob(env, &env->edit_env.map, ENEMY_CUBE, pos))
			return (-1);
	}
	enemys_movement(env);
	enemys_to_scene(env, &env->edit_env.map);
	return (0);
}
