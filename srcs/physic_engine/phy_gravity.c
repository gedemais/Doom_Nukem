/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phy_gravity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benji_code <benji_code@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:44:03 by bebosson          #+#    #+#             */
/*   Updated: 2020/07/14 19:56:23 by benji_code       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	phy_gravitax_cam(t_env *env, t_mesh *m)
{
	float grav;

	grav = env->phy_env.tps * env->phy_env.gravity * 50;
	env->phy_env.gravitax = (t_vec3d){0, grav, 0, 0};
	m->corp.v = vec_sub(m->corp.v, env->phy_env.gravitax);
	if (env->phy_env.tps < 10)
		env->phy_env.tps += 2.5;
}
