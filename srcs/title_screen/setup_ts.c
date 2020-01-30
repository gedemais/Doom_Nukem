/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:58:00 by gedemais          #+#    #+#             */
/*   Updated: 2020/01/30 03:26:30 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	init_buttons(t_env *env)
{
	t_sprite		*sp;
	unsigned int	i;
	int				y_offset;

	i = 0;
	sp = env->sprites;
	y_offset = 300;
	while (i < TS_BUTTON_MAX)
	{
		init_button(&env->ts_env.buttons[i],
		(t_point){415, y_offset},
		(t_sprite*[3]){&sp[i * 3], &sp[i * 3 + 1], &sp[i * 3 + 2]});
		y_offset += 80;
		i++;
	}
}

int		setup_ts(t_env *env)
{
	env->ts_env.env = env;
	init_buttons(env);
	return (0);
}
