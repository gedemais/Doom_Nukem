/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:50:02 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/10 09:52:06 by gedemais         ###   ########.fr       */
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
	env->cmp_env.player.current.ammos = 120;
	env->cmp_env.player.current.magazine = 30;
	env->cmp_env.player.current.loaded = 30;


	env->context = C_CAMPAIGN;
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
