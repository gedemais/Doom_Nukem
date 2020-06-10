#include "main.h"

static float	enemies_xz_angle(t_vec3d a, t_vec3d b)
{
	float	cross;
	float	dot;

	cross = a.x * b.z - a.z * b.x;
	dot = a.x * b.x + a.z * b.z;
	return (atan2(cross, dot));
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

static void		enemies_look_dir(t_enemy *mob)
{
	float	angle;
	float	fcos;
	float	fsin;
	t_vec3d	goal;

	goal = vec_add(mob->goal->pos, mob->goal->pos);
	goal = vec_sub(goal, mob->pos);
	angle = enemies_xz_angle(mob->head, goal);
	fcos = cos(angle);
	fsin = sin(angle);
	if (angle)
		enemies_rotate_mob(mob, fcos, fsin);
}

static void		enemies_moves_pitch(t_enemy *mob)
{
	t_vec3d	goal;

	goal = vec_add(mob->goal->pos, mob->goal->pos);
	mob->pitch.x = (goal.x - mob->pos.x) * mob->speed;
	mob->pitch.y = (goal.y - mob->pos.y) * mob->speed;
	mob->pitch.z = (goal.z - mob->pos.z) * mob->speed;	
}

void			enemies_goals(t_enemy *mob)
{
	enemies_moves_pitch(mob);
	enemies_look_dir(mob);
}
