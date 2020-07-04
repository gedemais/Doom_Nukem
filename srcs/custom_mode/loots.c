#include "main.h"

static void	replace_mobs_index(t_env *env, int delta)
{
	t_enemy	*mob;
	t_mesh	*m;
	int		i;
	int		j;

	i = 0;
	while (i < env->custom_env.mobs.nb_cells)
	{
		mob = dyacc(&env->custom_env.mobs, i);
		mob->map_start += delta;
		mob->map_end += delta;
		j = mob->map_start;
		while (j < mob->map_end)
		{
			m = dyacc(&env->edit_env.map.meshs, j);
			m->index += delta;
			j++;
		}
		i++;
	}
}

static t_mesh	*insert_loot(t_map *dest, t_map *src, t_vec3d pos, int index)
{
	t_mesh		new;
	t_mesh		*m;
	t_mesh		*ret;

	ft_memset(&new, 0, sizeof(t_mesh));
	m = dyacc(&src->meshs, 0);
	new.type = 1;
	new.index = index;
	if (init_dynarray(&new.tris, sizeof(t_triangle), 12)
		|| copy_triangles(dest, src, m, &new)
		|| insert_dynarray(&dest->meshs, &new, index))
		return (NULL);
	ret = dyacc(&dest->meshs, index);
	assign_meshs(dyacc(&dest->meshs, index));
	translate_mesh(dest, dyacc(&dest->meshs, index), pos);
	dest->nmesh++;
	return (ret);
}

static int	launch_loot(t_env *env, t_loot *loot)
{
	static int	(*loots_fts[LOOT_MAX])(t_env*) = {loot_nuke, loot_money, loot_shield, loot_ammos};
	t_loot		*l;
	int			ret;
	int			i;

	i = loot->index - 1;
	ret = loots_fts[(int)loot->id](env);
	printf("loot id : %d\n", loot->id);
	PUT
	extract_dynarray(&env->edit_env.map.meshs, loot->m->index);
	PUT
	extract_dynarray(&env->custom_env.loots, loot->index);
	PUT
	env->edit_env.map.nmesh--;
	while (i < env->custom_env.loots.nb_cells)
	{
		if (!(l = dyacc(&env->custom_env.loots, i)))
			break ;
		l->m->index--;
		i++;
	}
	PUT
//	printf("---------- lauch_loot------------\n");
//	print_mobs(env);
	replace_mobs_index(env, -1);
//	printf("---------- lauch_loot 2------------\n");
//	print_mobs(env);
//	exit(0);
	PUT
	return (ret);
}

int		spawn_loot(t_env *env, t_vec3d pos)
{
	t_dynarray	*loots;
	t_loot		loot;
	t_map		*map;
	t_enemy		*first;

	first = dyacc(&env->custom_env.mobs, 0);
	map = &env->maps[SCENE_LOOT];
	loots = &env->custom_env.loots;
	if (rand() % LOOT_FREQ > 0)
		return (0);
	loot.index = env->custom_env.loots.nb_cells;
	loot.id = rand() % LOOT_MAX;
	loot.pos = pos;
	pos.y += 2.0f;
	if (!(loot.m = insert_loot(&env->edit_env.map, map, pos, first->map_start)))
		return (-1);
	replace_mobs_index(env, 1);
	if (loots->byte_size == 0 && init_dynarray(loots, sizeof(t_loot), 0))
		return (-1);
	if (push_dynarray(loots, &loot, false))
		return (-1);
	return (0);
}

void	handle_loots(t_env *env)
{
	t_loot			*loot;
	t_vec3d			diff;
	float			dist;
	int				i;

	i = 0;
	while (i < env->custom_env.loots.nb_cells)
	{
		loot = dyacc(&env->custom_env.loots, i);
		if ((dist = vec3d_dist(env->cam.stats.pos, loot->m->corp.pos)) < EVENT_DIST)
		{
			diff = vec_sub(env->cam.stats.pos, loot->m->corp.pos);
			translate_mesh(&env->edit_env.map, loot->m, vec_fmult(diff, 0.1f));
			if (dist < 0.1f)
			{
				launch_loot(env, loot);
				return ;
			}
		}
		rotate_mesh(loot->m, loot->m->corp.pos, 0.02f, rotate_y);
		i++;
	}
}
