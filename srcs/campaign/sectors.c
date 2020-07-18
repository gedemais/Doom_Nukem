#include "main.h"

void	init_sectors(t_env *env)
{
	t_camp_env	*cmp_env;

	cmp_env = &env->cmp_env;
	cmp_env->sectors[SECTOR_AXIS].map = SCENE_AXIS;
	cmp_env->sectors[SECTOR_HOUSE].map = SCENE_HOUSE;
	cmp_env->sectors[SECTOR_START_ROOM].map = SCENE_START_ROOM;
	//cmp_env->sectors[SECTOR_].map = SCENE_;
}

void	check_doors(t_env *env, t_camp_env *cmp_env)
{
	unsigned int	i;
	float			dist;
	t_vec3d			door_pos;

	i = 0;
	(void)env;
	while (i < SECTOR_MAX)
	{
		dist = cmp_env->sectors[cmp_env->sector].doors[i].max_dist;
		door_pos = cmp_env->sectors[cmp_env->sector].doors[i].pos;
//		if (vec_sdist(env->cam.stats.pos,  door_pos) < dist)
//			textual_hint(env, 'E', "open the door");
		i++;
	}
}
