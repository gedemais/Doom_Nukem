#include "main.h"

static int				handle_events(t_env *env)
{
	static bool	clic = false;
	int			i;

	i = -1;
	while (++i < TS_BUTTON_MAX)
		if (is_on_button(env->events.mouse_pos, env->ts_env.buttons[i]))
		{
			if (!env->events.buttons[BUTTON_LCLIC] && clic)
			{
				if (i == TS_BUTTON_QUIT)
					switch_context(env, C_DEV);
					//exit_doom(env);
				else
					switch_context(env, i + 2);
				clic = false;
				return (1);
			}
			clic = env->events.buttons[BUTTON_LCLIC];
			env->ts_env.buttons[i].is_hover = true;
		}
		else
			env->ts_env.buttons[i].is_hover = false;
	return (0);
}

static void			render_buttons(t_env *env)
{
	unsigned int	i;

	i = 0;
	while (i < TS_BUTTON_MAX)
	{
		render_button(env, env->ts_env.buttons[i]);
		i++;
	}
}

static void			wait_frame(void)
{
	float		t;

	t = mesure_time(true);
	usleep(13500 - t);
}

int			render_ts(void *param)
{
	t_env		*env;
	static int	anim = 120;
	static int	frame = 0;

	mesure_time(false);
	env = ((t_env*)param);
	if (sound_system(env, 0, sp_no_sound(0, SA_PNL)) == 0)
		sound_system(env, SA_TITLE_SCREEN_L, sp_play(0.5f));
	handle_events(env);
	map_sprite(env->mlx.img_data,
		env->sprites[SP_TS_BACKGROUND], (t_point){0, 0});
	if (anim > 0 && (++frame))
		animation(env);
	else
		map_sprite(env->mlx.img_data,
			env->sprites[SP_TS_LOGO], (t_point){180, 50});
	render_buttons(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr,
		env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	if (anim-- > 0)
		wait_frame();
	return (0);
}
