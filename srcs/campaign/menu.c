#include "main.h"

static int				sound_button(t_env *env, bool hover)
{
	if (hover == false)
	{
		if (sound_system(env, SA_BUTTON, sp_stop()))
			return (-1);
		if (sound_system(env, SA_BUTTON,
				sp_play(env->sound.volume, PITCH, env->cam.stats.pos)))
			return (-1);
	}
	return (0);
}

static int				handle_events_cmp_menu(t_env *env)
{
	static bool	clic = false;
	int			i;

	i = -1;
	while (++i < CMP_BUTTON_MAX)
		if (is_on_button(env->events.mouse_pos, env->cmp_env.buttons[i]))
		{
			if (sound_button(env, env->cmp_env.buttons[i].is_hover))
				return (-1);
			if (!env->events.buttons[BUTTON_LCLIC] && clic)
			{
				if (i == CMP_BUTTON_MAIN_MENU
					&& switch_context(env, C_TITLE_SCREEN))
					return (-1);
				else if (i == CMP_BUTTON_NEW_GAME
					&& switch_campaign_subcontext(env, CMP_SC_GAME))
					return (-1);
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
	render_button(env, env->cmp_env.buttons[CMP_BUTTON_MAIN_MENU]);
	render_button(env, env->cmp_env.buttons[CMP_BUTTON_NEW_GAME]);
}

int			cmp_menu(void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (sound_manager(env, SA_TITLE_SCREEN_L))
		return (-1);
	if (handle_events_cmp_menu(env))
		return (0);
	map_sprite(env->mlx.img_data, env->sprites[SP_CMP_TS_BACKGROUND], (t_point){0, 0});
	map_sprite(env->mlx.img_data, env->sprites[SP_CMP_MENU_TXT], (t_point){0, 0});
	render_buttons_cmp_menu(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
