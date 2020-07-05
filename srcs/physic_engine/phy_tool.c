/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phy_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <bebosson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:44:09 by bebosson          #+#    #+#             */
/*   Updated: 2020/06/30 16:19:23 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	test_distance_camplan(t_collide c, t_vec3d *cam_vec) //8 // fonction hyper importante a refaire 
{
	float diff;

	diff = cam_vec->y - c.a->corp.pos.y;
	printf("diff = %f \n", diff);
	if (diff < 0.3 && diff > 0)
		cam_vec->y += 0.1;
}

bool	ft_good_diago(t_vec3d u, t_vec3d *dir)
{
	if (fabs(u.y) == 2 && vec_dot(*dir , u) > 0 
			&& (fabs(u.x) != 0 && fabs(u.z) != 0)) 
		return (true);
	return (false);
}
/*
static bool	look_for_diago(t_triangle *tri, t_vec3d *dir)
{
	t_vec3d u;
	t_vec3d v;
	t_vec3d w;

	u = vec_sub(tri->points[0], tri->points[1]);
	if (ft_good_diago(u, dir) == true) 
	{
		printf("dot = %f\n",vec_dot(*dir , u));
		print_vec(u);
		return (true);
//		return (u);
	}	
	v = vec_sub(tri->points[1], tri->points[2]);
	if (ft_good_diago(v, dir) == true) 
	{
		printf("dot = %f\n",vec_dot(*dir , v));	
		print_vec(v);
		return (true);
	}
	w = vec_sub(tri->points[2], tri->points[0]);
	print_vec(w);
	if (ft_good_diago(w, dir) == true)
	{
		printf("dot = %f\n",vec_dot(*dir , w));	
		print_vec(w);
		return (true);
	}
	return (false);

}
*/
static t_vec3d	look_for_slope_vect(t_triangle *tri, t_vec3d *dir)
{
	t_vec3d u;
	t_vec3d v;
	t_vec3d w;

	u = vec_sub(tri->points[0], tri->points[1]);
	if (vec_dot(u, *dir) < 0) 
		return ((t_vec3d){-u.x, -u.y, -u.z, -u.w});
	v = vec_sub(tri->points[1], tri->points[2]);
	if (vec_dot(v, *dir) < 0) 
		return ((t_vec3d){-v.x, -v.y, -v.z, -v.w});
	w = vec_sub(tri->points[2], tri->points[0]);
	if (vec_dot(w, *dir) < 0)
		return ((t_vec3d){-v.x, -v.y, -v.z, -v.w});
	return (zero_vector());
}




t_vec3d *coefdir_plan(t_env *env, t_mesh *m, t_mesh *cam, t_vec3d *dir) //6
{
	t_vec3d w;
	t_vec3d	*new_dir;
	t_vec3d step_dir;

	(void)cam;
	w = (t_vec3d){2,0,2,0};
  	if (m->tris.nb_cells == 8 && env->cam.stats.onfloor == 1) 	
	{
		w = look_for_slope_vect(dyacc(&m->tris, 4), dir);
		print_vec(w);
	}
	// test diff pos btw point et cam.pos pour voir si c pas un mur
	//else look_for_wall => zero_vector
	new_dir = dir;
	step_dir = project_ortho(w, *dir);
	new_dir->y = step_dir.y;
	if (new_dir->y < 0.8 && m->tris.nb_cells == 8)
		new_dir->y = 0.8;
	print_vec(*new_dir);
	return (new_dir);
}

t_vec3d		phy_move_collide(t_env *env, t_collide *c, t_vec3d dir) //5
{
	t_mesh *a;
	t_mesh *cam;
	t_vec3d f;	
	
	(void)dir;
	a = c->a;
	cam = c->b;
	f = vec_fmult(*coefdir_plan(env, a, cam, &dir), MAPED_WALK_SPEED * env->cam.stats.speed); 
	return (f);
}

t_vec3d	set_y_dir(t_env *env, t_map *map) //3
{
	t_vec3d f;

	f = (t_vec3d){2, 0, 2, 0};
	if (env->cam.stats.onwall == 0)
		f = phy_move_collide(env, map->cam_floor, env->cam.stats.dir);
	else if (env->cam.stats.onwall == 1)
		f = phy_move_collide(env, map->cam_wall, env->cam.stats.dir);
	return (f);
}

void print_vect_face(t_triangle *tri, t_vec3d *dir)
{
	t_vec3d u;
	t_vec3d v;
	t_vec3d w;
	(void)dir;
	(void)tri;	
//	printf("loookforcloth\n");
//	printf("----------------\n");
//	print_vec(tri->points[0]);
//	print_vec(tri->points[1]);
//	print_vec(tri->points[2]);
//	printf("----------------\n");
	//dir only in vec_dot < 0 way? 
	u = vec_sub(tri->points[0], tri->points[1]);
	v = vec_sub(tri->points[1], tri->points[2]);
	w = vec_sub(tri->points[2], tri->points[0]);
//	printf("dotu = %f\n",vec_dot(*dir , u));	
///	printf("dotv = %f\n",vec_dot(*dir , v));	
//	printf("dotw = %f\n",vec_dot(*dir , w));	
//	printf("w = ");
//	print_vec(u);
//	print_vec(v);
//	print_vec(w);
//	print_vec(*dir);

//	printf("----------------\n");
//			printf("-----------projete_u------\n");
//	print_vec(project_ortho(*dir, u));
// printf("-----------projete_v------\n");
//	print_vec(project_ortho(*dir, v));
 ///printf("-----------projete_w------\n");
//	print_vec(project_ortho(*dir, w));
}

t_vec3d		look_for_cloth_side(t_collide *c, t_triangle *tri, t_vec3d diff, int tris_num)
{
	t_vec3d test_diff;
	t_vec3d pos;
	int		i;

	i = -1;
	test_diff = diff;
	pos = c->b->corp.pos;

	print_vec(tri->normal);
	while (++i < 3)
	{
//		printf("point_%d\n",i);
//		print_vec(tri->points[i]);
//		printf("calcul test_diff\n");
//		print_vec(vec_sub(pos, tri->points[i]));
		if (vec_norm(vec_sub(pos, tri->points[i])) < vec_norm(test_diff))
		{
//			printf("face saved\n");
			c->diffwall = vec_sub(pos, tri->points[i]);
			test_diff = vec_sub(pos, tri->points[i]);
			c->cloth_face = tris_num;
		}

	}
//	print_vec(vec_sub(pos, tri->points[0]));
//	print_vec(vec_sub(pos, tri->points[1]));
//	print_vec(vec_sub(pos, tri->points[2]));
//	printf("------CALCUL--------\n");
//	test_diff = vec_sub(pos, tri->points[0]);
//
//	printf("test_diff\n");
//	print_vec(test_diff);
	return (test_diff);
}

void	parse_mesh_side(t_collide *c, t_mesh *wall, t_vec3d *dir)
{
	int	tris_num;
	t_vec3d diff_face;

	tris_num = -1;
	diff_face = (t_vec3d){2, 2, 2, 0};
	(void)dir;	
	while (++tris_num < wall->tris.nb_cells) // si la diago est tjrs a lindex 4 pas besoin de look for diago 
	{
//		printf("face = %d\n", tris_num);
//		print_vect_face(dyacc(&wall->tris, tris_num), dir);
		diff_face = look_for_cloth_side(c, dyacc(&wall->tris, tris_num), diff_face, tris_num);
	}
//	printf("test_diff_final\n");
//	print_vec(diff_face);

}
/*						A REFAIRE			*/
t_vec3d test_dist_wall(t_env *env, t_collide *c, t_vec3d f)
{
	t_mesh *cam;
	t_mesh *wall;
	t_vec3d vec;
	t_vec3d vec2;
	(void)env;
	cam = c->b;
	wall = c->a;
	
	vec = vec_sub(wall->corp.pos, cam->corp.pos);
	vec2 = (t_vec3d){vec.x, 0, vec.z, 0};
	if (wall->tris.nb_cells > 8 && vec_dot(f, vec2) > 0 
			&& vec_dot(f, vec2) < 0.5
			&& vec_norm(vec2) < 2.5)
		f = vec_fmult(vec2, -0.0075);
	else if (wall->tris.nb_cells == 8)
	{
		printf("f_dist_wall");
		if (f.y > 0 && f.y < 0.8)
			f.y = 0.8;
		print_vec(f);
	}
		
	return (f);
}

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

static	void	scan_actuall_collide(t_env *env, t_map *map)
{
	(void)map;
	if (env->cam.stats.onwall == 1) 
	{
		map->cam_wall->cam_mesh_actual = vec_sub(env->cam.stats.pos, map->cam_wall->a->corp.pos);
		map->cam_wall->norm_dist_actual = vec_norm(map->cam_wall->cam_mesh_actual);
		if (map->cam_wall->norm_dist_actual > map->cam_wall->norm_dist_first)
			env->cam.stats.onwall = 0;

	}
	if (env->cam.stats.onfloor == 1) 
	{
		map->cam_floor->cam_mesh_actual = vec_sub(env->cam.stats.pos, map->cam_floor->a->corp.pos);
		map->cam_floor->norm_dist_actual = vec_norm(map->cam_floor->cam_mesh_actual);
		if (map->cam_floor->norm_dist_actual > map->cam_floor->norm_dist_first)
			env->cam.stats.onfloor = 0;
	}
	if (env->cam.stats.onroof == 1) 
	{
		map->cam_roof->cam_mesh_actual = vec_sub(env->cam.stats.pos, map->cam_roof->a->corp.pos);
		map->cam_roof->norm_dist_actual = vec_norm(map->cam_roof->cam_mesh_actual);
		if (map->cam_roof->norm_dist_actual > map->cam_roof->norm_dist_first)
			env->cam.stats.onroof = 0;
	}
}

void	type_of_plan(t_env *env, t_collide *c, t_map *map)
{
	if (env->cam.stats.onwall == 1 || env->cam.stats.onfloor == 1 || env->cam.stats.onroof == 1)
		scan_actuall_collide(env, map);
	if (c->cam_mesh_first.y > 0) //
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
	/*
	else if (env->cam.stats.onroof == 1 )
	{
		map->cam_wall = NULL;
		env->cam.stats.onroof = 0;
	}
	*/
}
