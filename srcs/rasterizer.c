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
	t_triangle			tri;
	t_triangle			rtri;
	static float		theta = 90.0f;

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
		printf("angle = %f\n", (double)theta);

		update_xrotation_matrix(&env->cam, (float)ft_to_radians((double)theta));

		rtri.points[0] = multiply_matrix(env->cam.rx_m, mesh.tris[i].points[0]);
		rtri.points[1] = multiply_matrix(env->cam.rx_m, mesh.tris[i].points[1]);
		rtri.points[2] = multiply_matrix(env->cam.rx_m, mesh.tris[i].points[2]);

		rtri.points[0].z += 2.0f;
		rtri.points[1].z += 2.0f;
		rtri.points[2].z += 2.0f;

		rtri.points[0].x += 2.0f;
		rtri.points[1].x += 2.0f;
		rtri.points[2].x += 2.0f;

		rtri.points[0].y += 2.0f;
		rtri.points[1].y += 2.0f;
		rtri.points[2].y += 2.0f;

		tri.points[0] = multiply_matrix(env->cam.p_m, rtri.points[0]);
		tri.points[1] = multiply_matrix(env->cam.p_m, rtri.points[1]);
		tri.points[2] = multiply_matrix(env->cam.p_m, rtri.points[2]);

		tri.points[0].x += 1.0f;
		tri.points[0].y += 1.0f;
		tri.points[1].x += 1.0f;
		tri.points[1].y += 1.0f;
		tri.points[2].x += 1.0f;
		tri.points[2].y += 1.0f;

		tri.points[0].x *= (float)WDT * 0.05f;
		tri.points[0].y *= (float)HGT * 0.05f;
		tri.points[1].x *= (float)WDT * 0.05f;
		tri.points[1].y *= (float)HGT * 0.05f;
		tri.points[2].x *= (float)WDT * 0.05f;
		tri.points[2].y *= (float)HGT * 0.05f;

		draw_triangle(&env->mlx, (t_point){(int)tri.points[0].x, (int)tri.points[0].y},
					(t_point){(int)tri.points[1].x, (int)tri.points[1].y},
					(t_point){(int)tri.points[2].x, (int)tri.points[2].y});
		i++;
	}
	theta += 0.5f;
}













