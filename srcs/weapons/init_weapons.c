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
static void		assign_meshs(t_env *env)
{
	env->weapons[W_FAMAS].mesh = (t_mesh*)env->maps[SCENE_FAMAS].meshs.c;
	env->weapons[W_FAMAS].w_map = &env->maps[SCENE_FAMAS];
//	printf("%s\n", env->weapons[W_FAMAS].mesh->name);
	env->weapons[W_AK47].mesh = (t_mesh*)env->maps[SCENE_AK47].meshs.c;
	env->weapons[W_AK47].w_map = &env->maps[SCENE_AK47];
//	printf("%s\n", env->weapons[W_AK47].mesh->name);
	env->weapons[W_SAWED_OFF].mesh = (t_mesh*)env->maps[SCENE_SAWED_OFF].meshs.c;
	env->weapons[W_SAWED_OFF].w_map = &env->maps[SCENE_SAWED_OFF];
//	printf("%s\n", env->weapons[W_SAWED_OFF].mesh->name);
	env->weapons[W_GLOCK_18].mesh = (t_mesh*)env->maps[SCENE_GLOCK_18].meshs.c;
	env->weapons[W_GLOCK_18].w_map = &env->maps[SCENE_GLOCK_18];
//	printf("%s\n", env->weapons[W_GLOCK_18].mesh->name);
	env->weapons[W_AUG].mesh = (t_mesh*)env->maps[SCENE_AUG].meshs.c;
	env->weapons[W_AUG].w_map = &env->maps[SCENE_AUG];
//	printf("%s\n", env->weapons[W_AUG].mesh->name);
	env->weapons[W_UMP45].mesh = (t_mesh*)env->maps[SCENE_UMP45].meshs.c;
	env->weapons[W_UMP45].w_map = &env->maps[SCENE_UMP45];
//	printf("%s\n", env->weapons[W_UMP45].mesh->name);
	env->weapons[W_MAG7].mesh = (t_mesh*)env->maps[SCENE_MAG7].meshs.c;
	env->weapons[W_MAG7].w_map = &env->maps[SCENE_MAG7];
//	printf("%s\n", env->weapons[W_MAG7].mesh->name);
	env->weapons[W_GALIL].mesh = (t_mesh*)env->maps[SCENE_GALIL].meshs.c;
	env->weapons[W_GALIL].w_map = &env->maps[SCENE_GALIL];
//	printf("%s\n", env->weapons[W_GALIL].mesh->name);
	env->weapons[W_NEGEV].mesh = (t_mesh*)env->maps[SCENE_NEGEV].meshs.c;
	env->weapons[W_NEGEV].w_map = &env->maps[SCENE_NEGEV];
//	printf("%s\n", env->weapons[W_NEGEV].mesh->name);
	env->weapons[W_TEC9].mesh = (t_mesh*)env->maps[SCENE_TEC9].meshs.c;
	env->weapons[W_TEC9].w_map = &env->maps[SCENE_TEC9];
//	printf("%s\n", env->weapons[W_TEC9].mesh->name);
}

static void		assign_weapons_stats(t_env *env)
{
	env->weapons[W_FAMAS].damages = 30;
	env->weapons[W_AK47].damages = 50;
	env->weapons[W_SAWED_OFF].damages = 90;
	env->weapons[W_GLOCK_18].damages = 30;
	env->weapons[W_AUG].damages = 40;
	env->weapons[W_UMP45].damages = 30;
	env->weapons[W_MAG7].damages = 70;
	env->weapons[W_GALIL].damages = 25;
	env->weapons[W_NEGEV].damages = 25;

	env->weapons[W_FAMAS].accuracy = 0.8f;
	env->weapons[W_AK47].accuracy = 0.6f;
	env->weapons[W_SAWED_OFF].accuracy = 0.3f;
	env->weapons[W_GLOCK_18].accuracy = 0.5f;
	env->weapons[W_AUG].accuracy = 0.8f;
	env->weapons[W_UMP45].accuracy = 0.5;
	env->weapons[W_MAG7].accuracy = 0.4;
	env->weapons[W_GALIL].accuracy = 0.6;
	env->weapons[W_NEGEV].accuracy = 0.6;

	env->weapons[W_FAMAS].magazine = 25;
	env->weapons[W_AK47].magazine = 30;
	env->weapons[W_SAWED_OFF].magazine = 6;
	env->weapons[W_GLOCK_18].magazine = 18;
	env->weapons[W_AUG].magazine = 30;
	env->weapons[W_UMP45].magazine = 32;
	env->weapons[W_MAG7].magazine = 6;
	env->weapons[W_GALIL].magazine = 35;
	env->weapons[W_NEGEV].damages = 25;

	env->weapons[W_FAMAS].reticle = 20;
	env->weapons[W_AK47].reticle = 24;
	env->weapons[W_SAWED_OFF].reticle = 32;
	env->weapons[W_GLOCK_18].reticle = 16;
	env->weapons[W_AUG].reticle = 20;
	env->weapons[W_UMP45].reticle = 22;
	env->weapons[W_MAG7].reticle = 30;
	env->weapons[W_GALIL].reticle = 22;
	env->weapons[W_NEGEV].damages = 25;
}

static void	assign_weapons_offsets(t_env *env)
{
	(void)env;
/*	env->weapons[W_FAMAS].p_offset = (t_vec3d){};
	env->weapons[W_AK47].p_offset = (t_vec3d){};
	env->weapons[W_SAWED_OFF].p_offset = (t_vec3d){};
	env->weapons[W_GLOCK_18].p_offset = (t_vec3d){};
	env->weapons[W_AUG].p_offset = (t_vec3d){};
	env->weapons[W_UMP45].p_offset = (t_vec3d){};
	
	env->weapons[W_FAMAS].p_angle = (t_vec3d){};
	env->weapons[W_AK47].p_angle = (t_vec3d){};
	env->weapons[W_SAWED_OFF].p_angle = (t_vec3d){};
	env->weapons[W_GLOCK_18].p_angle = (t_vec3d){};
	env->weapons[W_AUG].p_angle = (t_vec3d){};
	env->weapons[W_UMP45].p_angle = (t_vec3d){};*/
}

int		init_weapons(t_env *env)
{
	if (dup_names(env))
		return (-1);
	assign_meshs(env);
	assign_weapons_stats(env);
	assign_weapons_offsets(env);
	if (init_dynarray(&env->player.weapons, sizeof(t_weapon), 0))
		return (-1);
	return (0);
}
