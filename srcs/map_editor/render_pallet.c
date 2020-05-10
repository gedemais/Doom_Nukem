#include "main.h"

static void	draw_focus_square(t_env *env, t_point pos, t_point o, int index)
{
	pos = (t_point){o.x + (index * 34) - 1, o.y};
	draw_rectangle(env->mlx.img_data, pos, (t_point){3, 34}, 0x00ff00);
	draw_rectangle(env->mlx.img_data, pos, (t_point){34, 2}, 0x00ff00);
	pos.x += 34;
	draw_rectangle(env->mlx.img_data, pos, (t_point){3, 34}, 0x00ff00);
	pos.x -= 34;
	pos.y += 34;
	draw_rectangle(env->mlx.img_data, pos, (t_point){37, 2}, 0x00ff00);
}

void		render_pallet(t_env *env, t_cube_pallet *p, t_point o, char bc)
{
	unsigned int	i;
	t_point			pos;
	int				index;

	i = 0;
	pos = o;
	pos.x += 2;
	pos.y += 2;
	index = env->edit_env.current_bt % 32;
	while (i < BTXT_MAX - 1)
	{
		if ((bc == BC_CUBE && p[i].cube)
			|| (ft_inbounds(bc, BC_SLOPE_NORD, BC_SLOPE_EST) && p[i].slope))
		{
			blit_sprite(env->mlx.img_data, p[i].sprite, pos, 2.0f);
			pos.x += 34;
		}
		i++;
	}
	draw_focus_square(env, pos, o, index);
}
