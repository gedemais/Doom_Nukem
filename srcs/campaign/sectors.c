#include "main.h"

void	init_sectors(t_env *env)
{
	t_camp_env	*cmp_env;

	cmp_env = &env->cmp_env;
	cmp_env->sectors[SECTOR_SA].map = SCENE_SA;
	cmp_env->sectors[SECTOR_SB].map = SCENE_SB;
	cmp_env->sectors[SECTOR_SC].map = SCENE_SC;
	cmp_env->sectors[SECTOR_E1].map = SCENE_E1;
	cmp_env->sectors[SECTOR_AK47].map = SCENE_AK47;
}

void	check_doors(t_env *env, t_camp_env *cmp_env)
{
	unsigned int	i;
	float			dist;
	t_vec3d			door_pos;

	i = 0;
	while (i < SECTOR_MAX)
	{
		dist = cmp_env->sectors[cmp_env->sector].doors[i].max_dist;
		door_pos = cmp_env->sectors[cmp_env->sector].doors[i].pos;
		if (vec_sdist(env->cam.stats.pos,  door_pos) < dist)
			textual_hint(env, 'E', "open the door");
		i++;
	}
}
