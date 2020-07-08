#include "main.h"

int		dup_names(t_env *env)
{
	const char	*names[W_MAX] = {"FAMAS", "AK-47", "Sawed-Off", "Glock-18",
									"AUG", "UMP45", "mag-7", "Galil",
									"Negev", "TEC-9"};
	unsigned int	i;

	i = 0;
	while (i < W_MAX)
	{
		if (!(env->weapons[i].name = ft_strdup((char*)names[i])))
			return (-1);
		env->weapons[i].index = (int)i;
		i++;
	}
	return (0);
}

// Assigne tous les premiers meshs des objs d'armes aux t_weapon
static void		assign_wmeshs(t_env *env)
{
	env->weapons[W_FAMAS].mesh = (t_mesh*)env->maps[SCENE_FAMAS].meshs.c;
	env->weapons[W_FAMAS].breech = dyacc(&env->maps[SCENE_FAMAS].meshs, 2);
	env->weapons[W_FAMAS].w_map = &env->maps[SCENE_FAMAS];
//	printf("%s\n", env->weapons[W_FAMAS].mesh->name);
	env->weapons[W_AK47].mesh = (t_mesh*)env->maps[SCENE_AK47].meshs.c;
	env->weapons[W_AK47].breech = dyacc(&env->maps[SCENE_AK47].meshs, 1);
	env->weapons[W_AK47].w_map = &env->maps[SCENE_AK47];
//	printf("%s\n", env->weapons[W_AK47].mesh->name);
	env->weapons[W_SAWED_OFF].mesh = (t_mesh*)env->maps[SCENE_SAWED_OFF].meshs.c;
	env->weapons[W_SAWED_OFF].breech = dyacc(&env->maps[SCENE_SAWED_OFF].meshs, 1);
	env->weapons[W_SAWED_OFF].w_map = &env->maps[SCENE_SAWED_OFF];
//	printf("%s\n", env->weapons[W_SAWED_OFF].mesh->name);
	env->weapons[W_GLOCK_18].mesh = (t_mesh*)env->maps[SCENE_GLOCK_18].meshs.c;
	env->weapons[W_GLOCK_18].breech = dyacc(&env->maps[SCENE_GLOCK_18].meshs, 2);
	env->weapons[W_GLOCK_18].w_map = &env->maps[SCENE_GLOCK_18];
//	printf("%s\n", env->weapons[W_GLOCK_18].mesh->name);
	env->weapons[W_AUG].mesh = (t_mesh*)env->maps[SCENE_AUG].meshs.c;
	env->weapons[W_AUG].breech = dyacc(&env->maps[SCENE_AUG].meshs, 2);
	env->weapons[W_AUG].w_map = &env->maps[SCENE_AUG];
//	printf("%s\n", env->weapons[W_AUG].mesh->name);
	env->weapons[W_UMP45].mesh = (t_mesh*)env->maps[SCENE_UMP45].meshs.c;
	env->weapons[W_UMP45].breech = dyacc(&env->maps[SCENE_UMP45].meshs, 2);
	env->weapons[W_UMP45].w_map = &env->maps[SCENE_UMP45];
//	printf("%s\n", env->weapons[W_UMP45].mesh->name);
	env->weapons[W_MAG7].mesh = (t_mesh*)env->maps[SCENE_MAG7].meshs.c;
	env->weapons[W_MAG7].breech = dyacc(&env->maps[SCENE_MAG7].meshs, 1);
	env->weapons[W_MAG7].w_map = &env->maps[SCENE_MAG7];
//	printf("%s\n", env->weapons[W_MAG7].mesh->name);
	env->weapons[W_GALIL].mesh = (t_mesh*)env->maps[SCENE_GALIL].meshs.c;
	env->weapons[W_GALIL].breech = dyacc(&env->maps[SCENE_GALIL].meshs, 2);
	env->weapons[W_GALIL].w_map = &env->maps[SCENE_GALIL];
//	printf("%s\n", env->weapons[W_GALIL].mesh->name);
	env->weapons[W_NEGEV].mesh = (t_mesh*)env->maps[SCENE_NEGEV].meshs.c;
	env->weapons[W_NEGEV].breech = dyacc(&env->maps[SCENE_NEGEV].meshs, 2);
	env->weapons[W_NEGEV].w_map = &env->maps[SCENE_NEGEV];
//	printf("%s\n", env->weapons[W_NEGEV].mesh->name);
	env->weapons[W_TEC9].mesh = (t_mesh*)env->maps[SCENE_TEC9].meshs.c;
	env->weapons[W_TEC9].breech = dyacc(&env->maps[SCENE_TEC9].meshs, 2);
	env->weapons[W_TEC9].w_map = &env->maps[SCENE_TEC9];
//	printf("%s\n", env->weapons[W_TEC9].mesh->name);
}

static void	assign_weapons_samples(t_env *env)
{
	env->weapons[W_FAMAS].shoot = SA_FAMAS_FIRE;
	env->weapons[W_AK47].shoot = SA_AK47_FIRE;
	env->weapons[W_SAWED_OFF].shoot = SA_SAWED_OFF_FIRE;
	env->weapons[W_GLOCK_18].shoot = SA_GLOCK_FIRE;
	env->weapons[W_AUG].shoot = SA_AUG_FIRE;
	env->weapons[W_UMP45].shoot = SA_UMP45_FIRE;
	env->weapons[W_MAG7].shoot = SA_MAG7_FIRE;
	env->weapons[W_GALIL].shoot = SA_GALIL_FIRE;
	env->weapons[W_NEGEV].shoot = SA_NEGEV_FIRE;
	env->weapons[W_TEC9].shoot = SA_TEC9_FIRE;

	env->weapons[W_FAMAS].reload = SA_FAMAS_RELOAD;
	env->weapons[W_AK47].reload = SA_AK47_RELOAD;
	env->weapons[W_SAWED_OFF].reload = SA_SAWED_OFF_FILL;
	env->weapons[W_GLOCK_18].reload = SA_GLOCK_RELOAD;
	env->weapons[W_AUG].reload = SA_AUG_RELOAD;
	env->weapons[W_UMP45].reload = SA_UMP45_RELOAD;
	env->weapons[W_MAG7].reload = SA_MAG7_RELOAD;
	env->weapons[W_GALIL].reload = SA_GALIL_RELOAD;
	env->weapons[W_NEGEV].reload = SA_NEGEV_RELOAD;
	env->weapons[W_TEC9].reload = SA_TEC9_RELOAD;
}

int		init_weapons(t_env *env)
{
	if (dup_names(env))
		return (-1);
	assign_wmeshs(env);
	assign_weapons_stats(env);
	assign_weapons_samples(env);
	return (0);
}
