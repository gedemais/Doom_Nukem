#include "main.h"

static int	select_map(t_env *env)
{
	t_scroll	*s;

	s = &env->scroll;
	display_file(env);
	if (s->s_path)
	{
		if (import_maped_map(&env->edit_env, s->s_path))
		{
			printf("Parsing Failed for map |%s|\n", s->s_path);
			exit(1);
			return (-1);
		}
		if (map_to_scene(env) || parse_events_blocks(env))
			return (-1);
		switch_custom_context(env, CUSTOM_SC_PLAY);
		//if (env->context == C_CUSTOM)
		//	greedy_meshing(env, scene);
	}
	ft_strdel(&s->s_path);
	return (0);
}

static int				handle_events(t_env *env)
{
	static bool	clic = false;
	int			i;

	i = -1;
	while (++i < MAPED_MENU_BUTTON_MAX)
		if (is_on_button(env->events.mouse_pos, env->edit_env.buttons[i]))
		{
			if (!env->events.buttons[BUTTON_LCLIC] && clic)
			{
				if (i == MAPED_MENU_BUTTON_MAIN_MENU)
					switch_context(env, C_TITLE_SCREEN);
				clic = false;
				return (1);
			}
			clic = env->events.buttons[BUTTON_LCLIC];
			env->edit_env.buttons[i].is_hover = true;
		}
		else
			env->edit_env.buttons[i].is_hover = false;
	return (0);
}

int			custom_menu(t_env *env)
{
	handle_events(env);
	map_sprite(env->mlx.img_data, env->sprites[SP_CUSTOM_BACKGROUND], (t_point){0, 0});
	render_button(env, env->edit_env.buttons[MAPED_MENU_BUTTON_MAIN_MENU]);
	if (select_map(env))
		return (-1);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
