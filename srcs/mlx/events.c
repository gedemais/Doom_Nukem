/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:24:28 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/06 18:43:11 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		key_press(int key, void *param)
{
	static int	(*key_press_fts[C_MAX])(int, void*) = {key_press_dev, key_press_ts};
	t_env		*env;

	env = ((t_env*)param);
	env->events.keys[key] = true;
	return (key_press_fts[env->context](key, param));
}

int		key_release(int key, void *param)
{
	static int	(*key_release_fts[C_MAX])(int, void*) = {key_release_dev, key_release_ts};
	t_env		*env;

	env = ((t_env*)param);
	env->events.keys[key] = false;
	return (key_release_fts[env->context](key, param));
}

int		mouse_press(int button, int x, int y, void *param)
{
	static int	(*mouse_press_fts[C_MAX])(int, int, int, void*) = {mouse_press_dev, mouse_press_ts};
	t_env		*env;

	env = ((t_env*)param);
	env->events.buttons[button] = true;
	return (mouse_press_fts[env->context](button, x, y, param));
}

int		mouse_release(int button, int x, int y, void *param)
{
	static int	(*mouse_release_fts[C_MAX])(int, int, int, void*) = {mouse_release_dev, mouse_release_ts};
	t_env		*env;

	env = ((t_env*)param);
	env->events.buttons[button] = false;
	return (mouse_release_fts[env->context](button, x, y, param));
}

int		mouse_position(int x, int y, void *param)
{
	static int	(*mouse_position_fts[C_MAX])(int, int, void*) = {mouse_position_dev, mouse_position_ts};
	t_env		*env;

	env = ((t_env*)param);
	env->events.mouse_pos = (t_point){x, y};
	return (mouse_position_fts[env->context](x, y, param));
}
