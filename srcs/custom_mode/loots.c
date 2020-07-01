#include "main.h"

int		spawn_loot(t_env *env, t_vec3d pos)
{
	t_dynarray	*loots;
	t_loot		loot;
	t_map		*map;

	map = &env->maps[SCENE_LOOT];
	loots = &env->custom_env.loots;
	if (rand() % LOOT_FREQ > 0)
		return (0);
	loot.id = rand() % LOOT_MAX;
	loot.pos = pos;
	if (!(loot.m = copy_to_scene(&env->edit_env.map, map, pos)))
		return (-1);
	if (loots->byte_size == 0 && init_dynarray(loots, sizeof(t_loot), 0))
		return (-1);
	if (push_dynarray(loots, &loot, false))
		return (-1);
	return (0);
}
