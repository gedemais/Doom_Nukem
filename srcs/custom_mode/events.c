/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:37:15 by gedemais          #+#    #+#             */
/*   Updated: 2020/05/05 17:21:16 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		key_press_custom(int key, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	if (key == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	return (0);
}

int		key_release_custom(int key, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	
	(void)key;
	return (0);
}

int		mouse_press_custom(int button, int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	(void)x;
	(void)y;
	if (env->edit_env.scroll.mouse_index > -1)
	{
		if (button == BUTTON_SCROLL_UP)
			++env->edit_env.scroll.current;
		else if (button == BUTTON_SCROLL_DOWN)
			--env->edit_env.scroll.current;
	}
	return (0);
}

int		mouse_release_custom(int button, int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_position_custom(int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	env->events.mouse_pos = (t_point){x, y};
	(void)x;
	(void)y;
	return (0);
}
