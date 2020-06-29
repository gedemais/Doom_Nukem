#include "main.h"

int		custom_game_over(t_env *env)
{
	(void)env;
	ft_memset(env->mlx.img_data, 0, WDT * HGT * 4);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
