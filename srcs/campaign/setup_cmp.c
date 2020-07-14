/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:58:00 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/13 20:24:03 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	init_buttons_cmp(t_env *env)
{
	t_camp_env	*cmp_env;
	t_button	*b;
	t_sprite	*sps[3];

	cmp_env = &env->cmp_env;
	b = &cmp_env->buttons[CMP_BUTTON_MAIN_MENU];
	sps[0] = &env->sprites[SP_CP_BUTTON_1C];
	sps[1] = &env->sprites[SP_CP_BUTTON_1H];
	sps[2] = &env->sprites[SP_CP_BUTTON_1O];
	init_button(b, (t_point){70, 600}, sps);

	b = &cmp_env->buttons[CMP_BUTTON_NEW_GAME];
	sps[0] = &env->sprites[SP_CP_BUTTON_2C];
	sps[1] = &env->sprites[SP_CP_BUTTON_2H];
	sps[2] = &env->sprites[SP_CP_BUTTON_2O];
	init_button(b, (t_point){330, 600}, sps);
}

int		init_keys(t_env *env)
{
	static t_vec3d	pos[SECTOR_MAX] = {{10.0f, 10.0f, 10.0f, 0},
								{10.0f, 10.0f, 10.0f, 0}};
	t_map			*map;
	int				i;

	i = 0;
	while (i < SECTOR_MAX)
	{
		map = &env->maps[env->cmp_env.sectors[i].map];
		if (!(env->cmp_env.key[i] = copy_to_scene(map, &env->maps[SCENE_KEY], pos[i])))
			return (-1);
		i++;
	}
	return (0);
}

int		setup_cmp(t_env *env)
{
	env->ts_env.env = env;
	init_buttons_cmp(env);
	init_sectors(env);
	if (init_keys(env))
		return (-1);
	return (0);
}
