#include "main.h"

static void	snow(int *img, int size)
{
	static int	colors[7] = {0x222222, 0x444444, 0x666666, 0x888888, 0xaaaaaa,
															0xcccccc, 0xffffff};
	int			i;

	i = 0;
	while (i < size)
	{
		img[i] = colors[rand() % 6];
		i++;
	}
}

static void	get_step(t_env *env, float left_time, int *step)
{
	static float	t = INFINITY;

	if (t == INFINITY)
		t = left_time;
	t -= env->data.spent;
	if (t <= 0)
	{
		*step += 1;
		t = INFINITY;
	}
}

int			cmp_intro(t_env *env)
{
	static float	time_list[INTRO_LIST_SIZE] = {1.5f, 4, 6, 6, 6, 7, 6, 5};
	static int		step = 0;

	ft_bzero(env->mlx.img_data, env->data.data_size);
	if (step == INTRO_LIST_SIZE && !(step = 0)
		&& switch_campaign_subcontext(env, CMP_SC_GAME))
		return (-1);
	if (step == 0 || step == INTRO_LIST_SIZE - 1)
		snow((int*)env->mlx.img_data, env->data.data_size / 4);
	else
		map_sprite(env->mlx.img_data,
			env->sprites[SP_CMP_KEY + step], (t_point){0, 0});
	get_step(env, time_list[step], &step);
	printf("step = %d\n", step);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
