/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phy_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benji_code <benji_code@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:44:16 by bebosson          #+#    #+#             */
/*   Updated: 2020/07/14 20:07:12 by benji_code       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	update_speeds_collide_cam(t_env *env, t_mesh *cam, t_map *map)
{
	t_collide			*c;
	int					i;
	int					j;

	i = 0;
	j = 0;
	if (env->cam.stats.onwall == 1 || env->cam.stats.onfloor == 1
		|| env->cam.stats.onroof == 1)
		scan_actuall_collide(env, map);
	while (i < env->phy_env.collides_cam.nb_cells)
	{
		c = dyacc(&env->phy_env.collides_cam, i);
		type_of_plan(env, c, map);
		i++;
	}
	if ((env->cam.stats.onwall == 0 && env->cam.stats.onfloor == 0) || (i == 0))
	{
		env->cam.stats.onfloor = 0;
		phy_gravitax_cam(env, cam);
	}
}

void	update_positions_cam(t_env *env, t_map *map, t_mesh *cam)
{
	translate_mesh(map, cam, cam->corp.v);
	env->cam.stats.pos = vec_add(env->cam.stats.pos, cam->corp.v);
	cam->corp.o = vec_sub(env->cam.stats.pos, vec_fdiv(cam->corp.dims,
	1.0f * env->cam.stats.crouch));
}
