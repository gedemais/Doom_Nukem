#include "main.h"

static char	*objs_paths(unsigned int index)
{
	static char	*objs_paths[SCENE_MAX] = {"resources/objs/object.obj"};

	return (objs_paths[index]);
}

int			load_scenes(t_env *env)
{
	unsigned int	i;

	i = 0;
	while (i < SCENE_MAX)
	{
		if (!(env->scene = load_objects(objs_paths(i))))
			return (-1);
		i++;
	}
	return (0);
}

