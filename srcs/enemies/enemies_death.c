#include "main.h"

static void		replace_meshs(t_enemy *mob, int delta)
{
	t_mesh	*m;
	int		i;

	i = mob->map_start;
	while (i < mob->map_end)
	{
		m = dyacc(&mob->map->meshs, i);
		m->index -= delta;
		assign_meshs(m);
		i++;
	}
}

static int		enemies_delete_mob(t_env *env, t_dynarray *mobs, t_enemy *mob, int index)
{
	int		i;
	int		tmp;
	t_enemy	*m;
	t_mesh	*mesh;

	(void)env;
	i = mob->map_start - 1;
	while (++i < mob->map_end)
	{
		mesh = dyacc(&mob->map->meshs, mob->map_start);
		free_mesh(mesh);
		if (extract_dynarray(&mob->map->meshs, mob->map_start))
			return (-1);
		--mob->map->nmesh;
	}
	tmp = mob->map_end - mob->map_start;
	if (extract_dynarray(mobs, index))
		return (-1);
	while (index < mobs->nb_cells)
	{
		m = dyacc(mobs, index);
		m->map_start -= tmp;
		m->map_end -= tmp;
		replace_meshs(m, tmp);
		index++;
	}
	return (0);
}

static bool		enemies_death_animation(t_enemy *mob, float angle)
{
	float			fcos;
	float			fsin;

	fcos = cos(angle);
	fsin = sin(angle);
	if (mob->sum_angle < 1.5f)
	{
		enemies_rotate_mob(mob, fcos, fsin, rotate_x);
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

int			enemies_death(t_env *env, t_dynarray *mobs)
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
				if (spawn_loot(env, mob->pos))
					return (-1);
				enemies_delete_mob(env, mobs, mob, i);
			}
	}
	return (0);
}
