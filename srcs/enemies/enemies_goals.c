#include "main.h"

static float	enemies_get_angle(t_fpoint a, t_fpoint b)
{
	float	cross;
	float	dot;

	cross = a.x * b.y - a.y * b.x;
	dot = a.x * b.x + a.y * b.y;
	return (atan2(cross, dot));
}

static void		enemies_rotate_y(t_vec3d *vec, float angle)
{
	float	x;

	x = vec->x;
	vec->x = x * cos(angle) - vec->z * sin(angle);
	vec->z = x * sin(angle) + vec->z * cos(angle);
}

static void		enemies_rotate_mob(t_enemy *mob, float angle)
{
	int			i;
	t_mesh		*m;
	t_triangle	*t;

	m = dyacc(&mob->map->meshs, mob->map_start);
	i = -1;
	while (++i < m->tris.nb_cells)
	{
		t = dyacc(&m->tris, i);
		// afficher les pts avant
		enemies_rotate_y(&t->points[0], angle);
		enemies_rotate_y(&t->points[1], angle);
		enemies_rotate_y(&t->points[2], angle);
		//aficher les pts apres
	}
}

static void		enemies_look_dir(t_enemy *mob)
{
	t_vec3d	goal;

	mob->head = (t_vec3d){ 1, 1, 0, 0};
	goal = vec_sub(mob->goal->pos, mob->pos);

	printf("A: head: ");
	print_vec(mob->head);
	printf("B: goal: ");
	print_vec(goal);
	t_fpoint	a;
	t_fpoint	b;

	a = (t_fpoint){ mob->head.x, mob->head.z };
	b = (t_fpoint){ goal.x, goal.z };

	float angle = enemies_get_angle(a, b);

	enemies_rotate_y(&mob->head, angle);
	printf("A': head' ");
	print_vec(mob->head);

	if (angle)
		enemies_rotate_mob(mob, angle);

	printf("angle: %f\n", angle);
	angle *= 180 / 3.14159;
	printf("angle: %f\n", angle);
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
