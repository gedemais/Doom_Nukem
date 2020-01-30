#include "main.h"

static char	*maps_paths(unsigned int index)
{
	char	*paths[SCENE_MAX] = {	"resources/maps/cluster.obj"};

	return (paths[index]);
}

int			load_maps(t_env *env)
{
	char			states[PS_MAX][PS_MAX];
	unsigned int	i;
//		t_mesh	*m;

	i = 0;
	ft_putendl("Loading maps...");
	init_states(states);
	while (i < SCENE_MAX)
	{
		if (parse_map(&env->maps[i], maps_paths(i), states) != 0)
			return (-1);
//		printf("%s (%d meshs)\n", maps_paths(i), env->maps[i].nmesh);
/*		for (int j = 0; j < env->maps[i].nmesh; j++)
		{
			m = dyacc(&env->maps[i].meshs, j);
			printf("%s : %d triangles\n", m->name, m->nb_tris);
		}*/
		i++;
	}
	return (0);
}
