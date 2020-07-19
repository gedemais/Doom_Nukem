/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:58:00 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/19 21:45:06 by gedemais         ###   ########.fr       */
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

int		setup_cmp(t_env *env)
{
	env->ts_env.env = env;
	init_buttons_cmp(env);
	init_sectors(env);
	return (0);
}
