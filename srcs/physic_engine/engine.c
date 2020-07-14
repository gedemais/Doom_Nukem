/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:37:28 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/14 20:37:42 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		physic_engine(t_env *env, t_map *maps)
{
	t_events	*e;
	t_mesh		*cam;

	cam = &maps->cam;
	e = &env->events;
	report_cam_collisions(env, maps);
	update_speeds_collide_cam(env, cam, maps);
	update_positions_cam(env, maps, cam);
	stop_position_cam(env, maps, cam);
	clear_dynarray(&env->phy_env.collides);
	return (0);
}
