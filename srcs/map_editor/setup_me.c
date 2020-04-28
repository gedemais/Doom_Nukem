/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:58:00 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/29 00:11:05 by gedemais         ###   ########.fr       */
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

static int	init_fields(t_env *env)
{
	t_ttf	*ttf;

	ttf = &env->edit_env.ttfs;
	ttf->fields[0] = {.o = (t_point){100, 100}, .offset = 0, .in = false};
	ttf->fields[1] = {.o = (t_point){200, 200}, .offset = 0, .in = false};
	ttf->fields[2] = {.o = (t_point){300, 300}, .offset = 0, .in = false};
	ttf->fields[3] = {.o = (t_point){400, 400}, .offset = 0, .in = false};

	if (!(ttf->fields[0].name = (unsigned char*)ft_strdup("Width"))
		|| !(ttf->fields[1].name = (unsigned char*)ft_strdup("Height"))
		|| !(ttf->fields[2].name = (unsigned char*)ft_strdup("Height"))
		|| !(ttf->fields[3].name = (unsigned char*)ft_strdup("Name")))
		return (-1);

	if (init_dynarray(&ttf->fields[0].str, sizeof(char), 0)
		|| init_dynarray(&ttf->fields[1].str, sizeof(char), 0)
		|| init_dynarray(&ttf->fields[2].str, sizeof(char), 0)
		|| init_dynarray(&ttf->fields[3].str, sizeof(char), 0))
		return (-1);
	return (0);
}


int			setup_medit(t_env *env)
{
	env->edit_env.env = env;
	env->edit_env.sub_context = MAPED_SC_MENU;
	init_buttons(env);
	if (init_fields(env))
		return (-1);
	return (0);
}
