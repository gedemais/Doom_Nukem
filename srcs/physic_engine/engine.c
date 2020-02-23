/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:15:21 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/23 19:58:26 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		physic_engine(t_env *env)
{
	report_collisions(env);
	//printf("%d collisions\n", env->phy_env.collides.nb_cells);
	clear_dynarray(&env->phy_env.collides);
	return (0);
}
