#include "main.h"

static void	set_renderable(t_cube_pallet *p)
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
	p[BTXT_LIBRARY - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
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

static void	draw_pallet_box(t_env *env, t_cube_pallet pallet[BTXT_MAX])
{
	unsigned int	i;
	unsigned int	nb;
	t_point			o;
	t_point			dims;

	i = 0;
	nb = 0;
	while (i < BTXT_MAX) //  a simplifier, le nombre de cubes sera connu avant le rendu
	{
		if (env->edit_env.current_bc == BC_CUBE && pallet[i].cube)
			nb++;
		if (env->edit_env.current_bc == BC_SLOPE && pallet[i].slope)
			nb++;
		if (env->edit_env.current_bc == BC_OBJ && pallet[i].obj)
			nb++;
		i++;
	}
	o = (t_point){env->data.half_wdt - (nb / 2 * 36), 600};
	dims = (t_point){(nb / 2 * 36) * 2, 2};
	draw_rectangle(env->mlx.img_data, o, dims, 0xffffff);
	draw_rectangle(env->mlx.img_data, o, (t_point){2, 34}, 0xffffff);
	draw_rectangle(env->mlx.img_data, (t_point){o.x + dims.x, o.y},
		(t_point){2, 36}, 0xffffff);
	o.y += 34;
	draw_rectangle(env->mlx.img_data, o, dims, 0xffffff);
}

int			render_pallet(t_env *env)
{
	unsigned int	i;

	i = 0;
	draw_pallet_box(env, env->edit_env.pallet);
	while (i < BTXT_MAX - 1)
	{
		printf("mapping %d x %d\n", env->edit_env.pallet[i].sprite.wdt, env->edit_env.pallet[i].sprite.hgt);
		map_sprite(env->mlx.img_data, env->edit_env.pallet[i].sprite, (t_point){400, 400});
		i++;
	}
	return (0);
}

int			init_cubes_pallet(t_env *env, t_edit_env *edit_env)
{
	t_vec2d			crop_size[2];
	unsigned int	i;

	i = 0;
	crop_size[0] = (t_vec2d){0.25f, 0.25f, 0};
	crop_size[1] = (t_vec2d){0.5f, 0.5f, 0};
	set_renderable(edit_env->pallet);
	while (i < BTXT_MAX - 1)
	{
		if (crop_sprite(env, edit_env->btxts[i + 1],
			&edit_env->pallet[i].sprite, crop_size))
			return (-1);
		i++;
	}
	return (0);
}
