#include "main.h"

int		set_game_stats(t_env *env)
{
	int		i;

	i = 0;
	env->weapons[W_GLOCK_18].ammos = 80;
	if (init_dynarray(&env->player.weapons, sizeof(t_weapon), 0)
		|| init_dynarray(&env->custom_env.mobs, sizeof(t_enemy), 0)
		|| init_dynarray(&env->custom_env.loots, sizeof(t_loot), 0))
			return (-1);
	if (push_dynarray(&env->player.weapons, &env->weapons[W_GLOCK_18], false))
		return (-1);
	env->player.current_w = 0;
	env->player.current = dyacc(&env->player.weapons, 0);
	env->player.current->ammos = env->player.current->max_ammos;
	env->player.hp = START_HP;
	env->custom_env.game.moula = START_MOULA;
	env->custom_env.game.wave = 0;
	return (0);
}

static int		put_variables(t_env *env)
{
	t_ttf_config	*conf;
	char			*ptr;

	conf = ttf_config();

	conf->size = 32;

	if (!(ptr = ft_itoa(env->custom_env.game.kill_count)))
		return (-1);
	ft_strcpy((char*)conf->s, ptr);
	my_string_put(env, env->mlx.img_data, (t_point){600, 305}, FONT_COOLVETICA);
	free(ptr);

	if (!(ptr = ft_itoa(env->custom_env.game.wave)))
		return (-1);
	ft_strcpy((char*)conf->s, ptr);
	my_string_put(env, env->mlx.img_data, (t_point){600, 365}, FONT_COOLVETICA);
	free(ptr);

	if (!(ptr = ft_itoa(env->custom_env.game.moula)))
		return (-1);
	ft_strcpy((char*)conf->s, ptr);
	my_string_put(env, env->mlx.img_data, (t_point){600, 425}, FONT_COOLVETICA);
	free(ptr);
	return (0);
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
					switch_custom_context(env, CUSTOM_SC_MENU);
				if (i == GO_BUTTON_YES)
					switch_custom_context(env, CUSTOM_SC_PLAY);
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
	map_sprite(env->mlx.img_data, env->sprites[SP_GAME_OVER], (t_point){0, 0});
	if (put_variables(env))
		return (-1);
	render_button(env, env->custom_env.go_env.buttons[GO_BUTTON_YES]);
	render_button(env, env->custom_env.go_env.buttons[GO_BUTTON_NO]);
	handle_events_go(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	return (0);
}
