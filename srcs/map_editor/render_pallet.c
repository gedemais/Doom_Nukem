#include "main.h"

void	render_cube_pallet(t_env *env, t_cube_pallet *pallet, t_point o)
{
	unsigned int	i;
	t_point			pos;
	int				index;

	i = 0;
	pos = o;
	pos.x += 2;
	pos.y += 2;
	index = env->edit_env.current_bt;
	while (i < NB_CUBES_ICONES)
	{
		blit_sprite(env->mlx.img_data, pallet[i].sprite, pos, 2.0f);
		pos.x += 34;
		i++;
	}
	pos = (t_point){o.x + (index * 34) - 1, o.y};
	draw_rectangle(env->mlx.img_data, pos, (t_point){3, 34}, 0x00ff00);
	draw_rectangle(env->mlx.img_data, pos, (t_point){34, 2}, 0x00ff00);
	pos.x += 34;
	draw_rectangle(env->mlx.img_data, pos, (t_point){3, 34}, 0x00ff00);
	pos.x -= 34;
	pos.y += 34;
	draw_rectangle(env->mlx.img_data, pos, (t_point){37, 2}, 0x00ff00);
}
