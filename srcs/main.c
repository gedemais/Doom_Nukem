/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:50:02 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/28 23:03:09 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		setup(t_env *env)
{
	if (!(env->mlx_ptr = mlx_init()))
		return (-1);
}

static inline int	doom_nukem()

int					main(void)
{
	t_env	env;

	if (setup(&env))
	return (0);
}
