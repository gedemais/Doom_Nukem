/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phy_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <bebosson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:44:09 by bebosson          #+#    #+#             */
/*   Updated: 2020/05/22 14:45:48 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	type_of_plan(t_env *env, t_collide *c)
{
	if ((fabs(c->a->corp.norm.x) == 1 || fabs(c->a->corp.norm.z) == 1) && c->i_a != 0)
	{
		env->maps[env->scene].cam_wall = *c;
		env->cam.stats.onwall = 1;
	}
	else
	{
		test_distance_camplan(env->maps[env->scene].cam_floor, &env->cam.stats.pos);
		c->b->corp.v = zero_vector(); //stop gravity
		env->phy_env.tps = 0;			// need to be variable by mesh 
		env->cam.stats.onwall = 0;
		if (c->a->corp.norm.y == 1 || c->i_a == 0)
		{
			env->cam.stats.onfloor = 1; //2 
			env->cam.stats.onplan = 0;
		}	// save the main collide
		else
		{
			env->cam.stats.onplan = 1; //3
			env->cam.stats.onfloor = 0; // save the main collide
		}
	}
}
