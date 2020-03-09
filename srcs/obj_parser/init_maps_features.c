#include "main.h"

int		init_maps_features(t_env *env)
{
	t_mesh	*m;
	int		i;
	int		j;

	i = 0;
	while (i < SCENE_MAX)
	{
		j = 0;
		while (j < env->maps[i].meshs.nb_cells)
		{
			m = dyacc(&env->maps[i].meshs, j);
		}
		i++;
	}
	return (0);
}
