/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:34:45 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/06 18:53:08 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			setup(t_env *env)
{
	if (init_mlx(env) != 0
		|| !(env->sprites = load_sprites(&env->mlx)))
		return (-1);
	if (init_openal(&env->sound) != 0)
		return (-1);
	init_camera(&env->cam);
	env->context = C_DEV;
//	play_ambience(env->sound.samples[SA_AMB_1], true, false);
	return (0);
}
