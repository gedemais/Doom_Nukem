/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phy_gravity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <bebosson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:44:03 by bebosson          #+#    #+#             */
/*   Updated: 2020/05/22 14:45:48 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	phy_gravitax_cam(t_env *env, t_mesh *m, t_cam_stats *stats)
{
	static  t_vec3d		gravitax;

	(void)stats;
	gravitax = (t_vec3d){0, env->phy_env.tps * env->phy_env.gravity * 50 , 0 ,0};
	m->corp.v = vec_sub(m->corp.v, gravitax);
	printf("gravitax\n");
	printf("tps = %d\n", env->phy_env.tps);
	if (env->phy_env.tps < 10)
		env->phy_env.tps += 2.5;
	else
	{
		if (stats->pos.y < -10)
		{
			printf("STOP_POS\n");
			env->phy_env.tps = 0;
			stats->pos = zero_vector();
			m->corp.v = zero_vector();
		}
	}
}


void	phy_gravitax(t_env *env, t_mesh *m, int i)
{
	static  t_vec3d		gravitax;

	gravitax = (t_vec3d){0, env->phy_env.tps * env->phy_env.gravity , 0 ,0};
	if (env->maps[env->scene].stats[i] == false)
	{
		m->corp.v = vec_sub(m->corp.v, gravitax);
		if (env->phy_env.tps < 900)
			env->phy_env.tps++;
	}
}
