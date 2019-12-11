#include "main.h"
/*
static void	draw_triangle(t_mlx *mlx, t_point a, t_point b, t_point c)
{
	draw_line(mlx, a, b, 0);
	draw_line(mlx, a, c, 0);
	draw_line(mlx, b, c, 0);
}*/

void	rasterizer(t_env *env)
{
	unsigned int		i;
	static float		thetaz = 0.0f;
	t_triangle			t;
	t_vec3d				normale;
	t_vec3d				line1;
	t_vec3d				line2;
	t_vec3d				light;
	t_vec3d				up;
	t_vec3d				target;

	i = 0;

//	printf("cam : %f %f %f\n", env->cam.pos.x, env->cam.pos.y, env->cam.pos.z);
	env->cam.dir = (t_vec3d){0, 0, 1, 1};
	up = (t_vec3d){0, 1, 0, 1};
	target = vec_add(env->cam.pos, env->cam.dir);

	light = (t_vec3d){0.0f, 1.0f, -1.0f, 0.0f};
	vec_normalize(&light);

	update_xrotation_matrix(&env->cam, 90);
	update_zrotation_matrix(&env->cam, 0);

	matrix_point_at(env->cam.c_m, env->cam.pos, target, up);
	quick_inverse_matrix(env->cam.c_m, env->cam.v_m);

	matrix_m_matrix(env->cam.rx_m, env->cam.rz_m, env->cam.w_m);
	translate_matrix(env->cam.t_m, (t_vec3d){0.0f, 0.0f, 20.0f, 1.0f});
	matrix_m_matrix(env->cam.w_m, env->cam.t_m, env->cam.w_m);

	for (int j = 0; j < env->maps[0].nmesh; j++){
		i = 0;
	while ((int)i < ((t_mesh*)dyacc(&env->maps[0].meshs, j))->nb_tris)
	{
		ft_memcpy(&t, &(((t_mesh*)dyacc(&env->maps[0].meshs, j))->tris[i]), sizeof(t_triangle));

		t.points[0] = multiply_matrix(env->cam.w_m, t.points[0]);
		t.points[1] = multiply_matrix(env->cam.w_m, t.points[1]);
		t.points[2] = multiply_matrix(env->cam.w_m, t.points[2]);

		line1 = vec_sub(t.points[1], t.points[0]);
		line2 = vec_sub(t.points[2], t.points[0]);
		normale = vec_cross(line1, line2);
		vec_normalize(&normale);

		if (vec_dot(normale, vec_sub(t.points[0], env->cam.pos)) < 0.0f)
		{
//			t.points[0] = multiply_matrix(env->cam.v_m, t.points[0]);
//			t.points[1] = multiply_matrix(env->cam.v_m, t.points[1]);
//			t.points[2] = multiply_matrix(env->cam.v_m, t.points[2]);

			t.points[0] = multiply_matrix(env->cam.p_m, t.points[0]);
			t.points[1] = multiply_matrix(env->cam.p_m, t.points[1]);
			t.points[2] = multiply_matrix(env->cam.p_m, t.points[2]);

			vec_normalize(&t.points[0]);
			vec_normalize(&t.points[1]);
			vec_normalize(&t.points[2]);
			
			t.points[0] = vec_add(t.points[0], (t_vec3d){1.0f, 1.0f, 0.0f, 0.0f});
			t.points[1] = vec_add(t.points[1], (t_vec3d){1.0f, 1.0f, 0.0f, 0.0f});
			t.points[2] = vec_add(t.points[2], (t_vec3d){1.0f, 1.0f, 0.0f, 0.0f});

			t.points[0] = vec_mult(t.points[0], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f, 1.0f});
			t.points[1] = vec_mult(t.points[1], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f, 1.0f});
			t.points[2] = vec_mult(t.points[2], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f, 1.0f});

			fill_triangle_unit(env, t, shade_color(0x00ff00, vec_dot(normale, light)));
//			draw_triangle(&env->mlx, (t_point){(int)t.points[0].x, (int)t.points[0].y},
//						(t_point){(int)t.points[1].x, (int)t.points[1].y},
//						(t_point){(int)t.points[2].x, (int)t.points[2].y});
		}
		i++;
	}
	}
//	printf("%f\n", theta);
	thetaz += 0.012f;
}

