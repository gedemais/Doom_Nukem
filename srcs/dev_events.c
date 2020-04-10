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
			env->scene = 0;
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

int		render_dev(void *param)
{
	t_env		*env;
	static float	av = 0.0f;
	static int		it = 0;

	mesure_time(false);
	env = ((t_env*)param);

	dev_handle_events(env);

	//printf("%f %f\n", env->cam.stats.pitch, env->cam.stats.yaw);
	//printf("%f %f %f | %f %f\n", env->cam.stats.pos.x, env->cam.stats.pos.y, env->cam.stats.pos.z, env->cam.stats.yaw, env->cam.stats.pitch);
//	translate_mesh(&env->maps[0], (t_mesh*)env->maps[0].meshs.c, (t_vec3d){0.01f, 0, 0, 0});
	clear_screen_buffers(env);
	camera_aim(env);
	physic_engine(env);
	if (rasterizer(env, env->scene))
		exit(EXIT_FAILURE);
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
