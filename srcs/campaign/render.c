/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 01:53:02 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/11 18:56:35 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int				handle_events_cp(t_env *env)
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
					switch_context(env, C_DEV);
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

static void	render_buttons_cp(t_env *env)
{
	unsigned int	i;

	i = CMP_BTN_MMENU;
	while (i < CMP_BUTTON_MAX)
	{
		render_button(env, env->cmp_env.buttons[i], SP_CP_BUTTON_1C);
		i++;
	}
}

/*
void	render_button(void *param, t_button button, unsigned int index)
{
	t_env		*env;
	t_sprite	*sprite;
	bool		clic;

	env = (t_env*)param;
	clic = false;
	if (button.is_hover)
	{
		if (env->events.buttons[BUTTON_LCLIC])
		{
			sprite = &env->sprites[index * 3];
			blit_sprite(env->mlx.img_data, *sprite, (t_point){button.l_up.x, button.l_up.y}, 1.0f);
			clic = true;
		}
		else
			sprite = &env->sprites[index * 3 + 1];
	}
	else
		sprite = &env->sprites[index * 3 + 2];
	if (!clic)
		blit_sprite(env->mlx.img_data, *sprite, (t_point){button.l_up.x, button.l_up.y}, 1.0f);
}
*/

int		render_camp(void *param)
{
	t_env	*env;

	env = ((t_env*)param);

//	ft_memset(env->mlx.img_data, 0, sizeof(int) * WDT * HGT);

	if (env->events.keys[KEY_M])
		switch_context(env, C_TITLE_SCREEN);

	handle_events_cp(env);	
	blit_sprite(env->mlx.img_data, env->sprites[SP_BGD_LOADER_CMP], (t_point){0, 0}, 1.0f);
	blit_sprite(env->mlx.img_data, env->sprites[SP_TXT_LOADER_CMP], (t_point){0, 0}, 1.0f);

//	blit_sprite(env->mlx.img_data, env->sprites[SP_CP_BUTTON_2O], (t_point){0, 0}, 1.0f);
//	blit_sprite(env->mlx.img_data, env->sprites[SP_CP_BUTTON_2H], (t_point){0, 0}, 1.0f);
	render_buttons_cp(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
//	mlx_string_put(env->mlx.mlx_ptr, env->mlx.mlx_win, 10, 10, 0xffffff, "Contexte : campaign");
	return (0);
}
