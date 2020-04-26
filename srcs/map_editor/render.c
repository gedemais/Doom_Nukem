/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:51:39 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/26 22:24:23 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		render_maped(void *param)
{
	static int	(*sub_contexts[MAPED_SC_MAX])(t_env *env) = {maped_menu, maped_new_map, NULL};
	t_env		*env;

	env = ((t_env*)param);
	return (sub_contexts[env->edit_env.sub_context](env));
}
