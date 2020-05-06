#include "main.h"

static void	set_renderable(t_cube_pallet p[BTXT_MAX])
{
	p[BTXT_BRICK - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_DARK_BRICK - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_CLEAN_STONE - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_DIRT - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_DIRT_GRASS - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_DIRT_SNOW - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_ICE - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_GOLD - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_IRON - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_LIBRARY - 1] = (t_cube_pallet){.cube = 1, .slope = 0, .obj = 0};
	p[BTXT_LIGHT - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_OBSIDIENNE - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_SAND - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_STONE - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_WOOD_A - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_WOOD_A_CUT - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_WOOD_B - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_WOOD_B_CUT - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_WOOD_C - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_WOOD_C_CUT - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_WOOD_D - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_WOOD_D_CUT - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
	p[BTXT_JUKEBOX - 1] = (t_cube_pallet){.cube = 0, .slope = 0, .obj = 1};
	//pallet[BTXT_ - 1] = (t_cube_pallet){.cube = , .slope = , .obj = };
}

static void	draw_pallet_bbox(t_env *env, int nb_icones, t_point *origin)
{
	t_point	o;
	t_point	dims;
	t_point	s_dims;
	int		offset;

	offset = nb_icones * 34;
	o = (t_point){env->data.half_wdt - (offset / 2), 600}; // bbox origin
	*origin = o;
	dims = (t_point){offset, 2};
	s_dims = (t_point){2, 34};

	draw_rectangle(env->mlx.img_data, o, dims, 0xffffff); // top
	draw_rectangle(env->mlx.img_data, o, s_dims, 0xffffff); // sides
	o.x += offset;
	draw_rectangle(env->mlx.img_data, o, s_dims, 0xffffff);
	o.x -= offset;
	dims.x += 2;
	o.y += s_dims.y;
	draw_rectangle(env->mlx.img_data, o, dims, 0xffffff); // bottom
}

int			render_pallet(t_env *env)
{
	t_point		o;

	if (env->edit_env.current_bc == BC_CUBE)
	{
		draw_pallet_bbox(env, NB_CUBES_ICONES, &o);
		render_cube_pallet(env, env->edit_env.pallet, o);
	}
	return (0);
}

int			init_cubes_pallet(t_env *env, t_edit_env *edit_env)
{
	static char		*paths[BTXT_MAX] = {"brick_ico.xpm", "dark_brick_ico.xpm",
					"clean_stone_ico.xpm", "dirt_ico.xpm", "dirt_grass_ico.xpm",
					"dirt_snow_ico.xpm", "glace_ico.xpm", "gold_ico.xpm",
					"iron_ico.xpm", "library_ico.xpm", "light_ico.xpm",
					"obsidienne_ico.xpm", "sand_ico.xpm", "stone_ico.xpm",
					"wood_a_ico.xpm", "wood_a_cut_ico.xpm",
					"wood_b_ico.xpm", "wood_b_cut_ico.xpm",
					"wood_c_ico.xpm", "wood_c_cut_ico.xpm",
					"wood_d_ico.xpm", "wood_d_cut_ico.xpm", "jukebox_ico.xpm"};
	char			path[256];
	unsigned int	i;

	i = 0;
	set_renderable(edit_env->pallet);
	while (i < BTXT_MAX - 1)
	{
		ft_bzero(path, 256);
		ft_strcpy(path, MAPED_ICONE_PATH);
		ft_strcat(path, paths[i]);
		if (load_texture(&env->mlx, path, &edit_env->pallet[i].sprite, false))
			return (-1);
		i++;
	}
	return (0);
}
