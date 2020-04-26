/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:58:00 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/26 22:06:54 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	init_buttons(t_env *env)
{
	t_edit_env	*me_env;
	t_button	*b;
	t_sprite	*sps[3];

	me_env = &env->edit_env;
	b = &me_env->buttons[MAPED_MENU_BUTTON_MAIN_MENU];
	sps[0] = &env->sprites[SP_CP_BUTTON_1C];
	sps[1] = &env->sprites[SP_CP_BUTTON_1H];
	sps[2] = &env->sprites[SP_CP_BUTTON_1O];
	init_button(b, (t_point){800, 600}, sps);

	b = &me_env->buttons[MAPED_MENU_BUTTON_NEW_MAP];
	sps[0] = &env->sprites[SP_ME_BUTTON_2C];
	sps[1] = &env->sprites[SP_ME_BUTTON_2H];
	sps[2] = &env->sprites[SP_ME_BUTTON_2O];
	init_button(b, (t_point){800, 500}, sps);
}

int		setup_medit(t_env *env)
{
	env->edit_env.env = env;
	env->edit_env.sub_context = MAPED_SC_MENU;
	init_buttons(env);
	return (0);
}
