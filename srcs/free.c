/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 05:31:43 by gedemais          #+#    #+#             */
/*   Updated: 2020/06/14 20:55:31 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	free_map_childrens(t_map *map)
{
	t_mesh	*m;
	t_mtl	*mtl;
	int		i;

	i = 0;
	while (i < map->meshs.nb_cells)
	{
		m = dyacc(&map->meshs, i);
		if (m->name)
			free(m->name);
		if (m->tris.byte_size)
			free_dynarray(&m->tris);
		if (m->deps.byte_size)
			free_dynarray(&m->deps);
		i++;
	}
	i = 0;
	while (i < map->mtls.nb_cells)
	{
		mtl = dyacc(&map->mtls, i);
		free(mtl->name);
		i++;
	}
}

static void	free_map(t_map *map)
{
	free_map_childrens(map);
	if (map->meshs.byte_size)
		free_dynarray(&map->meshs);
	if (map->txts.byte_size)
		free_dynarray(&map->txts);
	if (map->mtls.byte_size)
		free_dynarray(&map->mtls);
	if (map->stats)
		free(map->stats);
	if (map->stats_cpy)
		free(map->stats_cpy);
}

static void	free_cam(t_cam *cam)
{
	int		i;

	if (cam->clip_arrs[0].byte_size)
	{
		i = -1;
		while (++i < 4)
			free_dynarray(&cam->clip_arrs[i]);
	}
	if (cam->to_clip.byte_size)
		free_dynarray(&cam->to_clip);
	if (cam->to_raster.byte_size)
		free_dynarray(&cam->to_raster);
	if (cam->z_buffer)
		free(cam->z_buffer);
}

static void	free_fields(t_env *env)
{
	int		i;

	i = 0;
	while (i < FIELD_MAX)
	{
		free(env->ttfs.fields[i].name);
		free_dynarray(&env->ttfs.fields[i].str);
		i++;
	}
	input_fields(env, false, true);
}

static void	free_player(t_player *p)
{
	t_weapon	*w;
	int			i;

	i = 0;
	while (i < p->weapons.nb_cells)
	{
		w = dyacc(&p->weapons, i);
		free(w->name);
		i++;
	}
	if (p->weapons.byte_size)
		free_dynarray(&p->weapons);
}

static void	free_cmp(t_env *env)
{
	(void)env;
}

static void	free_custom(t_env *env)
{
	free_player(&env->player);
	if (env->mobs.byte_size)
		free_dynarray(&env->mobs);
	if (env->astar.d_nodes.byte_size)
		free_dynarray(&env->astar.d_nodes);
	if (env->astar.d_astar.byte_size)
		free_dynarray(&env->astar.d_astar);
	if (env->edit_env.map.meshs.byte_size)
		free_map(&env->edit_env.map);
}

static void	free_maped(t_env *env)
{
	if (env->edit_env.map.meshs.byte_size)
		free_map(&env->edit_env.map);
}

int			free_env(t_env *env)
{
	static void	(*free_context[C_MAX])(t_env*) = {NULL, NULL, free_cmp,
													free_custom, free_maped};
	int		i;

	i = 0;
	pixloc(0, 0, true);
	free_fields(env);
	free_cam(&env->cam);

	while (i < SP_MAX)
	{
		if (i < SCENE_MAX)
			free_map(&env->maps[i]);
		mlx_destroy_image(env->mlx.mlx_ptr, env->sprites[i].img_ptr);
		i++;
	}

	if (free_context[env->context])
		free_context[env->context](env);
	return (0);
}
