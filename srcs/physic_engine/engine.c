/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:37:28 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/14 20:37:42 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
void print_mesh_corp(t_mesh m)
{
//	printf("acc |");
//	print_vec(m.corp.acc);
//	printf("vo |");
//	print_vec(m.corp.vo);
//	printf("v |");
//	print_vec(m.corp.v);
//	printf("v_cpy |");
//	print_vec(m.corp.v_cpy);
	printf("pos |");
	print_vec(m.corp.pos);
	printf("o |");
	print_vec(m.corp.o);
//	printf("norm |");
//	print_vec(m.corp.norm);
//	printf("dims |");
//	print_vec(m.corp.dims);
	printf("type %d|", m.type);
}

void	print_collide(t_collide c)
{
	printf("%d\n", c.i_a);
	print_mesh_corp(*c.a);

}

void	print_info_phy(t_env *env, t_mesh *cam, t_map *maps)
{
	printf("-----------------PRINT_INFO---------------------\n");
	printf("floor %d \n", env->cam.stats.onfloor);
	printf("wall %d \n", env->cam.stats.onwall);
	printf("roof %d \n", env->cam.stats.onroof);
	printf("------------------------------------------------\n");
	printf("cam->corp.pos\n");
	print_vec(cam->corp.pos);
	printf("cam->corp.v\n");
	print_vec(cam->corp.v);
	printf("-----------------------------------------------\n");
	printf("env->cam.stats.pos\n");
	print_vec(env->cam.stats.pos);
	printf("-------------------COLIDE WALL-------------------------\n");
	if (env->cam.stats.onwall == 1)
		print_collide(*maps->cam_wall);
	printf("-------------------COLIDE FLOOR-------------------------\n");
	if (env->cam.stats.onfloor == 1)
	{
		print_collide(*maps->cam_floor);
		print_vec(maps->cam_floor->cam_mesh_first);
	}
	printf("-------------------COLIDE ROOF-------------------------\n");
	if (env->cam.stats.onroof == 1)
		print_collide(*maps->cam_roof);
}

int		physic_engine(t_env *env, t_map *maps)
{
	t_events	*e;
	t_mesh		*cam;

	cam = &maps->cam;
	e = &env->events;
	print_info_phy(env, cam, maps);
	report_cam_collisions(env, maps);
	update_speeds_collide_cam(env, cam, maps);
	update_positions_cam(env, maps, cam);
	stop_position_cam(env, maps, cam);
	clear_dynarray(&env->phy_env.collides_cam);
	env->custom_env.game.moula < 0 ? env->custom_env.game.moula = 0 : 0;
	return (0);
}
