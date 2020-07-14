/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phy_tool2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benji_code <benji_code@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:18:33 by benji_code        #+#    #+#             */
/*   Updated: 2020/07/14 20:18:39 by benji_code       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	is_mesh_mob(t_env *env, t_mesh *m)
{
	t_enemy	*mob;
	int		i;

	i = 0;
	while (i < env->custom_env.mobs.nb_cells)
	{
		mob = dyacc(&env->custom_env.mobs, i);
		if (m->index >= mob->map_start && m->index < mob->map_end)
			return (true);
		i++;
	}
	return (false);
}

void		scan_actuall_collide(t_env *env, t_map *map)
{
	if (env->cam.stats.onwall == 1)
	{
		map->cam_wall->cam_actual =
		vec_sub(map->cam.corp.pos, map->cam_wall->a->corp.pos);
		map->cam_wall->norm_actual = vec_norm(map->cam_wall->cam_actual);
		if (map->cam_wall->norm_actual > map->cam_wall->norm_dist_first)
			env->cam.stats.onwall = 0;
	}
	if (env->cam.stats.onfloor == 1)
	{
		map->cam_floor->cam_actual =
		vec_sub(map->cam.corp.pos, map->cam_floor->a->corp.pos);
		map->cam_floor->norm_actual = vec_norm(map->cam_floor->cam_actual);
		if (map->cam_floor->norm_actual > map->cam_floor->norm_dist_first)
			env->cam.stats.onfloor = 0;
	}
	if (env->cam.stats.onroof == 1)
	{
		map->cam_roof->cam_actual =
		vec_sub(map->cam.corp.pos, map->cam_roof->a->corp.pos);
		map->cam_roof->norm_actual = vec_norm(map->cam_roof->cam_actual);
		if (map->cam_roof->norm_actual > map->cam_roof->norm_dist_first)
			env->cam.stats.onroof = 0;
	}
}

void		type_of_plan(t_env *env, t_collide *c, t_map *map)
{
	if (c->cam_mesh_first.y > 0)
	{
		map->cam_floor = c;
		env->cam.stats.onfloor = !is_mesh_mob(env, c->a);
	}
	if (c->cam_mesh_first.y < 2
			&& c->cam_mesh_first.y > -1)
	{
		env->cam.stats.onwall = !is_mesh_mob(env, c->a);
		map->cam_wall = c;
	}
	if (c->cam_mesh_first.y < -2)
	{
		map->cam_roof = c;
		env->cam.stats.onroof = !is_mesh_mob(env, c->a);
	}
}

void		stop_position_cam(t_env *env, t_map *maps, t_mesh *cam)
{
	float		move;

	(void)maps;
	move = 0.0f;
	if (env->cam.stats.pos.y < -10 || env->cam.stats.onfloor == 1)
	{
		env->phy_env.tps = 0;
		cam->corp.v.y = 0;
		cam->corp.v = vec_fmult(cam->corp.v, 0.4);
		if (env->cam.stats.pos.y - maps->cam_floor->a->corp.pos.y < 4
			&& env->cam.stats.pos.y - maps->cam_floor->a->corp.pos.y > 0
			&& maps->cam_floor->a->tris.nb_cells == 8
			&& env->cam.stats.onroof == 0)
		{
			move = 4 - env->cam.stats.pos.y + maps->cam_floor->a->corp.pos.y;
			cam->corp.v = vec_add(cam->corp.v, (t_vec3d){0, move, 0, 0});
		}
		if (env->cam.stats.pos.y < -10)
			translate_mesh(maps, cam, vec_sub(maps->spawn, cam->corp.pos));
	}
}

void		scan_collide(t_collide *c, int i)
{
	c->cam_mesh_first = vec_sub(c->b->corp.pos, c->a->corp.pos);
	c->norm_dist_first = vec_norm(c->cam_mesh_first);
	c->i_a = i;
}
