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

static void	display_new_map_error(t_env *env, int error)
{
	t_ttf_config			*conf;
	static char				*err_msg[CM_ERR_MAX] = {"",
		"Too many chunks. width * height * depth must be <= 200000",
		"Invalid / empty dimensions param. Should be an integer",
		"Invalid / empty name"};

	conf = ttf_config();
	conf->size = 16;
	ft_memset(conf->s, 0, MAX_STR_CHARS);
	ft_strcpy((char*)conf->s, err_msg[error]);
	my_string_put(env, env->mlx.img_data, (t_point){100, 450}, FONT_ARIAL);
	ft_memset(conf->s, 0, MAX_STR_CHARS);
}

static void	handle_events(t_env *env)
{
	bool	ret;

	ret = is_on_button(env->events.mouse_pos, env->edit_env.buttons[MAPED_NM_BUTTON_CREATE]);
	env->edit_env.buttons[MAPED_NM_BUTTON_CREATE].is_hover = ret;
	if (ret && env->events.buttons[BUTTON_LCLIC]
		&& !(env->edit_env.error = create_me_map(env)))
		switch_mecontext(env, MAPED_SC_CREATIVE);

	ret = is_on_button(env->events.mouse_pos, env->edit_env.buttons[MAPED_NM_BUTTON_MAPED]);
	env->edit_env.buttons[MAPED_NM_BUTTON_MAPED].is_hover = ret;
	if (ret && env->events.buttons[BUTTON_LCLIC])
		switch_mecontext(env, MAPED_SC_MENU);


	if (env->edit_env.error == -1)
		exit(1);
	else
		display_new_map_error(env, env->edit_env.error);
}

int			maped_new_map(t_env *env)
{
	background(env);
	map_sprite(env->mlx.img_data, env->sprites[SP_ME_NM_TITLE],
		(t_point){420, 60});
	input_fields(env, false);
	handle_events(env);
	render_button(env, env->edit_env.buttons[MAPED_NM_BUTTON_CREATE]);
	render_button(env, env->edit_env.buttons[MAPED_NM_BUTTON_MAPED]);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
