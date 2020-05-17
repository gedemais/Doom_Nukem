#include "main.h"

static void	move(t_env *env, bool keys[NB_KEYS])
{
	t_vec3d		f;
	t_vec3d		r;

	f = vec_fmult(env->cam.stats.dir, WALK_SPEED);
	r = (t_vec3d){f.z, 0, -f.x, f.w};
	if (keys[KEY_W])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(f, 3.0f));
	if (keys[KEY_S])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(f, 3.0f));
	if (keys[KEY_A])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(r, 3.0f));
	if (keys[KEY_D])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(r, 3.0f));
}

static void	handle_keys(t_env *env, t_events *e)
{
	if ((e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D]))
		move(env, e->keys);
}

static void	handle_mouse(t_env *env, t_events *e)
{
	bool	exp;

	exp = (e->buttons[BUTTON_SCROLL_UP] || e->buttons[BUTTON_SCROLL_DOWN]);
	if (exp && env->player.current)
		switch_current_weapon(env, &env->events);

	e->buttons[BUTTON_SCROLL_UP] = false;
	e->buttons[BUTTON_SCROLL_DOWN] = false;
}

static void	cmp_game_handle_events(t_env *env)
{
	t_events	*e;

	e = &env->events;
	handle_keys(env, e);
	handle_mouse(env, e);
}

int		cmp_game(void *param)
{
	t_env		*env;
	t_camp_env	*cmp_env;
	static float	av = 0.0f;
	static int		it = 0;

	mesure_time(false);
	env = (t_env*)param;
	cmp_env = &env->cmp_env;
	env->scene = cmp_env->sectors[cmp_env->sector].map;
	//physic_engine(env);
	camera_aim(env);
	cmp_game_handle_events(env);
	clear_screen_buffers(env);
	if (rasterizer(env, &env->maps[env->scene]))
		return (-1);
	handle_weapons(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);

	av += 1 / mesure_time(true);
	if (av > 5000)
	{
		printf("%f\n", av / it);
		av = 0.0f;
		it = 0;
	}
	it++;
	return (0);
}
