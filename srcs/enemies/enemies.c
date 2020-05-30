#include "main.h"

static void		enemies_get_start(t_pf *a, t_enemy *mob)
{
	int	sx;
	int	sy;
	int	sz;

	sx = mob->pos.x / 2;
	sy = mob->pos.y / 2;
	sz = mob->pos.z / 2;
	a->start = &a->nodes[sx][sy][sz];
}

static void		enemies_get_goal(t_pf *a, t_enemy *mob)
{
	t_node	*current;

	current = a->end;
	if (current == NULL)
		return ;
	enemies_get_start(a, mob);
	while (current && current != a->start)
	{
		if (current->parent == a->start)
		{
			mob->goal = current;
			return ;
		}
		current = current->parent;
	}
}

static void		enemies_smooth_movement(t_enemy *mob)
{
	float	x;
	float	y;
	float	z;
	float	speed = 0.1f;

	x = mob->goal->x * 2;
	y = mob->goal->y * 2;
	z = mob->goal->z * 2;
	mob->pos.x += (x - mob->pos.x) * speed;
	mob->pos.y += (y - mob->pos.y) * speed;
	mob->pos.z += (z - mob->pos.z) * speed;
}

static void		enemies_do_movement(t_pf *a, t_enemy *mob)
{
	t_vec3d	v;
	static int i = 0;

	if (i++ == 0) {
		PUT
		enemies_get_goal(a, mob);
	}
	v.x = mob->goal->x * 2;
	v.y = mob->goal->y * 2;
	v.z = mob->goal->z * 2;
	if (vec_dst(v, mob->pos) < 0.1f)
	{
		mob->pos.x = mob->goal->x * 2;
		mob->pos.y = mob->goal->y * 2;
		mob->pos.z = mob->goal->z * 2;
		enemies_get_goal(a, mob);
	}
	enemies_smooth_movement(mob);
}

static void		enemies_get_end(t_pf *a)
{
	int	ex;
	int	ey;
	int	ez;

	ex = a->width - 1;
	ey = a->height - 1;
	ez = a->depth - 1;
	a->end = &a->nodes[ex][ey][ez];
	while (astar_distance(*a->start, *a->end) > 5)
	{
		ex = a->end->x / 2 + a->start->x / 2;
		ey = a->end->y / 2 + a->start->y / 2;
		ez = a->end->z / 2 + a->start->z / 2;
		a->end = &a->nodes[ex][ey][ez];
	}
}

static int		check_mob_pos(t_pf *a, t_enemy *mob)
{
	if (a->end == NULL)
		return (-1);
	return (mob->pos.x == a->end->x * 2
		&& mob->pos.y == a->end->y * 2
		&& mob->pos.z == a->end->z * 2);
}

static void		enemies_movement(t_env *env)
{
	int		i;
	t_enemy	*mob;

	i = -1;
	while (++i < env->mobs.nb_cells)
	{
		mob = dyacc(&env->mobs, i);
		enemies_get_start(&env->astar, mob);
		if (check_mob_pos(&env->astar, mob))
		{
			enemies_get_end(&env->astar);
			astar(&env->astar);
		}
		enemies_do_movement(&env->astar, mob);
	}
}

static void		enemies_to_scene(t_env *env, t_map *map)
{
	int		i;
	t_mesh	*m;
	t_enemy	*mob;

	i = -1;
	while (++i < env->mobs.nb_cells)
	{
		mob = dyacc(&env->mobs, i);
		m = dyacc(&map->meshs, mob->map_start);
		translate_mesh(map, m, vec_sub(mob->pos, m->corp.pos));
	}
}

static int		test_mob(t_env *env)
{
	t_vec3d	pos;

	pos = (t_vec3d){0, 2, 0, 0};
	if (env->mobs.nb_cells == 0)
	{
		if (create_mob(env, &env->edit_env.map, ENEMY_CUBE, pos))
			return (-1);
	}
	return (0);
}

int				handle_enemies(t_env *env)
{
	if (test_mob(env))
		return (-1);
	enemies_movement(env);
	enemies_to_scene(env, &env->edit_env.map);
	return (0);
}
