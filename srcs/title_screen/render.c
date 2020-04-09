#include "main.h"

int				handle_events(t_env *env)
{
	static bool	clic = false;
	int			i;

	i = -1;
	if (env->events.keys[KEY_ESCAPE])
		exit(EXIT_SUCCESS);
	while (++i < TS_BUTTON_MAX)
		if (is_on_button(env->events.mouse_pos, env->ts_env.buttons[i]))
		{
			if (!env->events.buttons[BUTTON_LCLIC] && clic)
			{
				if (i == TS_BUTTON_QUIT)
					exit(EXIT_SUCCESS);
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

static void	render_buttons(t_env *env)
{
	unsigned int	i;

	i = 0;
	while (i < TS_BUTTON_MAX)
	{
		render_button(env, env->ts_env.buttons[i], i);
		i++;
	}
}
/*
static void	play_sound(t_env *env)
{
	static bool		first = true;
	static bool		loop = false;

	if (loop)
		loop_sample(env->sound.samples[SA_TITLE_SCREEN_L], false, false, true);
	else if (first && !(first = false))
		play_ambience(env->sound.samples[SA_TITLE_SCREEN_S], true, false, false);
	else if (play_ambience(env->sound.samples[SA_TITLE_SCREEN_S], true, false, true) == 0)
	{
		loop = true;
		loop_sample(env->sound.samples[SA_TITLE_SCREEN_L], true, false, false);
	}
}*/

int			render_ts(void *param)
{
	t_env		*env;
	static int	anim = 120;
	static int	frame = 0;
	float		t;

	mesure_time(false);
	env = ((t_env*)param);

	handle_events(env);

//	play_sound(env);
	map_sprite(env->mlx.img_data, env->sprites[SP_TS_BACKGROUND], (t_point){0, 0});
	if (anim > 0)
	{
		frame++;
		animation(env);
	}
	else
		map_sprite(env->mlx.img_data, env->sprites[SP_TS_LOGO], (t_point){180, 50});
	render_buttons(env);

	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	if (anim > 0)
	{
		t = mesure_time(true);
		usleep(13500 - t);
	}
	anim--;
	return (0);
}
