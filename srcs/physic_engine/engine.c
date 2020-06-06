/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <bebosson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:43:18 by bebosson          #+#    #+#             */
/*   Updated: 2020/05/22 14:45:48 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		physic_engine(t_env *env, t_map *maps)
{
	t_events	*e;
	t_mesh		*cam;

	cam = &maps->cam;
	e = &env->events;
	ft_memset((void*)maps->colls, 0, sizeof(bool) *  maps->nmesh);
//	dev_handle_events(env);
//	report_collisions(env);
	report_cam_collisions(env, maps);
//	color_collides(env);
	color_collides_cam(env);
//	update_speeds_collide(env); //report type of collision cam_floor // et update angle 
	update_speeds_collide_cam(env);
//	update_positions_gravity(env); // gravity 
	update_positions_gravity_cam(env, cam);

	// update_plan_cam(env)
//	if (e->keys[KEY_P])
//		pause_position(env);
//	stop_speed(env);
	clear_dynarray(&env->phy_env.collides);
	return (0);
}
