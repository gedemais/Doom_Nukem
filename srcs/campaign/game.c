#include "main.h"

static void	move(t_env *env, bool keys[NB_KEYS])
{
	t_vec3d		f;
	t_vec3d		r;

	f = vec_fmult(env->cam.stats.dir, WALK_SPEED);
	r = vec_fdiv((t_vec3d){f.z, 0, -f.x, f.w}, env->cam.stats.aspect_ratio);

	if (keys[KEY_W])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(f, 3.0f));
	if (keys[KEY_S])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(f, 3.0f));
	if (keys[KEY_A])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(r, 3.0f));
	if (keys[KEY_D])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(r, 3.0f));
}

static void	real_move(t_env *env, bool keys[NB_KEYS])
{
	t_mesh		*cam;
	t_vec3d		f;
	t_vec3d		r;

	f = vec_fmult(env->cam.stats.dir, WALK_SPEED);
	r = vec_fmult((t_vec3d){f.z, 0, -f.x, f.w}, 0.5f);

	if (keys[KEY_W])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(f, 3.0f));
	if (keys[KEY_S])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(f, 3.0f));
	if (keys[KEY_A])
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(r, 3.0f));
	if (keys[KEY_D])
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(r, 3.0f));

	// actualise camera's stats into camera mesh for collisions
	cam = dyacc(&env->maps[env->scene].meshs, env->maps[env->scene].nmesh);
//	cam.corp.pos = ;
	cam->corp.o = vec_sub(env->cam.stats.pos, vec_fdiv(cam->corp.dims, 2.0f));
}

static void	handle_keys(t_env *env, t_events *e)
{
	static int move_i = 0;
	t_vec3d dir;
	t_vec3d pos;

	dir = env->cam.stats.dir;
	pos = env->cam.stats.pos;

	if ((e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D]) && move_i == 0) 
		move(env, e->keys);
	if ((e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D]) && move_i == 1) 
		real_move(env, e->keys);
	else if (e->keys[KEY_N])
		move_i = (move_i == 0) ? 1 : 0;
}

static void	cmp_game_handle_events(t_env *env)
{
	t_events	*e;

	e = &env->events;
	handle_keys(env, e);
}

int		cmp_game(void *param)
{
	t_env *env;

	env = (t_env*)param;
	cmp_game_handle_events(env);
	clear_screen_buffers(env);
	camera_aim(env);
	if (rasterizer(env, env->cmp_env.sector))
		return (-1);
	handle_weapons(env);
	cmp_hud(env, &env->cmp_env);
	my_string_put(env, (t_point){50, 100}, FONT_AMAZDOOM, "FDP_DE_PUTE");
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
