#include "main.h"

static void	background(t_env *env)
{
	char		*img;
	char		*b;
	int			color;
	int			x;
	int			y;

	y = 0;
	color = 0x444444;
	b = (char*)&color;
	img = env->mlx.img_data;
	while (y < HGT)
	{
		if (y % 4 == 0)
			b[0]++;
		x = 0;
		while (x < WDT)
		{
			draw_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

static void	handle_events(t_env *env)
{
	bool	ret;

	ret = is_on_button(env->events.mouse_pos, env->edit_env.buttons[MAPED_NM_BUTTON_CREATE]);
	env->edit_env.buttons[MAPED_NM_BUTTON_CREATE].is_hover = ret;
	if (ret && env->events.buttons[BUTTON_LCLIC]
		&& !(env->edit_env.error = create_me_map(env)))
		env->edit_env.sub_context = MAPED_SC_CREATIVE;
}

int			maped_new_map(t_env *env)
{
	background(env);
	map_sprite(env->mlx.img_data, env->sprites[SP_ME_NM_TITLE],
		(t_point){420, 60});
	//draw_rectangle(env->mlx.img_data, (t_point){100, 275}, (t_point){850, 200}, 0);
	input_fields(env, false);
	handle_events(env);
	render_button(env, env->edit_env.buttons[MAPED_NM_BUTTON_CREATE]);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
