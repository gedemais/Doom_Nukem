#include "main.h"

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
		loading_bar(i, SCENE_MAX, false);
		if (parse_map(&env->maps[i], maps_paths(i), states) != 0)
			return (-1);
//		if (!(env->maps[i].stats = (bool*)malloc(env->maps[i].nmesh))
//			|| load_map_config(&env->maps[i], maps_paths(i)))
//			return (-1);
		//printf("%s (%d meshs)\n", maps_paths(i), env->maps[i].nmesh);
//		for (int j = 0; j < env->maps[i].nmesh; j++)
//		{
//			m = dyacc(&env->maps[i].meshs, j);
		//	printf("%s : %d triangles\n", m->name, m->tris.nb_cells);
//		}
		ft_putchar(i == SCENE_MAX - 1 ? '\0' : '\r');
		i++;
	}
	loading_bar(i, SCENE_MAX, true);
	return (0);
}
