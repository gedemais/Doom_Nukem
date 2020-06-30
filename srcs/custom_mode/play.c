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
		env->phy_env.type_move = false;
	if (e->keys[KEY_Y])
		env->phy_env.type_move = true;

	ft_type_move(env, e->keys, &env->edit_env.map);
	return (0);
}

int			custom_play(t_env *env)
{
	handle_keys(env, &env->events);
	handle_player(env);
	camera_aim(env);
	physic_engine(env, &env->edit_env.map);
	clear_screen_buffers(env);
	assert(!rasterizer(env, &env->edit_env.map, false));
	handle_enemies(env);
	handle_weapons(env);
	handle_block_events(env);
	handle_moon(env);
	draw_hud(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	env->events.buttons[BUTTON_SCROLL_UP] = false;
	env->events.buttons[BUTTON_SCROLL_DOWN] = false;
	return (0);
}
