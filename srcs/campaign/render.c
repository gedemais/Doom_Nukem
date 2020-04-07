/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 01:53:02 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/07 10:21:43 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	init_cmp_routines(void (*cmp_routines[CMP_SC_MAX][CMP_SC_MAX])(t_env*))
{
	cmp_routines[CMP_SC_MENU][CMP_SC_GAME] = cmp_menu_to_game;
	cmp_routines[CMP_SC_GAME][CMP_SC_MENU] = cmp_game_to_menu;
}

int		switch_campaign_subcontext(t_env *env, unsigned int i)
{
	t_camp_env		*cmp_env;
	static bool		first = true;
	static void		(*cmp_routines[CMP_SC_MAX][CMP_SC_MAX])(t_env*) = {};

	cmp_env = &env->cmp_env;
	if (first)
		init_cmp_routines(cmp_routines);
	if (i >= CMP_SC_MAX)
	{
		ft_putstr_fd(ISCS_ERR, 2);
		return (-1);
	}
	if (cmp_routines[cmp_env->sub_context][i])
		cmp_routines[cmp_env->sub_context][i](env);
	cmp_env->sub_context = i;
	first = false;
	return (0);
}

int		render_camp(void *param)
{
	t_env		*env;
	t_camp_env	*cmp_env;
	static int	(*cmp_sub_contexts[CMP_SC_MAX])(void*) = {cmp_menu, cmp_game};

	env = ((t_env*)param);
	cmp_env = &env->cmp_env;
	if (cmp_sub_contexts[cmp_env->sub_context](env))
		return (-1);
	return (0);
}
