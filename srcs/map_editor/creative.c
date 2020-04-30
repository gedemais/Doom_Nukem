#include "main.h"

int		maped_creative(t_env *env)
{
	ft_memset(env->mlx.img_data, 0, env->data.data_size);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
