#include "main.h"

static t_node	*enemies_get_closest_node(t_pf *a, t_vec3d pos)
{
	float	dst;
	float	tmp;
	int		nb[3];
	t_node	*ret;

	pos = vec_fdiv(pos, 2);
	dst = INFINITY;
	nb[0] = -1;
	while (++nb[0] < a->width)
	{
		nb[1] = -1;
		while (++nb[1] < a->height)
		{
			nb[2] = -1;
			while (++nb[2] < a->depth)
			{
				tmp = astar_distance(pos, a->nodes[nb[0]][nb[1]][nb[2]].pos);
				if (tmp < dst)
				{
					dst = tmp;
					ret = &a->nodes[nb[0]][nb[1]][nb[2]];
				}
			}
		}
	}
	return (ret);
}

static void		enemies_get_goal(t_pf *a, t_enemy *mob)
{
	t_node	*current;

	current = a->end;
	if (current == NULL)
		return ;
	a->start = enemies_get_closest_node(a, mob->pos);
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
	float	speed = 0.2f;
	t_vec3d	pos;

	pos = vec_fmult(mob->goal->pos, 2);
	mob->pos.x += (pos.x - mob->pos.x) * speed;
	mob->pos.y += (pos.y - mob->pos.y) * speed;
	mob->pos.z += (pos.z - mob->pos.z) * speed;
}

static void		enemies_do_movement(t_pf *a, t_enemy *mob)
{
	t_vec3d	v;

	v = vec_fmult(a->start->pos, 2);
	if (mob->pos.x == v.x
		&& mob->pos.y == v.y
		&& mob->pos.z == v.z)
	{
		enemies_get_goal(a, mob);
	}
	v = vec_fmult(mob->goal->pos, 2);
	if (astar_distance(v, mob->pos) < 0.1f)
	{
		mob->pos = v;
		enemies_get_goal(a, mob);
	}
	enemies_smooth_movement(mob);
}

static void		enemies_get_end(t_pf *a)
{
	int	i;
	int	ex;
	int	ey;
	int	ez;

	ex = a->width - 1;
	ey = a->height - 1;
	ez = a->depth - 1;
	a->end = &a->nodes[ex][ey][ez];
	while (astar_distance(a->start->pos, a->end->pos) > 5)
	{
		ex = a->end->pos.x / 2 + a->start->pos.x / 2;
		ey = a->end->pos.y / 2 + a->start->pos.y / 2;
		ez = a->end->pos.z / 2 + a->start->pos.z / 2;
		a->end = &a->nodes[ex][ey][ez];
		if (a->end->bobstacle == 1)
		{
			i = -1;
			while (++i < NEIGHBOURG)
				if (a->end->nghbr[i]->bobstacle == 0)
					a->end = a->end->nghbr[i];
		}
	}
}

static int		check_mob_pos(t_pf *a, t_enemy *mob)
{
	return (a->end == NULL
		|| (mob->pos.x == a->end->pos.x * 2
		&& mob->pos.y == a->end->pos.y * 2
		&& mob->pos.z == a->end->pos.z * 2));
}

static void		enemies_movement(t_env *env)
{
	int		i;
	t_enemy	*mob;
	t_pf	*a;

	a = &env->astar;
	i = -1;
	while (++i < env->mobs.nb_cells)
	{
		mob = dyacc(&env->mobs, i);
		a->start = enemies_get_closest_node(a, mob->pos);
		if (check_mob_pos(a, mob))
		{
			enemies_get_end(a);
			astar(a);
		}
		enemies_do_movement(a, mob);
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
		translate_mesh(map, m,
			vec_sub(mob->pos, m->corp.pos));
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
