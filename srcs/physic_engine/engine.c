/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benji_code <benji_code@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:43:18 by bebosson          #+#    #+#             */
/*   Updated: 2020/07/14 20:20:06 by benji_code       ###   ########.fr       */
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
