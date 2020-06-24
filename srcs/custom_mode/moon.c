#include "main.h"

void			moon_rotate(t_mesh *mesh, t_vec3d mesh_pos, float angle,
		void (*rotation)(t_vec3d *v, t_vec3d m, float fcos, float fsin))
{
	int			i;
	float		fcos;
	float		fsin;
	t_triangle	*tri;

	fcos = cos(angle);
	fsin = sin(angle);
	i = -1;
	while (++i < mesh->tris.nb_cells)
	{
		tri = dyacc(&mesh->tris, i);
		rotation(&tri->points[0], mesh_pos, fcos, fsin);
		rotation(&tri->points[1], mesh_pos, fcos, fsin);
		rotation(&tri->points[2], mesh_pos, fcos, fsin);
	}
}

void			handle_moon(t_env *env)
{
	t_vec3d	map_center;
	t_map	*moon;

	map_center = (t_vec3d){ env->edit_env.new_map.width,
						env->edit_env.new_map.height,
						env->edit_env.new_map.depth, 0 };
	moon = &env->maps[SCENE_MOON];

	printf("map_center ");
	print_vec(map_center);

	printf("moon_pos ");
	print_vec(env->custom_env.moon_pos);

	//enemies_rotate_y
	//moon_rotate(moon, env->custom_env.moon_pos, 5, ro)
}
