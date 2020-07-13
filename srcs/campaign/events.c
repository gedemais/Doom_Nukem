/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 01:53:49 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/13 14:22:38 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		key_press_camp(int key, void *param)
{
	t_env		*env;

	env = ((t_env*)param);

	if (key == KEY_SPACE)
	{
		env->cmp_env.sector++;
		if (env->cmp_env.sector == SECTOR_MAX)
			env->cmp_env.sector = 0;
	}
	if (env->cmp_env.sub_context == CMP_SC_GAME && key == KEY_Q)
		env->data.wireframe = !env->data.wireframe;
	return (0);
}

int		key_release_camp(int key, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	
	(void)key;
	return (0);
}

int		mouse_press_camp(int button, int x, int y, void *param)
{
	t_camp_env	*env;

	env = &((t_env*)param)->cmp_env;
	
	(void)x;
	(void)y;
	(void)button;
	return (0);
}

int		mouse_release_camp(int button, int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_position_camp(int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	env->events.mouse_pos = (t_point){x, y};
	(void)x;
	(void)y;
	return (0);
}
