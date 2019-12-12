#include "main.h"

int		key_press_dev(int key, void *param)
{
	t_env		*env;
	t_vec3d		f;
	t_vec3d		r;

	env = ((t_env*)param);
	f = vec_fmult(env->cam.dir, 0.5f);
	r = vec_cross(env->cam.dir, f);
	vec_normalize(&r);

	if (key == KEY_LEFT)
		env->cam.yaw -= 0.05f;
	if (key == KEY_RIGHT)
		env->cam.yaw += 0.05f;
	if (key == KEY_UP)
		env->cam.pitch += 0.05f;
	if (key == KEY_DOWN)
		env->cam.pitch -= 0.05f;

	if (key == KEY_W)
		env->cam.pos = vec_add(env->cam.pos, f);
	if (key == KEY_S)
		env->cam.pos = vec_sub(env->cam.pos, f);

	if (key == KEY_A)
		env->cam.pos.x += 0.5f;
	if (key == KEY_D)
		env->cam.pos.x -= 0.5f;

	if (key == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	if (key == KEY_C)
		env->context = C_TITLE_SCREEN;
	(void)key;
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
	(void)param;
	(void)x;
	(void)y;
	return (0);
}

int		render_dev(void *param)
{
	t_env		*env;
	static float	av = 0.0f;
	static int		it = 0;

	mesure_time(false);
	env = ((t_env*)param);

	handle_events(env);

	ft_memset(env->mlx.img_data, 50, env->data.data_size);
	rasterizer(env);
	mlx_string_put(env->mlx.mlx_ptr, env->mlx.mlx_win, 10, 10, 0xffffff, "Contexte : dev");
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);

	av += 1 / mesure_time(true);
	if (av > 20000)
	{
		printf("%f\n", av / it);
		av = 0.0f;
		it = 0;
	}
	it++;
	return (0);
}
