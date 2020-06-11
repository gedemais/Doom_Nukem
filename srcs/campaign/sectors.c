#include "main.h"

void	init_sectors(t_env *env)
{
	t_camp_env	*cmp_env;

	cmp_env = &env->cmp_env;
	cmp_env->sectors[SECTOR_AXIS].map = SCENE_AXIS;
	cmp_env->sectors[SECTOR_CUBE].map = SCENE_CUBE;
	cmp_env->sectors[SECTOR_TEST].map = SCENE_MAP_TEST;
	cmp_env->sectors[SECTOR_SLENDER].map = SCENE_SLENDER;

	cmp_env->sectors[SECTOR_FAMAS].map = SCENE_FAMAS;
	cmp_env->sectors[SECTOR_AK47].map = SCENE_AK47;
	cmp_env->sectors[SECTOR_SAWED_OFF].map = SCENE_SAWED_OFF;
	cmp_env->sectors[SECTOR_GLOCK_18].map = SCENE_GLOCK_18;
	cmp_env->sectors[SECTOR_AUG].map = SCENE_AUG;
	cmp_env->sectors[SECTOR_UMP45].map = SCENE_UMP45;
	cmp_env->sectors[SECTOR_MAG7].map = SCENE_MAG7;
	cmp_env->sectors[SECTOR_GALIL].map = SCENE_GALIL;
	cmp_env->sectors[SECTOR_NEGEV].map = SCENE_NEGEV;
	cmp_env->sectors[SECTOR_TEC9].map = SCENE_TEC9;
	cmp_env->sectors[SECTOR_UGLY].map = SCENE_UGLY;
	//cmp_env->sectors[SECTOR_].map = SCENE_;
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
