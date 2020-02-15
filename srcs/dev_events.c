#include "main.h"

int		key_press_dev(int key, void *param)
{
	t_env		*env;

	env = ((t_env*)param);
	if (key == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	if (key == KEY_M)
		env->context = C_TITLE_SCREEN;
	if (key == KEY_SPACE)
	{
		env->scene++;
		if (env->scene == SCENE_MAX)
			env->scene = SCENE_A;
	}
	return (0);
}

int		key_release_dev(int key, void *param)
{
	t_env		*env;

	env = ((t_env*)param);
	(void)key;
	return (0);
}

int		mouse_press_dev(int button, int x, int y, void *param)
{
	t_env		*env;

	env = ((t_env*)param);
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_release_dev(int button, int x, int y, void *param)
{
	(void)param;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_position_dev(int x, int y, void *param)
{
	t_env		*env;

	env = ((t_env*)param);
	env->events.mouse_pos.x = x;
	env->events.mouse_pos.y = y;
	return (0);
}

static void camera(t_env *env)
{
	int			hwdt;
	int			hhgt;
	int			x;
	int			y;

	hwdt = WDT / 2;
	hhgt = HGT / 2;
	x = env->events.mouse_pos.x;
	y = env->events.mouse_pos.y;
	if (x <= hwdt && y < hhgt) // L Up
	{
		env->cam.stats.yaw -= fabs((hwdt - x) * SENSI) * env->cam.stats.aspect_ratio; // A caper
		env->cam.stats.pitch += fabs((hhgt - y) * SENSI);
	}
	else if (x < hwdt && y >= hhgt) // L Down
	{
		env->cam.stats.yaw -= fabs((hwdt - x) * SENSI) * env->cam.stats.aspect_ratio;
		env->cam.stats.pitch -= fabs((hhgt - y) * SENSI);
	}
	else if (x >= hwdt && y < hhgt) // R Up
	{
		env->cam.stats.yaw += fabs((hwdt - x) * SENSI) * env->cam.stats.aspect_ratio;
		env->cam.stats.pitch += fabs((hhgt - y) * SENSI);
	}
	else if (x > hwdt && y >= hhgt) // R Down
	{
		env->cam.stats.yaw += fabs((hwdt - x) * SENSI) * env->cam.stats.aspect_ratio;
		env->cam.stats.pitch -= fabs((hhgt - y) * SENSI);
	}
	mlx_mouse_move(env->mlx.mlx_win, hwdt, hhgt);
	env->events.mouse_pos.x = hwdt;
	env->events.mouse_pos.y = hhgt;
}

int		render_dev(void *param)
{
	t_env		*env;
	static float	av = 0.0f;
	static int		it = 0;

	mesure_time(false);
	env = ((t_env*)param);

	dev_handle_events(env);

	ft_memset(env->mlx.img_data, 0, env->data.data_size);
	for (int i = 0; i < HGT * WDT; i++)
		env->cam.z_buffer[i] = 0.0f;
	camera(env);
	//translate_mesh(dyacc(&env->maps[env->scene].meshs, 1), (t_vec3d){0, 0, 0.01f, 0});
	rasterizer(env, env->scene);
//  blit_sprite(env->mlx.img_data, env->sprites[TXT_BLOC_GRASS], (t_point){0.0f, 0.0f}, 1.0f);
//	mlx_string_put(env->mlx.mlx_ptr, env->mlx.mlx_win, 10, 10, 0xffffff, "Contexte : dev");
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);

//	printf("%f %f %f\n", env->cam.stats.pos.x, env->cam.stats.pos.y, env->cam.stats.pos.z);
	av += 1 / mesure_time(true);
	if (av > 2000)
	{
		printf("%f\n", av / it);
		av = 0.0f;
		it = 0;
	}
	it++;
	return (0);
}
