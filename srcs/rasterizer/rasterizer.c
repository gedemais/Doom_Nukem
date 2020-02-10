#include "main.h"

void	project_triangle(t_env *env, t_triangle t, t_vec3d normal, t_dynarray *tris)
{
	t_triangle	clipped[2];
	int			nclip;
	int			i;

	i = 0;
	t.illum = vec_dot(normal, env->cam.light);

	// View matrix
	t.points[0] = multiply_matrix(env->cam.v_m, t.points[0]);
	t.points[1] = multiply_matrix(env->cam.v_m, t.points[1]);
	t.points[2] = multiply_matrix(env->cam.v_m, t.points[2]);

	nclip = clip_triangle((t_vec3d){0.0f, 0.0f, 0.1f, 1.0f}, (t_vec3d){0.0f, 0.0f, 1.0f, 1.0f}, t, clipped);

	while (i < nclip)
	{
		// Projection
		t.points[0] = multiply_matrix(env->cam.p_m, clipped[i].points[0]);
		t.points[1] = multiply_matrix(env->cam.p_m, clipped[i].points[1]);
		t.points[2] = multiply_matrix(env->cam.p_m, clipped[i].points[2]);

		t.txt[0].u = clipped[i].txt[0].u / clipped[i].points[0].w;
		t.txt[1].u = clipped[i].txt[1].u / clipped[i].points[1].w;
		t.txt[2].u = clipped[i].txt[2].u / clipped[i].points[2].w;

		t.txt[0].v = clipped[i].txt[0].v / clipped[i].points[0].w;
		t.txt[1].v = clipped[i].txt[1].v / clipped[i].points[1].w;
		t.txt[2].v = clipped[i].txt[2].v / clipped[i].points[2].w;

		t.txt[0].w = 1.0f / clipped[i].points[0].w;
		t.txt[1].w = 1.0f / clipped[i].points[1].w;
		t.txt[2].w = 1.0f / clipped[i].points[2].w;

		// Scaling with screen
		t.points[0] = vec_add(t.points[0], (t_vec3d){1.0f, 1.0f, 0.0f, 0.0f});
		t.points[1] = vec_add(t.points[1], (t_vec3d){1.0f, 1.0f, 0.0f, 0.0f});
		t.points[2] = vec_add(t.points[2], (t_vec3d){1.0f, 1.0f, 0.0f, 0.0f});
		t.points[0] = vec_mult(t.points[0], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f, 1.0f});
		t.points[1] = vec_mult(t.points[1], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f, 1.0f});
		t.points[2] = vec_mult(t.points[2], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f, 1.0f});

		t.color = 0xffffff;
		if (push_dynarray(tris, &t, false))
			return ;
		i++;
	}
}

void	triangle_pipeline(t_env *env, t_triangle t, t_dynarray *tris)
{
	t_vec3d		normal;
	t_vec3d		line1;
	t_vec3d		line2;

	// Translation
	t.points[0] = vec_add(t.points[0], (t_vec3d){5.0f, 3.0f, 5.0f, 0.0f});
	t.points[1] = vec_add(t.points[1], (t_vec3d){5.0f, 3.0f, 5.0f, 0.0f});
	t.points[2] = vec_add(t.points[2], (t_vec3d){5.0f, 3.0f, 5.0f, 0.0f});

	//Rotation
	t.points[0] = matrix_mult_vec(env->cam.w_m, t.points[0]);
	t.points[1] = matrix_mult_vec(env->cam.w_m, t.points[1]);
	t.points[2] = matrix_mult_vec(env->cam.w_m, t.points[2]);

	line1 = vec_sub(t.points[1], t.points[0]);
	line2 = vec_sub(t.points[2], t.points[0]);
	normal = vec_cross(line1, line2);
	vec_normalize(&normal);

	if (vec_dot(normal, vec_sub(t.points[0], env->cam.pos)) < 0.0f)
		project_triangle(env, t, normal, tris);
}

void	compute_rotation_matrices(t_env *env, t_mesh m)
{
	update_xrotation_matrix(env->cam.rx_m, m.pitch);
	update_yrotation_matrix(env->cam.ry_m, m.yaw);
	update_zrotation_matrix(env->cam.rz_m, m.roll);
	matrix_mult_matrix(env->cam.rz_m, env->cam.rx_m, env->cam.w_m);
}

void	compute_matrices(t_env *env)
{
	t_vec3d	up;
	t_vec3d	target;
	static float		theta = 0.0f;

	env->cam.dir = (t_vec3d){0, 0, 1, 0};
	up = (t_vec3d){0, -1, 0, 0};
	target = (t_vec3d){0, 0, 1, 0};

	update_yrotation_matrix(env->cam.cry_m, ft_to_radians(env->cam.yaw));
	update_xrotation_matrix(env->cam.crx_m, ft_to_radians(env->cam.pitch));
	matrix_mult_matrix(env->cam.crx_m, env->cam.cry_m, env->cam.cr_m);

	env->cam.dir = matrix_mult_vec(env->cam.cr_m, target);
	up = matrix_mult_vec(env->cam.cr_m, (t_vec3d){0, -1, 0, 0});
	target = vec_add(env->cam.pos, env->cam.dir);

	matrix_pointat(env->cam.c_m, env->cam.pos, target, up);

	inverse_matrix(env->cam.c_m, env->cam.v_m);
	theta -= 0.01f;
}

void		*rasthreader(void *param)
{
	t_rasthread	*thr;
	t_triangle	*t;
	t_env		*env;

	thr = (t_rasthread*)param;
	env = thr->env;
	while (thr->index < thr->end)
	{
		t = (t_triangle*)dyacc(&env->cam.to_raster, thr->index);
		fill_triangle_texture((t_env*)thr->env, *t);
//		printf("There2 (%f %f <-> %f %f <-> %f %f)\n", t->points[0].x, t->points[0].y, t->points[1].x, t->points[1].y, t->points[2].x, t->points[2].y);
		//assert(t->points[0].x > 0.0f && t->points[0].y  > 0.0f&& t->points[1].x > 0.0f && t->points[1].y > 0.0f && t->points[2].x > 0.0f && t->points[2].y > 0.0f);
//		fill_triangle_unit((t_env*)thr->env, *t, shade_color(t->color, t->illum));
		draw_triangle(&env->mlx,
			(t_point){t->points[0].x, t->points[0].y},
			(t_point){t->points[1].x, t->points[1].y},
			(t_point){t->points[2].x, t->points[2].y});
		thr->index++;
	}
	thr->done = true;
	if (thr->mono)
		return (NULL);
	else
		pthread_exit(NULL);
}

void	monothread_raster(void *e)
{
	t_rasthread		thread;
	t_env			*env;

	env = e;
	thread.env = env;
	thread.tris = &env->cam.to_raster;
	thread.start = 0;
	thread.index = 0;
	thread.end = env->cam.to_raster.nb_cells;
	thread.done = false;
	thread.mono = true;
	rasthreader(&thread);
}

void	rasterizer(t_env *env, int scene)
{
	int			i;
	int			j;
	t_mesh		*m;
	t_triangle	t;

	i = 0;
	compute_matrices(env);
	while (i < env->maps[scene].nmesh)
	{
		j = 0;
		if (!(m = dyacc(&env->maps[scene].meshs, i)))
			return ;
		compute_rotation_matrices(env, *m);
		while (j < m->faces.nb_cells)
		{
			t = *(t_triangle*)(dyacc(&m->tris, j));
			triangle_pipeline(env, t, &env->cam.to_clip);
			j++;
		}
		i++;
	}
	if (raster_triangles(env, &env->cam.to_clip))
		return ;
	clear_dynarray(&env->cam.to_clip);
}
