/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:58:00 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/11 05:50:31 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	init_pos_me(t_env *env)
{
	t_point *pt;
	
	pt = env->edit_env.pos;
	pt[EDT_BTN_LOAD] = (t_point){338, 450};
	pt[EDT_BTN_NEW] = (t_point){538, 450};
	pt[EDT_BTN_TXT] = (t_point){338, 575};
	pt[EDT_BTN_OBJ] = (t_point){538, 575};
	pt[EDT_BTN_MMENU] = (t_point){751, 450};

}

static void	init_buttons_me(t_env *env)
{
	t_sprite		*sp;
	unsigned int	i;
	unsigned int	j;
	unsigned int	y_s;

	j = EDT_BTN_LOAD;
	i = SP_ME_BUTTON_LD_O;
	sp = env->sprites;
	y_s = 0;
	while (j < EDT_BUTTON_MAX)
	{
		init_button(&env->edit_env.buttons[j], env->edit_env.pos[j],
		(t_sprite*[3]){&sp[i], &sp[i + 1], &sp[i + 2]});
		j++;
		i += 3;
	}
}

int		setup_medit(t_env *env)
{
	env->ts_env.env = env;
	init_pos_me(env);
	init_buttons_me(env);
	return (0);
}
