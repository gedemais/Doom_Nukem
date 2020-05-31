#include "main.h"

static t_node	*enemies_get_closest_node(t_pf *a, t_vec3d pos)
{
	float	dst;
	float	tmp;
	int		nb[3];
	t_node	*node;

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
					node = &a->nodes[nb[0]][nb[1]][nb[2]];
				}
			}
		}
	}
	return (node);
}

static void		enemies_get_pas(t_enemy *mob)
{
	float	speed = 0.1f;
	t_vec3d	goal;

	goal = vec_add(mob->goal->pos, mob->goal->pos);
	mob->pas.x = (goal.x - mob->pos.x) * speed;
	mob->pas.y = (goal.y - mob->pos.y) * speed;
	mob->pas.z = (goal.z - mob->pos.z) * speed;	
}

static void		enemies_get_goal(t_pf *a, t_enemy *mob)
{
	t_node	*current;

	current = a->end;
	if (current == NULL)
		return ;
	while (current && current != a->start)
	{
		if (current->parent == a->start)
		{
			mob->goal = current;
			enemies_get_pas(mob);
			return ;
		}
		current = current->parent;
	}
}

static void		enemies_smooth_movement(t_enemy *mob)
{
	t_vec3d	goal;

	goal = vec_add(mob->goal->pos, mob->goal->pos);
	if (mob->pos.x == goal.x
		&& mob->pos.y == goal.y
		&& mob->pos.z == goal.z)
		return ;
	mob->pos.x += mob->pas.x;
	mob->pos.y += mob->pas.y;
	mob->pos.z += mob->pas.z;
}

static void		enemies_do_movement(t_pf *a, t_enemy *mob)
{
	t_vec3d	start;

	start = vec_add(a->start->pos, a->start->pos);
	if (mob->pos.x == start.x
		&& mob->pos.y == start.y
		&& mob->pos.z == start.z)
		enemies_get_goal(a, mob);
	enemies_smooth_movement(mob);
	start = vec_add(mob->goal->pos, mob->goal->pos);
	if (astar_distance(start, mob->pos) < 0.1f)
		mob->pos = start;
}

static void		enemies_get_end(t_pf *a)
{
	int		i;
	t_vec3d	end;

	end.x = a->width - 1;
	end.y = a->height - 1;
	end.z = a->depth - 1;
	a->end = enemies_get_closest_node(a, end);
	while (astar_distance(a->start->pos, a->end->pos) > 5)
	{
		end.x = a->end->pos.x / 2 + a->start->pos.x / 2;
		end.y = a->end->pos.y / 2 + a->start->pos.y / 2;
		end.z = a->end->pos.z / 2 + a->start->pos.z / 2;
		a->end = enemies_get_closest_node(a, end);
		if (a->end->bobstacle == 1)
		{
			i = -1;
			while (++i < NEIGHBOURG)
				if (a->end->nghbr[i]->bobstacle == 0)
					a->end = a->end->nghbr[i];
		}
	}
}

static int		enemies_astar_detection(t_pf *a, t_enemy *mob)
{
	t_vec3d	v;

	if (a->end == NULL)
		return (-1);
	v = vec_add(a->end->pos, a->end->pos);
	return (mob->pos.x == v.x
		&& mob->pos.y == v.y
		&& mob->pos.z == v.z);
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
		a->start = enemies_get_closest_node(a, vec_fdiv(mob->pos, 2));
		if (enemies_astar_detection(a, mob))
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
