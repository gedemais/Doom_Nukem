#include "main.h"

int		key_press_dev(int key, void *param)
{
	t_env		*env;

	env = ((t_env*)param);
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

//	mesure_time(false);
	env = ((t_env*)param);

	handle_events(env);

	ft_memset(env->mlx.img_data, 50, sizeof(int) * WDT * HGT);
	rasterizer(env);
	mlx_string_put(env->mlx.mlx_ptr, env->mlx.mlx_win, 10, 10, 0xffffff, "Contexte : dev");
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);

	return (0);
}
