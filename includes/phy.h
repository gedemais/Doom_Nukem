/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phy.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 03:01:19 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/15 05:12:03 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHY_H
# define PHY_H

struct	s_physics
{
	float	gravity;

};

int		init_physic_engine(t_env *env);

int		report_collisions(t_env *env);


void	translate_mesh(t_mesh *m, t_vec3d t);

#endif
