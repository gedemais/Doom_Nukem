/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:51:39 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/25 15:17:55 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int				handle_events_me(t_env *env)
{
	(void)env;
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

	handle_events_me(env);

	input_field(env, (t_point){300, 300}, NULL);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	//mlx_string_put(env->mlx.mlx_ptr, env->mlx.mlx_win, 10, 10, 0xffffff, "Contexte : map editor");
	return (0);
}
