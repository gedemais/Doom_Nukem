/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phy_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <bebosson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:44:09 by bebosson          #+#    #+#             */
/*   Updated: 2020/05/22 14:45:48 by bebosson         ###   ########.fr       */
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

void print_vect_face(t_triangle *tri, t_vec3d *dir)
{
	t_vec3d u;
	t_vec3d v;
	t_vec3d w;

	u = vec_sub(tri->points[0], tri->points[1]);
	printf("dot = %f\n",vec_dot(*dir , u));
	print_vec(u);
//		return (u);
	v = vec_sub(tri->points[1], tri->points[2]);
	printf("dot = %f\n",vec_dot(*dir , v));	
	print_vec(v);
	w = vec_sub(tri->points[2], tri->points[0]);
	printf("dot = %f\n",vec_dot(*dir , w));	
	print_vec(w);
}

t_vec3d	ft_look_for_slope(t_mesh *m, t_vec3d *dir)
{
	int	tris_num;
	t_vec3d slope;
	int	tris_diago;

	tris_num = -1;
	(void)slope;
	if (m->tris.nb_cells > 8)
		return ((t_vec3d){2,0,2,0}); // return proj_ortho(2,0,2) ? 
	while (++tris_num < m->tris.nb_cells)
	{
		if (look_for_diago(dyacc(&m->tris, tris_num), dir) == true)
			tris_diago = tris_num;
	}
	slope = look_for_slope_vect(dyacc(&m->tris, tris_diago), dir);
	return (slope);
}

t_vec3d *coefdir_plan(t_mesh *m, t_vec3d *dir) //6
{
	t_vec3d w;
	t_vec3d	*new_dir;
	t_vec3d step_dir;
	
	w = ft_look_for_slope(m, dir);
	new_dir = dir;
	step_dir = project_ortho(w, *dir);
	new_dir->y = step_dir.y;
	return (new_dir);
}

t_vec3d		fps_move_print(t_collide *c, t_vec3d dir) //5
{
	t_mesh *a;
	t_vec3d f;	
	
	(void)dir;
	a = c->a;
//	print_collide(*c);
	f = vec_fmult(*coefdir_plan(a, &dir), MAPED_WALK_SPEED); 
	return (f);
}

t_vec3d	set_y_dir(t_env *env, t_map *map) //3
{
	t_vec3d f;

	f = fps_move_print(&map->cam_floor, env->cam.stats.dir);
	return (f);

}
/*						A REFAIRE			*/
t_vec3d test_dist_wall(t_env *env, t_collide *c, t_vec3d f)
{
	t_mesh *cam;
	t_mesh wall;
	t_vec3d norm_wall;

	(void)env;
	cam = c->b;
	wall = *(c->a);
	norm_wall = wall.corp.norm;
	if (vec_dot(f, norm_wall) < 0 && c->i_a != 0)
		return (zero_vector());
	else
		return (f);
}

void	type_of_plan(t_env *env, t_collide *c, t_map *map)
{
	map->cam_floor = *c;
	env->cam.stats.onfloor = 1;
}
