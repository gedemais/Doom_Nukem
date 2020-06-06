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
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(f, 3.0f));
		translate_mesh(map, &map->cam, vec_fmult(f, 3.0f));
	}
	if (keys[KEY_S])
	{
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(f, 3.0f));
		translate_mesh(map, &map->cam, vec_fmult(f, -3.0f));
	}
	if (keys[KEY_A])
	{
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(r, 3.0f));
		translate_mesh(map, &map->cam, vec_fmult(r, 3.0f));
	}
	if (keys[KEY_D])
	{
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(r, 3.0f));
		translate_mesh(map, &map->cam, vec_fmult(r, -3.0f));
	}
}

static void ft_type_move(t_env *env, bool keys[NB_KEYS])
{
	if (env->phy_env.type_move == true)
		move(env, keys);
	else
		phy_move(env, keys);
	
}

static int		handle_keys(t_env *env, t_events *e)
{
	if (e->keys[KEY_T])
		env->phy_env.type_move = false;
	if (e->keys[KEY_Y])
		env->phy_env.type_move = true;

	ft_type_move(env, e->keys);
	return (0);
}

int			custom_play(t_env *env)
{
	clear_screen_buffers(env);
	handle_enemies(env);
	handle_keys(env, &env->events);
	camera_aim(env);
	env->mid.mesh = NULL;
	
	
//	if (env->phy_env.type_move == false)
		physic_engine(env, &env->edit_env.map);
	assert(!rasterizer(env, &env->edit_env.map, false));
	handle_weapons(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	env->events.buttons[BUTTON_SCROLL_UP] = false;
	env->events.buttons[BUTTON_SCROLL_DOWN] = false;
	return (0);
}
