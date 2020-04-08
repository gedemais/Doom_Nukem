#include "main.h"

static int				handle_events_cmp_menu(t_env *env)
{
	static bool	clic = false;
	int			i;

	i = -1;
	if (env->events.keys[KEY_ESCAPE])
		exit(EXIT_SUCCESS);
	while (++i < CMP_BUTTON_MAX)
		if (is_on_button(env->events.mouse_pos, env->cmp_env.buttons[i]))
		{
			if (!env->events.buttons[BUTTON_LCLIC] && clic)
			{
				if (i == CMP_BTN_MMENU)
					switch_context(env, C_TITLE_SCREEN);
				else if (i == CMP_BTN_NWG)
					switch_campaign_subcontext(env, CMP_SC_GAME);
				clic = false;
				return (1);
			}
			clic = env->events.buttons[BUTTON_LCLIC];
			env->cmp_env.buttons[i].is_hover = true;
		}
		else
			env->cmp_env.buttons[i].is_hover = false;
	return (0);
}

static void	render_buttons_cmp_menu(t_env *env)
{
	unsigned int	i;

	i = CMP_BTN_MMENU;
	while (i < CMP_BUTTON_MAX)
	{
		render_button(env, env->cmp_env.buttons[i], SP_CP_BUTTON_1C);
		i++;
	}
}

int		cmp_menu(void *param)
{
	t_env *env;

	env = (t_env*)param;
	handle_events_cmp_menu(env);	
	if (env->events.keys[KEY_M])
		switch_context(env, C_TITLE_SCREEN);

	map_sprite(env->mlx.img_data, env->sprites[SP_BGD_LOADER_CMP], (t_point){0, 0});
	blit_sprite(env->mlx.img_data, env->sprites[SP_TXT_LOADER_CMP], (t_point){0, 0}, 1.0f);

	render_buttons_cmp_menu(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
