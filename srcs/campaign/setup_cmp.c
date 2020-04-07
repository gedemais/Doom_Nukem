/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:58:00 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/07 10:20:41 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	init_pos_cmp(t_env *env)
{
	t_point *pt;
	
	pt = env->cmp_env.pos;
	pt[CMP_BTN_MMENU] = (t_point){69, 607};
	pt[CMP_BTN_NWG] = (t_point){329, 607};
	pt[CMP_BTN_LDG] = (t_point){69, 550}; 

}

static void	init_buttons_cmp(t_env *env)
{
	t_sprite		*sp;
	unsigned int	i;
	unsigned int	j;

	j = CMP_BTN_MMENU;
	i = SP_CP_BUTTON_1C;
	sp = env->sprites;
	while (j < CMP_BUTTON_MAX)
	{
		init_button(&env->cmp_env.buttons[j], env->cmp_env.pos[j],
		(t_sprite*[3]){&sp[i], &sp[i + 1], &sp[i + 2]});
		j++;
		i += 3;
	}
}

int		setup_cmp(t_env *env)
{
	env->ts_env.env = env;
	init_pos_cmp(env);
	init_buttons_cmp(env);
	init_sectors(env);
	return (0);
}
