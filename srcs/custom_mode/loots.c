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

static t_mesh	*insert_loot(t_map *dest, t_map *src, t_vec3d pos, int index[2])
{
	t_mesh		new;
	t_mesh		*m;
	t_mesh		*ret;

	ft_memset(&new, 0, sizeof(t_mesh));
	printf("cube n%d\n", index[1]);
	m = dyacc(&src->meshs, index[1]);
	new.type = 1;
	new.index = index[0];
	if (init_dynarray(&new.tris, sizeof(t_triangle), 12)
		|| copy_triangles(dest, src, m, &new)
		|| insert_dynarray(&dest->meshs, &new, index[0]))
		return (NULL);
	ret = dyacc(&dest->meshs, index[0]);
	assign_meshs(dyacc(&dest->meshs, index[0]));
	translate_mesh(dest, dyacc(&dest->meshs, index[0]), pos);
	dest->nmesh++;
	return (ret);
}

static int	launch_loot(t_env *env, t_loot *loot)
{
	static int	(*loots_fts[LOOT_MAX])(t_env*) = {loot_nuke, loot_money, loot_shield, loot_ammos};
	t_loot		*l;
	int			tmp;
	int			ret;
	int			i;

	i = loot->index;
	ret = loots_fts[(int)loot->id](env);

	printf("---------- lauch_loot 0 ------------\n");
	print_mobs(env);
	//sleep(1);

	printf("%d loots\n", env->custom_env.loots.nb_cells);

	tmp = loot->m->index;
	while (loot->index >= env->custom_env.loots.nb_cells)
		loot->index--;
	if (loot->index == -1)
		return (-1);
	printf("extract loot %d\n", loot->index);
	extract_dynarray(&env->custom_env.loots, loot->index);

	printf("---------- lauch_loot 1 ------------\n");
	print_mobs(env);
	//sleep(1);

	printf("%d loots\n", env->custom_env.loots.nb_cells);
	env->edit_env.map.nmesh--;
	printf("i = %d\n", i);
	while (i < env->custom_env.loots.nb_cells)
	{
		PUT
		if (!(l = dyacc(&env->custom_env.loots, i)))
		{
			PUT1
			break ;
		}
		printf("before : %d\n", l->m->index);
		l->m->index--;
		l->m = dyacc(&env->edit_env.map.meshs, l->m->index);
		printf("after : %d\n", l->m->index);
		i++;
	}

	printf("extract mesh %d from scene\n", tmp);
	extract_dynarray(&env->edit_env.map.meshs, tmp);

	printf("---------- lauch_loot 2 ------------\n");
	print_mobs(env);
	//sleep(1);

	printf("---------- lauch_loot 3 ------------\n");
	print_mobs(env);
	//sleep(1);

	printf("replace_mobs\n");
	replace_mobs_index(env, -1);

	printf("---------- lauch_loot 4------------\n");
	print_mobs(env);
	//sleep(1);

//	exit(0);
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
	pos.y += 4.0f;
	if (!(loot.m = insert_loot(&env->edit_env.map, map, pos, (int[2]){first->map_start, loot.id})))
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
			translate_mesh(&env->edit_env.map, loot->m, vec_fmult(diff, 0.33f / dist));
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
