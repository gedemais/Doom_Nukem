#include "main.h"

void			enemies_rotate_y(t_vec3d *v, t_vec3d m, float fcos, float fsin)
{
	float	x;
	float	z;

	x = (v->x - m.x) * fcos - (v->z - m.z) * fsin;
	z = (v->x - m.x) * fsin + (v->z - m.z) * fcos;
	v->x = x + m.x;
	v->z = z + m.z;
}

void			enemies_rotate_x(t_vec3d *v, t_vec3d m, float fcos, float fsin)
{
	float	y;
	float	z;

	y = (v->y - m.y) * fcos - (v->z - m.z) * fsin;
	z = (v->y - m.y) * fsin + (v->z - m.z) * fcos;
	v->y = y + m.y;
	v->z = z + m.z;
}

void			enemies_rotate_mob(t_enemy *mob, float fcos, float fsin,
		void (*rotation)(t_vec3d *v, t_vec3d m, float fcos, float fsin))
{
	int			i;
	int			j;
	t_vec3d		middle;
	t_mesh		*mesh;
	t_triangle	*tri;

	middle = vec_add(mob->pos, mob->offset);
	rotation(&mob->head, (t_vec3d){}, fcos, fsin);
	i = mob->map_start - 1;;
	while (++i < mob->map_end)
	{
		mesh = dyacc(&mob->map->meshs, i);
		j = -1;
		while (++j < mesh->tris.nb_cells)
		{
			tri = dyacc(&mesh->tris, j);
			rotation(&tri->points[0], middle, fcos, fsin);
			rotation(&tri->points[1], middle, fcos, fsin);
			rotation(&tri->points[2], middle, fcos, fsin);
		}
	}
}

void			enemies_last_rotation(t_enemy *mob, t_vec3d cam)
{
	float	fcos;
	float	fsin;
	t_vec3d	goal;

	goal = vec_sub(cam, mob->pos);
	mob->yaw = enemies_xz_angle(mob->head, goal) * 0.5f;
	fcos = cos(mob->yaw);
	fsin = sin(mob->yaw);
	enemies_rotate_mob(mob, fcos, fsin, enemies_rotate_y);
}
