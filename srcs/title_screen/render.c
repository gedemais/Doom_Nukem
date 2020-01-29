#include "main.h"

static void		switch_context(t_env *env, unsigned int i)
{
	static int	contexts[TS_BUTTON_MAX] = {C_DEV, C_DEV, C_DEV, C_DEV, C_DEV};

	env->context = contexts[i];
}

int				handle_events(t_env *env)
{
	static bool		clic = false;
	unsigned int	i;

	i = 0;
	if (env->events.keys[KEY_ESCAPE])
		exit(EXIT_SUCCESS);
	while (i < TS_BUTTON_MAX)
	{
		if (is_on_button(env->events.mouse_pos, env->ts_env.buttons[i]))
		{
			if (!env->events.buttons[BUTTON_LCLIC] && clic)
			{
				switch_context(env, i);
				return (1);
			}
			clic = env->events.buttons[BUTTON_LCLIC];
			env->ts_env.buttons[i].is_hover = true;
		}
		else
			env->ts_env.buttons[i].is_hover = false;
		i++;
	}
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
