#include "main.h"

bool	key_move(bool keys[NB_KEYS])
{
	if ((keys[KEY_W] || keys[KEY_S] || keys[KEY_A] || keys[KEY_D]) || keys[KEY_E]) 
		return (true);
	else
		return (false);
}

unsigned int		return_test_collide(t_env *env)
{
	unsigned int	ans;
	
	ans = 0;
	if (env->cam.stats.onfloor == 1)
		ans++;
	if (env->cam.stats.onroof == 1)
		ans+= 2;
	if (env->cam.stats.onwall == 1)
		ans+= 3;
	return (ans);
}

void	stop_position_cam(t_env *env, t_map *maps, t_mesh *cam)
{
	(void)maps;
	if (env->cam.stats.pos.y < -10 || env->cam.stats.onfloor == 1)
	{
		env->phy_env.tps = 0;
		cam->corp.v.y = 0;
		cam->corp.v = vec_fmult(cam->corp.v, 0.4);

//printf("actual %f\n", maps->cam_floor->a->corp.pos.y);
//		printf("pos.y%f\n", env->cam.stats.pos.y);
//	printf("diff_y%f\n", env->cam.stats.pos.y - maps->cam_floor->a->corp.pos.y);
//		printf("crouch%d\n", env->cam.stats.crouch);
		if (env->cam.stats.pos.y - maps->cam_floor->a->corp.pos.y < 4 
			&& env->cam.stats.pos.y - maps->cam_floor->a->corp.pos.y > 0
			&& maps->cam_floor->a->tris.nb_cells == 8
			&& env->cam.stats.onroof == 0)
			cam->corp.v = vec_add(cam->corp.v, (t_vec3d){0, 4 - env->cam.stats.pos.y + maps->cam_floor->a->corp.pos.y, 0, 0});
	//	else if (env->cam.stats.pos.y - maps->cam_floor->a->corp.pos.y < 3 && env->cam.stats.crouch == 0)
	//		cam->corp.v = vec_add(cam->corp.v, (t_vec3d){0, 5 - env->cam.stats.pos.y + maps->cam_floor->a->corp.pos.y , 0, 0});
		if (env->cam.stats.pos.y < -10)
			translate_mesh(maps, cam, vec_sub(maps->spawn, cam->corp.pos));

	}

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

