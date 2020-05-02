#include "main.h"

int			map_to_scene(t_env *env)
{
	t_edit_env	*edit_env;
	t_map		*scene;

	edit_env = &env->edit_env;
	scene = &edit_env->map;
	if (init_dynarray(&scene->meshs, sizeof(t_mesh), 0))
		return (-1);
	return (0);
}
