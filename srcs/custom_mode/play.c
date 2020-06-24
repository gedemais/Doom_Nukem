#include "main.h"

static void	move(t_env *env, bool keys[NB_KEYS])
{
	t_map		*map;
	t_vec3d		f;
	t_vec3d		r;

	map = &env->edit_env.map;
	f = vec_fmult(env->cam.stats.dir, MAPED_WALK_SPEED);
	r = (t_vec3d){f.z, 0, -f.x, f.w};
	if (keys[KEY_W])
	{
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(f, WSPEED));
		translate_mesh(map, &map->cam, vec_fmult(f, WSPEED));
	}
	if (keys[KEY_S])
	{
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(f, WSPEED));
		translate_mesh(map, &map->cam, vec_fmult(f, -WSPEED));
	}
	if (keys[KEY_A])
	{
		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(r, WSPEED));
		translate_mesh(map, &map->cam, vec_fmult(r, WSPEED));
	}
	if (keys[KEY_D])
	{
		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(r, WSPEED));
		translate_mesh(map, &map->cam, vec_fmult(r, -WSPEED));
	}
}

static int		handle_keys(t_env *env, t_events *e)
{
	if ((e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D]))
		move(env, e->keys);
	return (0);
}

static void	print_doors(t_env *env)
{
	t_dynarray	*door;
	int			*pos;
	int			i;
	int			j;

	i = 0;
	while (i < env->custom_env.doors.nb_cells)
	{
		j = 0;
		door = dyacc(&env->custom_env.doors, i);
		printf("------- door n%d : %d blocks ------------\n", i, door->nb_cells);
		while (j < door->nb_cells)
		{
			pos = dyacc(door, j);
			printf("block n%d : %d %d %d | door n%d\n", j, pos[0], pos[1], pos[2], pos[3]);
			j++;
		}
		printf("-----------------------------------\n");
		i++;
	}
}

int			custom_play(t_env *env)
{
	print_doors(env);
	handle_player(env);
	clear_screen_buffers(env);
	handle_keys(env, &env->events);
	camera_aim(env);
	env->mid.mesh = NULL;
//	physic_engine(env);
	assert(!rasterizer(env, &env->edit_env.map, false));
	handle_enemies(env);
	handle_weapons(env);
	handle_block_events(env);
	handle_moon(env);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	env->events.buttons[BUTTON_SCROLL_UP] = false;
	env->events.buttons[BUTTON_SCROLL_DOWN] = false;
	return (0);
}
