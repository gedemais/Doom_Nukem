/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_handle_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:00:05 by gedemais          #+#    #+#             */
/*   Updated: 2020/06/30 16:15:44 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
