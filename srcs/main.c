/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:50:02 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/08 04:52:42 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	doom_nukem(t_env *env)
{
	srand(time(NULL));
	if (setup(env))
		return (-1);

/*	t_mesh	*m;
	t_triangle	*t;

	mlx_mouse_hide();
	m = (t_mesh*)env->maps[0].meshs.c;
	for (int i = 0; i < m->tris.nb_cells; i++)
	{
		t = dyacc(&m->tris, i);
		if (t->textured)
			t->sp = &env->sprites[TXT_BLOC_GRASS];
	}*/
	//mlx_mouse_hide();
	env->context = C_TITLE_SCREEN;
	env->scene = SCENE_A;
	mlx_mouse_move(env->mlx.mlx_win, WDT / 2, HGT / 2);
	mlx_hooks(env);
	return (0);
}

int			main(void)
{
	t_env	env;

	ft_memset(&env, 0, sizeof(t_env));
	if (doom_nukem(&env))
	{
		ft_putstr_fd("Error\n", 2);
		free_env(&env);
		return (1);
	}
	free_env(&env);
	return (0);
}
