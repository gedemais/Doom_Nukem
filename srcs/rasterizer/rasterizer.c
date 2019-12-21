#include "main.h"
/*
static void	draw_triangle(t_mlx *mlx, t_point a, t_point b, t_point c)
{
	draw_line(mlx, a, b, 0);
	draw_line(mlx, a, c, 0);
	draw_line(mlx, b, c, 0);
}*/

void	project_triangle(t_env *env, t_triangle t, t_vec3d normal)
{
	float	illum;

	// Illumination computing
	env->cam.light = (t_vec3d){0.0f, 0.0f, -1.0f, 0.0f};
	vec_normalize(&env->cam.light);
	illum = vec_dot(normal, env->cam.light);

	// Projection
	t.points[0] = multiply_matrix(env->cam.v_m, t.points[0]);
	t.points[1] = multiply_matrix(env->cam.v_m, t.points[1]);
	t.points[2] = multiply_matrix(env->cam.v_m, t.points[2]);

	t.points[0] = multiply_matrix(env->cam.p_m, t.points[0]);
	t.points[1] = multiply_matrix(env->cam.p_m, t.points[1]);
	t.points[2] = multiply_matrix(env->cam.p_m, t.points[2]);

	// Scaling with screen
	t.points[0] = vec_add(t.points[0], (t_vec3d){1.0f, 1.0f, 0.0f, 0.0f});
	t.points[1] = vec_add(t.points[1], (t_vec3d){1.0f, 1.0f, 0.0f, 0.0f});
	t.points[2] = vec_add(t.points[2], (t_vec3d){1.0f, 1.0f, 0.0f, 0.0f});
	t.points[0] = vec_mult(t.points[0], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f, 1.0f});
	t.points[1] = vec_mult(t.points[1], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f, 1.0f});
	t.points[2] = vec_mult(t.points[2], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f, 1.0f});

	// Drawing triangles
	fill_triangle_unit(env, t, shade_color(0xff0000, illum));
//	draw_triangle(&env->mlx, (t_point){t.points[0].x, t.points[0].y},
//		(t_point){t.points[1].x, t.points[1].y},
//		(t_point){t.points[2].x, t.points[2].y});
}

void	triangle_pipeline(t_env *env, t_triangle t)
{
	t_vec3d		normal;
	t_vec3d		line1;
	t_vec3d		line2;

	//Rotation
	t.points[0] = matrix_mult_vec(env->cam.w_m, t.points[0]);
	t.points[1] = matrix_mult_vec(env->cam.w_m, t.points[1]);
	t.points[2] = matrix_mult_vec(env->cam.w_m, t.points[2]);

	// Translation
	t.points[0] = vec_add(t.points[0], (t_vec3d){0.0f, 0.0f, 25.0f, 0.0f});
	t.points[1] = vec_add(t.points[1], (t_vec3d){0.0f, 0.0f, 25.0f, 0.0f});
	t.points[2] = vec_add(t.points[2], (t_vec3d){0.0f, 0.0f, 25.0f, 0.0f});

	line1 = vec_sub(t.points[1], t.points[0]);
	line2 = vec_sub(t.points[2], t.points[0]);
	normal = vec_cross(line1, line2);
	vec_normalize(&normal);

	if (vec_dot(normal, vec_sub(t.points[0], env->cam.pos)) < 0.0f)
		project_triangle(env, t, normal);
}

void	compute_matrices(t_env *env)
{
	t_vec3d	up;
	t_vec3d	target;
	static float		theta = 0.0f;


	env->cam.dir = (t_vec3d){0, 0, 1, 1};
	update_xrotation_matrix(env->cam.rx_m, theta);
	update_zrotation_matrix(env->cam.rz_m, theta * 1.5f);
	matrix_mult_matrix(env->cam.rz_m, env->cam.rx_m, env->cam.w_m);

	up = (t_vec3d){0, -1, 0, 1};
	target = (t_vec3d){0, 0, 1, 1};
	update_yrotation_matrix(env->cam.cry_m, env->cam.yaw);
	update_xrotation_matrix(env->cam.crx_m, env->cam.pitch);
	matrix_mult_matrix(env->cam.cry_m, env->cam.crx_m, env->cam.cr_m);
	env->cam.dir = matrix_mult_vec(env->cam.cr_m, target);
	target = vec_add(env->cam.pos, env->cam.dir);

	matrix_pointat(env->cam.c_m, env->cam.pos, target, up);

	inverse_matrix(env->cam.c_m, env->cam.v_m);
//	translation_matrix(env->cam.t_m, (t_vec3d){0.0f, 0.0f, 25.0f, 0.0f});
//	matrix_mult_matrix(env->cam.w_m, env->cam.v_m, env->cam.w_m);
	theta -= 0.01f;
}

void	rasterizer(t_env *env, int scene)
{
	int			i;
	int			j;
	t_mesh		*m;
	t_triangle	t;

	j = 0;
	compute_matrices(env);
	while (j < env->maps[scene].nmesh)
	{
		i = 0;
		if (!(m = dyacc(&env->maps[scene].meshs, j)))
			return ;
		while (i < m->faces.nb_cells)
		{
			ft_memcpy(&t, dyacc(&m->tris, i), sizeof(t_triangle));
			triangle_pipeline(env, t);
			i++;
		}
		j++;
	}
}
