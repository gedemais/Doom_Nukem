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
	(void)env;
	unsigned int		i;
	static float		thetaz = 0.0f;
	t_triangle			t;

	i = 0;
	t_vec3d	normale;
	t_vec3d	line1;
	t_vec3d	line2;
	t_vec3d	light;

	light = (t_vec3d){0.0f, 1.0f, -1.0f};
	vec_normalize(&light);
	while (i < (unsigned)env->scene[0].nb_tris)
	{
		ft_memcpy(&t, &env->scene[0].tris[i], sizeof(t_triangle));

		update_xrotation_matrix(&env->cam, thetaz * 1.25f);
		update_zrotation_matrix(&env->cam, thetaz);

		t.points[0] = multiply_matrix(env->cam.rx_m, t.points[0]);
		t.points[1] = multiply_matrix(env->cam.rx_m, t.points[1]);
		t.points[2] = multiply_matrix(env->cam.rx_m, t.points[2]);

		t.points[0] = multiply_matrix(env->cam.rz_m, t.points[0]);
		t.points[1] = multiply_matrix(env->cam.rz_m, t.points[1]);
		t.points[2] = multiply_matrix(env->cam.rz_m, t.points[2]);

		t.points[0] = vec_add(t.points[0], (t_vec3d){0.0f, 0.0f, 6.0f});
		t.points[1] = vec_add(t.points[1], (t_vec3d){0.0f, 0.0f, 6.0f});
		t.points[2] = vec_add(t.points[2], (t_vec3d){0.0f, 0.0f, 6.0f});

		line1 = vec_sub(t.points[1], t.points[0]);
		line2 = vec_sub(t.points[2], t.points[0]);
		normale = vec_cross(line1, line2);
		vec_normalize(&normale);

		if (vec_dot(normale, vec_sub(t.points[0], env->cam.pos)) < 0.0f)
		{
			t.points[0] = multiply_matrix(env->cam.p_m, t.points[0]);
			t.points[1] = multiply_matrix(env->cam.p_m, t.points[1]);
			t.points[2] = multiply_matrix(env->cam.p_m, t.points[2]);
			
			t.points[0] = vec_add(t.points[0], (t_vec3d){1.0f, 1.0f, 0.0f});
			t.points[1] = vec_add(t.points[1], (t_vec3d){1.0f, 1.0f, 0.0f});
			t.points[2] = vec_add(t.points[2], (t_vec3d){1.0f, 1.0f, 0.0f});

			t.points[0] = vec_mult(t.points[0], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f});
			t.points[1] = vec_mult(t.points[1], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f});
			t.points[2] = vec_mult(t.points[2], (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f});

			fill_triangle_unit(env, t, shade_color(0xffffff, vec_dot(normale, light)));
//			draw_triangle(&env->mlx, (t_point){(int)t.points[0].x, (int)t.points[0].y},
//						(t_point){(int)t.points[1].x, (int)t.points[1].y},
//						(t_point){(int)t.points[2].x, (int)t.points[2].y});
		}
		i++;
	}
//	printf("%f\n", theta);
	thetaz += 0.012f;
}













