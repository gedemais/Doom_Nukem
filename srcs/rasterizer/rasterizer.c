#include "main.h"
/*
static void	draw_triangle(t_mlx *mlx, t_point a, t_point b, t_point c)
{
	draw_line(mlx, a, b, 0x000000);
	draw_line(mlx, a, c, 0x000000);
	draw_line(mlx, b, c, 0x000000);
}*/

void	project_triangle(t_env *env, t_triangle t, t_vec3d normal, t_dynarray *tris)
{
	t_triangle	clipped[2];
	int			nclip;

	// Illumination computing
	env->cam.light = (t_vec3d){0.0f, 0.0f, -1.0f, 0.0f};
	vec_normalize(&env->cam.light);
	t.illum = vec_dot(normal, env->cam.light);

	// View matrix
	t.points[0] = multiply_matrix(env->cam.v_m, t.points[0]);
	t.points[1] = multiply_matrix(env->cam.v_m, t.points[1]);
	t.points[2] = multiply_matrix(env->cam.v_m, t.points[2]);

	nclip = clip_triangle((t_vec3d){0.0f, 0.0f, 0.1f, 1.0f}, (t_vec3d){0.0f, 0.0f, 1.0f, 1.0f}, t, clipped);

	for (int i = 0; i < nclip; i++){
		// Projection
		t.points[0] = multiply_matrix(env->cam.p_m, clipped[i].points[0]);
		t.points[1] = multiply_matrix(env->cam.p_m, clipped[i].points[1]);
		t.points[2] = multiply_matrix(env->cam.p_m, clipped[i].points[2]);

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
	}
}

void	print_matrix(float m[4][4])
{
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++)
			printf("%f ", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

void	triangle_pipeline(t_env *env, t_triangle t, t_dynarray *tris)
{
	t_vec3d		normal;
	t_vec3d		line1;
	t_vec3d		line2;

	//Rotation
	t.points[0] = matrix_mult_vec(env->cam.w_m, t.points[0]);
	t.points[1] = matrix_mult_vec(env->cam.w_m, t.points[1]);
	t.points[2] = matrix_mult_vec(env->cam.w_m, t.points[2]);

	// Translation
	t.points[0] = vec_add(t.points[0], (t_vec3d){5.0f, 3.0f, 5.0f, 0.0f});
	t.points[1] = vec_add(t.points[1], (t_vec3d){5.0f, 3.0f, 5.0f, 0.0f});
	t.points[2] = vec_add(t.points[2], (t_vec3d){5.0f, 3.0f, 5.0f, 0.0f});

	line1 = vec_sub(t.points[1], t.points[0]);
	line2 = vec_sub(t.points[2], t.points[0]);
	normal = vec_cross(line1, line2);
	vec_normalize(&normal);

	if (vec_dot(normal, vec_sub(t.points[0], env->cam.pos)) < 0.0f)
		project_triangle(env, t, normal, tris);
}

void	compute_matrices(t_env *env)
{
	t_vec3d	up;
	t_vec3d	target;
	static float		theta = 0.0f;


	update_xrotation_matrix(env->cam.rx_m, 0);
	update_yrotation_matrix(env->cam.ry_m, 0);
	update_zrotation_matrix(env->cam.rz_m, 0);

	matrix_mult_matrix(env->cam.rz_m, env->cam.rx_m, env->cam.w_m);

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

static void	raster_triangles(t_env *env, t_dynarray *arr)
{
	t_dynarray	to_raster;
	t_triangle	*t;
	int			i;

	i = 0;
	if (init_dynarray(&to_raster, sizeof(t_triangle), arr->nb_cells))// a n init qu une fois
		return ;
	printf("%d before clipping\n", arr->nb_cells);
	clip_mesh_triangles(arr, &to_raster);
	printf("%d triangles to raster\n", to_raster.nb_cells);
	while (i < to_raster.nb_cells)
	{
		t = (t_triangle*)dyacc(&to_raster, i);
		fill_triangle_unit(env, *t, shade_color(t->color, t->illum));
//		draw_triangle(&env->mlx, (t_point){t->points[0].x, t->points[0].y},
//			(t_point){t->points[1].x, t->points[1].y},
//			(t_point){t->points[2].x, t->points[2].y});
		i++;
	}
	free_dynarray(&to_raster);//__
}

void		rasterizer(t_env *env, int scene)
{
	int			i;
	int			j;
	t_mesh		*m;
	t_triangle	t;
	t_dynarray	to_raster;

	i = 0;
	compute_matrices(env);
	if (init_dynarray(&to_raster, sizeof(t_triangle), 4096))
		return ;
	while (i < env->maps[scene].nmesh)
	{
		j = 0;
		if (!(m = dyacc(&env->maps[scene].meshs, i)))
			return ;
		while (j < m->faces.nb_cells)
		{
			ft_memcpy(&t, dyacc(&m->tris, j), sizeof(t_triangle));
			triangle_pipeline(env, t, &to_raster);
			j++;
		}
		i++;
	}
	raster_triangles(env, &to_raster);
	free_dynarray(&to_raster);
}
