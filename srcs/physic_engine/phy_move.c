#include "main.h"

static	t_vec3d phy_handle_key(t_env *env, t_vec3d f, t_vec3d r, bool keys[NB_KEYS]) //remplacer f par m->corp.v
{
	(void)env;

	if (keys[KEY_W])
		f = vec_add(f, vec_fmult(f, 3.0f));
	if (keys[KEY_S])
		f = vec_add(f, vec_fmult(f, -4.0f));
	if (keys[KEY_A])
		f = vec_add(f, vec_fmult(r, 3.0f));
	if (keys[KEY_D])
		f = vec_add(f, vec_fmult(r, -3.0f));
	if (!keys[KEY_W] && !keys[KEY_S] && !keys[KEY_D] && !keys[KEY_A])
		f = zero_vector();
	return (f);
}

void	phy_move(t_env *env, bool keys[NB_KEYS], t_map *maps) //2
{
	t_mesh		*cam;
	t_vec3d		f;
	t_vec3d		r;
	int			i;

	i = 0;
	cam = &env->edit_env.map.cam;
	env->cam.stats.speed = (keys[KEY_SHIFT_LEFT]) ? 2 : 1;
	if (env->cam.stats.onfloor == 1 || env->cam.stats.onwall == 1)
		f = set_y_dir(env, maps); // a virer dans engine ! 
	r = vec_fdiv((t_vec3d){f.z, 0, -f.x, 0}, env->cam.stats.aspect_ratio);
	if ((keys[KEY_W] || keys[KEY_S] || keys[KEY_A] || keys[KEY_D]|| keys[KEY_E]) && env->cam.stats.onfloor == 1)
	{
		f = phy_handle_key(env, f, r, keys);
		if (keys[KEY_E] && env->cam.stats.onroof == 0)
			f.y += 0.3;
		if (env->cam.stats.onwall == 1)
			f = test_dist_wall(env, maps->cam_wall, f);
		env->cam.stats.pos = vec_add(env->cam.stats.pos, f);
		cam->corp.v = f;
	}
	if (keys[KEY_O])
	{
		env->phy_env.type_move = false;
		translate_mesh(maps, cam, vec_sub(vec_add(zero_vector(), cam->corp.dims), cam->corp.o));
	}
}
