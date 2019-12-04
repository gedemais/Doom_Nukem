/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:24:28 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/04 07:33:56 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		key_press(int key, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	if (key == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	if (key == KEY_M)
	{
		*mouse_freedom() = *mouse_freedom() ? false : true;
		if (*mouse_freedom())
			mlx_mouse_show();
		else
			mlx_mouse_hide();
	}
	env->events.keys[key] = true;
	return (0);
}

int		key_release(int key, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	env->events.keys[key] = false;
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	env->events.buttons[button] = true;
	printf("x = %d\ny = %d\nbutton = %d\n", x, y, button);
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	env->events.buttons[button] = false;
	printf("x = %d\ny = %d\nbutton = %d\n", x, y, button);
	return (0);
}

int		mouse_position(int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	env->events.mouse_x = x;
	env->events.mouse_y = y;
	printf("x = %d y = %d\n", x, y);
	return (0);
}
