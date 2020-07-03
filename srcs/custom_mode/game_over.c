#include "main.h"

static void		put_variables(t_env *env)
{
	t_ttf_config	*conf;

	conf = ttf_config();

	conf->size = 32;
	ft_strcpy((char*)conf->s, ft_itoa(env->custom_env.game.kill_count));
	my_string_put(env, env->mlx.img_data, (t_point){600, 305}, FONT_COOLVETICA);
	ft_strcpy((char*)conf->s, ft_itoa(env->custom_env.game.wave));
	my_string_put(env, env->mlx.img_data, (t_point){600, 365}, FONT_COOLVETICA);
	ft_strcpy((char*)conf->s, ft_itoa(env->custom_env.game.moula));
	my_string_put(env, env->mlx.img_data, (t_point){600, 425}, FONT_COOLVETICA);
}

static int		handle_events_go(t_env *env)
{
	static bool	clic = false;
	int			i;

	i = -1;
	while (++i < GO_BUTTON_MAX)
		if (is_on_button(env->events.mouse_pos, env->custom_env.go_env.buttons[i]))
		{
			if (!env->events.buttons[BUTTON_LCLIC] && clic)
			{
				if (i == GO_BUTTON_NO)
					switch_context(env, C_TITLE_SCREEN);
				if (i == GO_BUTTON_YES)
				{
					custom_menu_to_play(env);
					switch_custom_context(env, CUSTOM_SC_PLAY);
				}
				clic = false;
				return (1);
			}
			clic = env->events.buttons[BUTTON_LCLIC];
			env->custom_env.go_env.buttons[i].is_hover = true;
		}
		else
			env->custom_env.go_env.buttons[i].is_hover = false;
	return (0);
}

int		custom_game_over(t_env *env)
{
	(void)env;

	mlx_mouse_show();
	map_sprite(env->mlx.img_data, env->sprites[SP_GAME_OVER], (t_point){0, 0});
	put_variables(env);
	render_button(env, env->custom_env.go_env.buttons[GO_BUTTON_YES]);
	render_button(env, env->custom_env.go_env.buttons[GO_BUTTON_NO]);
	handle_events_go(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
