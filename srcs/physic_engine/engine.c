/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <bebosson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:43:18 by bebosson          #+#    #+#             */
/*   Updated: 2020/06/30 15:24:08 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		physic_engine(t_env *env, t_map *maps)
{
	t_events	*e;
	t_mesh		*cam;

	cam = &maps->cam;
	e = &env->events;
	print_info_phy(env, &maps->cam, maps);
//	dev_handle_events(env);
//	report_collisions(env);
	report_cam_collisions(env, maps);
//	color_collides(env);
//	color_collides_cam(env);
//	update_speeds_collide(env); //report type of collision cam_floor // et update angle 
	update_speeds_collide_cam(env, cam, maps);
//	update_positions_gravity(env); // gravity 
	update_positions_cam(env , maps, cam);
//	print_collide(maps->cam_floor);
	stop_position_cam(env, maps, cam);
	clear_dynarray(&env->phy_env.collides);
	return (0);
}
