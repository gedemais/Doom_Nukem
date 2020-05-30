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

static int		handle_keys(t_env *env, t_events *e)
{
	if ((e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D]))
		move(env, e->keys);
	return (0);
}

int			custom_play(t_env *env)
{
	clock_t	time;

	time = clock();
	clear_screen_buffers(env);
	time = clock() - time;
	printf("clear screen buffers : %f\n-----------------\n", (double)time / CLOCKS_PER_SEC);

	handle_enemys(env);
	handle_keys(env, &env->events);
	camera_aim(env);
	env->mid.mesh = NULL;
	time = clock();
	assert(!rasterizer(env, &env->edit_env.map, false));
	time = clock() - time;
	printf("scene rasterization : %f\n", (double)time / CLOCKS_PER_SEC);

	time = clock();
	handle_weapons(env);
	time = clock() - time;
	printf("handle_weapons : %f\n", (double)time / CLOCKS_PER_SEC);

	printf("--------------------------------------------------------\n");
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	env->events.buttons[BUTTON_SCROLL_UP] = false;
	env->events.buttons[BUTTON_SCROLL_DOWN] = false;
	return (0);
}
