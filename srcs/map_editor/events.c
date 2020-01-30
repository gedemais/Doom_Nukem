/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:51:41 by gedemais          #+#    #+#             */
/*   Updated: 2020/01/30 02:53:56 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		key_press_maped(int key, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	if (key == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	return (0);
}

int		key_release_maped(int key, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	
	(void)key;
	return (0);
}

int		mouse_press_maped(int button, int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_release_maped(int button, int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_position_maped(int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	env->events.mouse_pos = (t_point){x, y};
	(void)x;
	(void)y;
	return (0);
}
