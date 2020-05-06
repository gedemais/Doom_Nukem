#include "main.h"


static void	move(t_env *env, bool keys[NB_KEYS])
{
	t_vec3d		f;
	t_vec3d		r;
f = vec_fmult(env->cam.stats.dir, MAPED_WALK_SPEED);
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

//static void	switch_slope_block_type(t_env *env, t_events *e)
static void	switch_cube_block_type(t_env *env, t_events *e)
{
	char	*bt;

	bt = &env->edit_env.current_bt;
	if (e->buttons[BUTTON_SCROLL_UP])
	{
		if (env->edit_env.current_bc == BC_CUBE)
			*bt = (*bt >= NB_CUBES_ICONES - 1) ? 0 : *bt + 1;
	}
	else if (e->buttons[BUTTON_SCROLL_DOWN])
	{
		if (env->edit_env.current_bc == BC_CUBE)
			*bt = (*bt == BTXT_NONE) ? NB_CUBES_ICONES - 1 : *bt - 1;
	}
}

static void	handle_mouse(t_env *env, t_events *e)
{
	static int	put_delay = PUT_BLOCK_DELAY;
	static int	del_delay = PUT_BLOCK_DELAY;

	if (!e->buttons[BUTTON_LCLIC])
		put_delay = 0;
	if (!e->buttons[BUTTON_RCLIC])
		del_delay = 0;
	if (e->buttons[BUTTON_LCLIC] && env->mid.mesh && put_delay <= 0
		&& (put_delay = PUT_BLOCK_DELAY))
		put_block(env);
	else if (e->buttons[BUTTON_RCLIC] && del_delay <= 0
		&& (del_delay = PUT_BLOCK_DELAY))
		del_block(env);
	switch_cube_block_type(env, e);
	e->buttons[BUTTON_SCROLL_UP] = false;
	e->buttons[BUTTON_SCROLL_DOWN] = false;
	put_delay--;
	del_delay--;
}

static void	handle_keys(t_env *env, t_events *e)
{

	if ((e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D]))
		move(env, e->keys);

	if (e->keys[KEY_E]) // Custom only, a tej d'ici
		del_door(env);
}

int		maped_creative(t_env *env)
{
	handle_keys(env, &env->events);
	handle_mouse(env, &env->events);
	clear_screen_buffers(env);
	camera_aim(env);
	env->mid.mesh = NULL;
	if (rasterizer(env, &env->edit_env.map))
		exit(EXIT_FAILURE);
	render_pallet(env);
	maped_crosshair(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
