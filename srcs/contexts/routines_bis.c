/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:53:57 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/29 17:13:18 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	custom_to_ts(t_env *env)
{
	(void)env;
	mlx_mouse_show();
}

void	map_editor_to_ts(t_env *env)
{
	(void)env;
	// Disable les saisies de texte du menu new_map
	env->ttfs.fields[0].rendered = false;
	env->ttfs.fields[1].rendered = false;
	env->ttfs.fields[2].rendered = false;
	env->ttfs.fields[3].rendered = false;
	env->ttfs.fields[4].rendered = false;

	mlx_mouse_show(); // ?
}
