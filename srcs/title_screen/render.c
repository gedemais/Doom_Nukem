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
				if (i == TS_BUTTON_CAMPAIGN) //
					switch_context(env, C_DEV);// Provisoire
				else if (i == TS_BUTTON_QUIT)
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

int		render_ts(void *param)
{
	t_env	*env;

	env = ((t_env*)param);

	ft_memset(env->mlx.img_data, 0, sizeof(int) * WDT * HGT);

	handle_events(env);
	render_buttons(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
