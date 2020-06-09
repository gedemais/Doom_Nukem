#include "main.h"

static	t_vec3d phy_handle_key(t_env *env, t_vec3d f, t_vec3d r, bool keys[NB_KEYS]) //remplacer f par m->corp.v
{
	(void)env;
	if (keys[KEY_W] || keys[KEY_E])
	{
		f = vec_add(f, vec_fmult(f, 3.0f));
		if (keys[KEY_E])
			f.y += 0.5;
		if (keys[KEY_E] && !keys[KEY_W])
			f = (t_vec3d){0, f.y, 0, f.w};
	}
	if (keys[KEY_S])
		f = vec_add(f, vec_fmult(f, -3.0f));
	if (keys[KEY_A])
		f = vec_add(f, vec_fmult(r, 3.0f));
	if (keys[KEY_D])
		f = vec_add(f, vec_fmult(r, -3.0f));
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
//	print_info_phy(env, &maps->cam);
	 if (env->cam.stats.onfloor == 1)
		f = set_y_dir(env, maps); // a virer dans engine ! 
	else
		f = vec_fmult(env->cam.stats.dir, MAPED_WALK_SPEED);
	r = vec_fdiv((t_vec3d){f.z, 0, -f.x, 0}, env->cam.stats.aspect_ratio);
	if ((keys[KEY_W] || keys[KEY_S] || keys[KEY_A] || keys[KEY_D]|| keys[KEY_E]))
	{
		f = phy_handle_key(env, f, r, keys);
		env->cam.stats.pos = vec_add(env->cam.stats.pos, f);
		cam->corp.v = f;
	}
}
