#include "main.h"

static bool		enemies_infinite_loop(t_enemy *mob)
{
	return (mob->end->parent->parent
		&& mob->end->parent->parent->i == mob->end->i);
}

static void		enemies_get_goal(t_enemy *mob)
{
	while (mob->end && mob->end->i != mob->goal->i)
	{
		if (mob->end->parent == NULL)
			return ;
		if (mob->end->parent->i == mob->goal->i)
		{
			mob->goal = mob->end;
			enemies_goals(mob);
			return ;
		}
		if (enemies_infinite_loop(mob))
		{
			mob->end = NULL;
			return ;
		}
		mob->end = mob->end->parent;
	}
}

static void		enemies_rotate_y(t_vec3d *v, t_vec3d m, float fcos, float fsin)
{
	float	x;
	float	z;

	x = (v->x - m.x) * fcos - (v->z - m.z) * fsin;
	z = (v->x - m.x) * fsin + (v->z - m.z) * fcos;
	v->x = x + m.x;
	v->z = z + m.z;
}

static void		enemies_rotate_mob(t_enemy *mob, float fcos, float fsin)
{
	int			i;
	int			j;
	t_mesh		*m;
	t_triangle	*t;

	enemies_rotate_y(&mob->head, (t_vec3d){}, fcos, fsin);
	i = mob->map_start - 1;;
	while (++i < mob->map_end)
	{
		m = dyacc(&mob->map->meshs, i);
		j = -1;
		while (++j < m->tris.nb_cells)
		{
			t = dyacc(&m->tris, j);
			enemies_rotate_y(&t->points[0], mob->pos, fcos, fsin);
			enemies_rotate_y(&t->points[1], mob->pos, fcos, fsin);
			enemies_rotate_y(&t->points[2], mob->pos, fcos, fsin);
		}
	}
}

static void		enemies_smooth_movement(t_enemy *mob)
{
	if (mob->i == mob->goal->i)
		return ;
	mob->pos = vec_add(mob->pos, mob->pitch);

	float	fcos = cos(mob->yaw);
	float	fsin = sin(mob->yaw);
	enemies_rotate_mob(mob, fcos, fsin);
}

void			enemies_do_movement(t_enemy *mob)
{
	t_vec3d	goal;

	mob->goal->bobstacle = 0;
	if (mob->i == mob->goal->i)
		enemies_get_goal(mob);
	if (mob->end == NULL)
		return ;
	enemies_smooth_movement(mob);
	goal = vec_add(mob->goal->pos, mob->goal->pos);
	if (astar_distance(goal, mob->pos) < 0.1f)
		mob->i = mob->goal->i;
	mob->goal->bobstacle = 1;
}
