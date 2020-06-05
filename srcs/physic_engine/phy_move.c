#include "main.h"

void	phy_move(t_env *env, bool keys[NB_KEYS]) //2
{
	t_mesh		*cam;
	t_vec3d		f;
	t_vec3d		r;
	int			i;

	i = 0;
	cam = &env->maps[env->scene].cam;
	f = set_y_dir(env, keys);
	r = vec_fdiv((t_vec3d){f.z, 0, -f.x, 0}, env->cam.stats.aspect_ratio);
	if (keys[KEY_W] || keys[KEY_E])
	{
		f = vec_add(f, vec_fmult(f, 3.0f));
		if (keys[KEY_E] && !keys[KEY_W])
			f = (t_vec3d){0 , f.y, 0, f.w};
	}
	if (keys[KEY_S])
		f = vec_add(f, vec_fmult(f, -3.0f));
	if (keys[KEY_A])
		f = vec_add(f, vec_fmult(r, 3.0f));
	if (keys[KEY_D])
		f = vec_add(f, vec_fmult(r, -3.0f));
	if (env->cam.stats.onwall == 1)
		f =	test_dist_wall(env, &env->maps[env->scene].cam_wall, f);
	env->cam.stats.pos = vec_add(env->cam.stats.pos, f);
	cam->corp.o = vec_sub(env->cam.stats.pos, vec_fdiv(cam->corp.dims, 2.0f));
	cam->corp.v = f;
}
