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

t_vec3d *coefdir_plan(t_mesh *m, t_vec3d *dir) //6
{
	t_triangle *tri;
	t_vec3d v;
	t_vec3d w;
	t_vec3d u;
	t_vec3d x;
	t_vec3d y;
	t_vec3d z;
	t_vec3d	*new_dir;
	t_vec3d step_dir;
	
	tri = dyacc(&m->tris, 0);
	x = tri->points[0];
	y = tri->points[1];
	z = tri->points[2];
	/* creation vecteurs pentes */
	u = vec_sub(x, y);
	v = vec_sub(x, z);
	w = vec_sub(y, z);
	/* dot product*/
	new_dir = dir;
	step_dir = project_ortho(w, *dir);
	printf("dot = %f\n",vec_dot(step_dir , w));	
	new_dir->y = step_dir.y;
	return (new_dir);
}

t_vec3d		fps_move_print(t_collide *c, t_vec3d dir) //5
{
	t_mesh *a;
	t_vec3d f;	
	
	(void)dir;
	a = c->a;
	f = vec_fmult(*coefdir_plan(a, &dir), WALK_SPEED); 
	return (f);
}

t_vec3d	set_y_dir(t_env *env, t_map *map) //3
{
	t_vec3d f;

	f = fps_move_print(&map->cam_floor, env->cam.stats.dir);
	return (f);

}

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
	print_collide(map->cam_floor);
}
