/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_handle_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:00:05 by gedemais          #+#    #+#             */
/*   Updated: 2020/06/05 15:48:22 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// only define the direction of the slope
static int key_move(bool keys[NB_KEYS]) //1
{
	if ((keys[KEY_W] || keys[KEY_S] || keys[KEY_A] || keys[KEY_D]) || keys[KEY_E]) 
		return (1);
	else
		return (0);

}

static void	handle_keys(t_env *env, t_events *e)
{
	if (key_move(e->keys))
		phy_move(env, e->keys, &env->maps[env->scene]);
}

void		dev_handle_events(t_env *env)
{
	t_events *e;
	
	e = &env->events;
	handle_keys(env, e);
}
