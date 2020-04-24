/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:51:39 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/24 16:14:15 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int				handle_events_me(t_env *env)
{
	static bool	clic = false;
	int			i;

	//configurer pour switch context du button 
	i = -1;
	if (env->events.keys[KEY_ESCAPE])
		exit(EXIT_SUCCESS);
	while (++i < EDT_BUTTON_MAX)
		if (is_on_button(env->events.mouse_pos, env->edit_env.buttons[i]))
		{
			if (!env->events.buttons[BUTTON_LCLIC] && clic)
			{
				switch_context(env, env->edit_env.buttons[i].context);
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

static void	render_buttons_me(t_env *env)
{
	unsigned int	i;

	i = EDT_BTN_LOAD;
	while (i < EDT_BUTTON_MAX)
	{
		render_button(env, env->edit_env.buttons[i], SP_CP_BUTTON_1C);
		i++;
	}
}
/*
static void	init_sub_context(t_env *env, void *sub_context[])
{
	

}
*/
int		render_maped(void *param)
{
//	static bool		first = true;
//	static void (*sub_context[])(t_env *env) = {};
	t_env		*env;

	env = ((t_env*)param);

	if (env->events.keys[KEY_M])
		switch_context(env, C_TITLE_SCREEN);
	ft_memset(env->mlx.img_data, 0, sizeof(int) * WDT * HGT);
/********************************************/
/********************************************/

	handle_events_me(env);
	
	
	map_sprite(env->mlx.img_data, env->sprites[SP_EDT_BGD], (t_point){0, 0});
	map_sprite(env->mlx.img_data, env->sprites[SP_EDT_ME_TITLE], (t_point){328, 370});
	map_sprite(env->mlx.img_data, env->sprites[SP_ME_RECT_BTN], (t_point){328, 430});
	map_sprite(env->mlx.img_data, env->sprites[SP_ME_RECT_PRW], (t_point){751, 506});
	//faire un sous context pour le render
	render_buttons_me(env);

	input_field(env, (t_point){300, 300}, NULL);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	//mlx_string_put(env->mlx.mlx_ptr, env->mlx.mlx_win, 10, 10, 0xffffff, "Contexte : map editor");
	return (0);
}
