#include "main.h"

static void		replace_meshs(t_dynarray *mobs, int index, int delta)
{
	t_enemy	*mob;
	t_mesh	*m;
	int		i;
	int		j;

	i = index;
	while (i < mobs->nb_cells)
	{
		mob = dyacc(mobs, i);
		j = mob->map_start;
		while (j < mob->map_end - 1)
		{
			m = dyacc(&mob->map->meshs, j);
			m->index -= delta;
			assign_meshs(m);
			j++;
		}
		i++;
	}
}

static void		enemies_delete_mob(t_dynarray *mobs, t_enemy *mob, int index)
{
	int		i;
	int		tmp;
	t_enemy	*m;

	i = mob->map_start - 1;
	while (++i < mob->map_end)
	{
		extract_dynarray(&mob->map->meshs, mob->map_start);
		--mob->map->nmesh;
	}
	tmp = mob->map_end - mob->map_start;
	extract_dynarray(mobs, index);
	while (index < mobs->nb_cells)
	{
		m = dyacc(mobs, index);
		m->map_start -= tmp;
		m->map_end -= tmp;
		replace_meshs(mobs, index, tmp);
		index++;
	}
}

static bool		enemies_death_animation(t_enemy *mob, float angle)
{
	float			fcos;
	float			fsin;

	fcos = cos(angle);
	fsin = sin(angle);
	if (mob->sum_angle < 1.5f)
	{
		enemies_rotate_mob(mob, fcos, fsin, enemies_rotate_x);
		mob->sum_angle += angle;
		return (false);
	}
	if (mob->pos.y > 0)
	{
		mob->pos.y -= 0.3f;
		return (false);
	}
	return (true);
}

void			enemies_death(t_dynarray *mobs)
{
	int		i;
	t_enemy	*mob;

	i = -1;
	while (++i < mobs->nb_cells)
	{
		mob = dyacc(mobs, i);
		if (mob->hp < 1)
			if (enemies_death_animation(mob, 0.1f))
			{
				enemies_delete_mob(mobs, mob, i);
				//extract_dynarray(mobs, i);
			}
	}
}
