#include "main.h"

static void	move(t_env *env, bool keys[NB_KEYS])
{
	t_map		*map;
	t_vec3d		f;
	t_vec3d		r;

	map = &env->edit_env.map;
	f = vec_fmult(env->cam.stats.dir, MAPED_WALK_SPEED);
	r = (t_vec3d){f.z, 0, -f.x, f.w};
	if (keys[KEY_W])
	{
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(f, WSPEED));
		translate_mesh(map, &map->cam, vec_fmult(f, WSPEED));
	}
	if (keys[KEY_S])
	{
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(f, WSPEED));
		translate_mesh(map, &map->cam, vec_fmult(f, -WSPEED));
	}
	if (keys[KEY_A])
	{
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(r, WSPEED));
		translate_mesh(map, &map->cam, vec_fmult(r, WSPEED));
	}
	if (keys[KEY_D])
	{
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(r, WSPEED));
		translate_mesh(map, &map->cam, vec_fmult(r, -WSPEED));
	}
//	print_info_phy(env, &map->cam);
}

static void ft_type_move(t_env *env, bool keys[NB_KEYS], t_map *maps)
{
	if (env->phy_env.type_move == false)
		move(env, keys);
	else
		phy_move(env, keys, maps);
}

static int		handle_keys(t_env *env, t_events *e)
{
	if (e->keys[KEY_T])
	{
		env->phy_env.type_move = false;
		env->hud.timePhysic = env->data.time.tv_sec;
	}
	if (e->keys[KEY_Y])
	{
		env->phy_env.type_move = true;
		env->hud.timePhysic = env->data.time.tv_sec;
	}
	if (e->keys[KEY_M])
		if (switch_custom_context(env, CUSTOM_SC_MENU))
			return (-1);

	ft_type_move(env, e->keys, &env->edit_env.map);
	return (0);
}

static void	print_mobs(t_env *env)
{
	t_enemy	*mob;
	t_mesh	*m;
	int		i;

	i = 0;
	if (env->custom_env.loot.m)
		printf("loot : %d\n", env->custom_env.loot.m->index);
	while (i < env->custom_env.mobs.nb_cells)
	{
		mob = dyacc(&env->custom_env.mobs, i);
		printf("mob %d : %d <-> %d (", i, mob->map_start, mob->map_end);
		for (int j = mob->map_start; j < mob->map_end; j++)
		{
			m = dyacc(&env->edit_env.map.meshs, j);
			printf("%d ", m->index);
		}
		printf(")\n");
		i++;
	}
	printf("-----------------------------------------------------\n");
}

int			custom_play(t_env *env)
{
	print_mobs(env);
	if (sound_manager(env, SA_MAX))
		return (-1);
	handle_waves(env);
	//physic_engine(env, &env->edit_env.map);
	camera_aim(env);
	clear_screen_buffers(env);
	if (rasterizer(env, &env->edit_env.map, false))
		return (-1);
	handle_moon(env);
	if (handle_loots(env) || handle_weapons(env) || handle_block_events(env))
		return (-1);
	draw_hud(env);
	if (handle_keys(env, &env->events)
		|| handle_player(env) || handle_enemies(env))
		return (-1);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
