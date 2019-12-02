#include "main.h"

static void	draw_triangle(t_mlx *mlx, t_point a, t_point b, t_point c)
{
	draw_line(mlx, a, b, 0xffffff);
	draw_line(mlx, a, c, 0xffffff);
	draw_line(mlx, b, c, 0xffffff);
}

void	rasterizer(t_env *env)
{
	(void)env;
	unsigned int		i;
	static float		theta = 0.0f;
	t_triangle			t;
//	t_triangle			translate;
//	t_triangle			rotate;

	i = 0;
	t_mesh	mesh;
// cube shit
	if (!(mesh.tris = (t_triangle*)malloc(sizeof(t_triangle) * 12)))
		return ;
	// south face
	mesh.tris[0].points[0] = (t_vec3d){0.0f, 0.0f, 0.0f};
	mesh.tris[0].points[1] = (t_vec3d){0.0f, 1.0f, 0.0f};
	mesh.tris[0].points[2] = (t_vec3d){1.0f, 1.0f, 0.0f};

	mesh.tris[1].points[0] = (t_vec3d){0.0f, 0.0f, 0.0f};
	mesh.tris[1].points[1] = (t_vec3d){1.0f, 1.0f, 0.0f};
	mesh.tris[1].points[2] = (t_vec3d){1.0f, 0.0f, 0.0f};
	// east face   
	mesh.tris[2].points[0] = (t_vec3d){1.0f, 0.0f, 0.0f};
	mesh.tris[2].points[1] = (t_vec3d){1.0f, 1.0f, 0.0f};
	mesh.tris[2].points[2] = (t_vec3d){1.0f, 1.0f, 1.0f};

	mesh.tris[3].points[0] = (t_vec3d){1.0f, 0.0f, 0.0f};
	mesh.tris[3].points[1] = (t_vec3d){1.0f, 1.0f, 1.0f};
	mesh.tris[3].points[2] = (t_vec3d){1.0f, 0.0f, 1.0f};
	// north face  
	mesh.tris[4].points[0] = (t_vec3d){1.0f, 0.0f, 1.0f};
	mesh.tris[4].points[1] = (t_vec3d){1.0f, 1.0f, 1.0f};
	mesh.tris[4].points[2] = (t_vec3d){0.0f, 1.0f, 1.0f};

	mesh.tris[5].points[0] = (t_vec3d){1.0f, 0.0f, 1.0f};
	mesh.tris[5].points[1] = (t_vec3d){0.0f, 1.0f, 1.0f};
	mesh.tris[5].points[2] = (t_vec3d){0.0f, 0.0f, 1.0f};
	// west        
	mesh.tris[6].points[0] = (t_vec3d){0.0f, 0.0f, 1.0f};
	mesh.tris[6].points[1] = (t_vec3d){0.0f, 1.0f, 1.0f};
	mesh.tris[6].points[2] = (t_vec3d){0.0f, 1.0f, 0.0f};

	mesh.tris[7].points[0] = (t_vec3d){0.0f, 0.0f, 1.0f};
	mesh.tris[7].points[1] = (t_vec3d){0.0f, 1.0f, 0.0f};
	mesh.tris[7].points[2] = (t_vec3d){0.0f, 0.0f, 0.0f};
	// top         
	mesh.tris[8].points[0] = (t_vec3d){0.0f, 1.0f, 0.0f};
	mesh.tris[8].points[1] = (t_vec3d){0.0f, 1.0f, 1.0f};
	mesh.tris[8].points[2] = (t_vec3d){1.0f, 1.0f, 1.0f};

	mesh.tris[9].points[0] = (t_vec3d){0.0f, 1.0f, 0.0f};
	mesh.tris[9].points[1] = (t_vec3d){1.0f, 1.0f, 1.0f};
	mesh.tris[9].points[2] = (t_vec3d){1.0f, 1.0f, 0.0f};
	//bottom      
	mesh.tris[10].points[0] = (t_vec3d){1.0f, 0.0f, 1.0f};
	mesh.tris[10].points[1] = (t_vec3d){0.0f, 0.0f, 1.0f};
	mesh.tris[10].points[2] = (t_vec3d){0.0f, 0.0f, 0.0f};

	mesh.tris[11].points[0] = (t_vec3d){1.0f, 0.0f, 1.0f};
	mesh.tris[11].points[1] = (t_vec3d){0.0f, 0.0f, 0.0f};
	mesh.tris[11].points[2] = (t_vec3d){1.0f, 0.0f, 0.0f};
// cube shit
	while (i < 12)
	{
		ft_memcpy(&t, &mesh.tris[i], sizeof(t_triangle));

		update_xrotation_matrix(&env->cam, theta);
		update_zrotation_matrix(&env->cam, theta);

		t.points[0] = multiply_matrix(env->cam.rz_m, t.points[0]);
		t.points[1] = multiply_matrix(env->cam.rz_m, t.points[1]);
		t.points[2] = multiply_matrix(env->cam.rz_m, t.points[2]);

		t.points[0] = multiply_matrix(env->cam.rx_m, t.points[0]);
		t.points[1] = multiply_matrix(env->cam.rx_m, t.points[1]);
		t.points[2] = multiply_matrix(env->cam.rx_m, t.points[2]);

		t.points[0] = vec_add(t.points[0], (t_vec3d){1.5f, 1.5f, 3.0f});
		t.points[1] = vec_add(t.points[1], (t_vec3d){1.5f, 1.5f, 3.0f});
		t.points[2] = vec_add(t.points[2], (t_vec3d){1.5f, 1.5f, 3.0f});

		t.points[0] = multiply_matrix(env->cam.p_m, t.points[0]);
		t.points[1] = multiply_matrix(env->cam.p_m, t.points[1]);
		t.points[2] = multiply_matrix(env->cam.p_m, t.points[2]);
		
		t.points[0].x += 5.0f;
		t.points[0].y += 4.0f;
		t.points[1].x += 5.0f;
		t.points[1].y += 4.0f;
		t.points[2].x += 5.0f;
		t.points[2].y += 4.0f;

		t.points[0].x *= 0.1f * (float)env->mlx.half_wdt;
		t.points[0].y *= 0.1f * (float)env->mlx.half_hgt;
		t.points[1].x *= 0.1f * (float)env->mlx.half_wdt;
		t.points[1].y *= 0.1f * (float)env->mlx.half_hgt;
		t.points[2].x *= 0.1f * (float)env->mlx.half_wdt;
		t.points[2].y *= 0.1f * (float)env->mlx.half_hgt;

		draw_triangle(&env->mlx, (t_point){(int)t.points[0].x, (int)t.points[0].y},
					(t_point){(int)t.points[1].x, (int)t.points[1].y},
					(t_point){(int)t.points[2].x, (int)t.points[2].y});
		i++;
	}
	theta += 0.1f;
}













