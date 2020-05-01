/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:58:00 by gedemais          #+#    #+#             */
/*   Updated: 2020/05/01 20:28:46 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	init_new_map_buttons(t_env *env)
{
	t_edit_env	*me_env;
	t_button	*b;
	t_sprite	*sps[3];

	me_env = &env->edit_env;
	b = &me_env->buttons[MAPED_NM_BUTTON_CREATE];
	sps[0] = &env->sprites[SP_ME_BUTTON_CREATE_1C];
	sps[1] = &env->sprites[SP_ME_BUTTON_CREATE_1H];
	sps[2] = &env->sprites[SP_ME_BUTTON_CREATE_1O];
	init_button(b, (t_point){600, 500}, sps);
	b->r_down = (t_point){600 + env->sprites[SP_ME_BUTTON_CREATE_1C].wdt, 500 + env->sprites[SP_ME_BUTTON_CREATE_1C].hgt};

	b = &me_env->buttons[MAPED_NM_BUTTON_MAPED];
	sps[0] = &env->sprites[SP_NM_BUTTON_MAPED_2C];
	sps[1] = &env->sprites[SP_NM_BUTTON_MAPED_2H];
	sps[2] = &env->sprites[SP_NM_BUTTON_MAPED_2O];
	init_button(b, (t_point){200, 500}, sps);
	b->r_down = (t_point){200 + env->sprites[SP_NM_BUTTON_MAPED_2C].wdt, 500 + env->sprites[SP_NM_BUTTON_MAPED_2C].hgt};
}

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
	b->r_down = (t_point){800 + env->sprites[SP_CP_BUTTON_1C].wdt, 600 + env->sprites[SP_CP_BUTTON_1C].hgt};

	b = &me_env->buttons[MAPED_MENU_BUTTON_NEW_MAP];
	sps[0] = &env->sprites[SP_ME_BUTTON_2C];
	sps[1] = &env->sprites[SP_ME_BUTTON_2H];
	sps[2] = &env->sprites[SP_ME_BUTTON_2O];
	init_button(b, (t_point){800, 500}, sps);
	b->r_down = (t_point){800 + env->sprites[SP_ME_BUTTON_2C].wdt, 500 + env->sprites[SP_CP_BUTTON_2C].hgt};

	init_new_map_buttons(env);
}

static int	init_fields(t_env *env)
{
	t_ttf	*ttf;

	ttf = &env->ttfs;
	ft_memset(&ttf->fields, 0, sizeof(t_text_box) * FIELD_MAX);
	ttf->fields[0].o = (t_point){140, 350};
	ttf->fields[1].o = (t_point){440, 350};
	ttf->fields[2].o = (t_point){740, 350};
	ttf->fields[3].o = (t_point){540, 200};
	ttf->fields[4].o = (t_point){300, 200};

	if (!(ttf->fields[0].name = ft_strdup("Width"))
		|| !(ttf->fields[1].name = ft_strdup("Height"))
		|| !(ttf->fields[2].name = ft_strdup("Depth"))
		|| !(ttf->fields[3].name = ft_strdup("Scale"))
		|| !(ttf->fields[4].name = ft_strdup("Name")))
		return (-1);

	if (init_dynarray(&ttf->fields[0].str, sizeof(char), 0)
		|| init_dynarray(&ttf->fields[1].str, sizeof(char), 0)
		|| init_dynarray(&ttf->fields[2].str, sizeof(char), 0)
		|| init_dynarray(&ttf->fields[3].str, sizeof(char), 0)
		|| init_dynarray(&ttf->fields[4].str, sizeof(char), 0))
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
