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
		init_button(&env->cmp_env.buttons[j],
		(t_point){76 + j * 300, 568},
		(t_sprite*[3]){&sp[i], &sp[i + 1], &sp[i + 2]});
		j++;
		i += 3;
	}
}

int		setup_cmp(t_env *env)
{
	env->ts_env.env = env;
	init_buttons_cmp(env);
	return (0);
}
