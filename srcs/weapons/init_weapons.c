#include "main.h"

int		dup_names(t_camp_env *cmp_env)
{
	const char	*names[W_MAX] = {"FAMAS", "AK-47", "Sawed-Off", "Glock-18",
									"AUG", "UMP45"};
	unsigned int	i;

	i = 0;
	while (i < W_MAX)
	{
		if (!(cmp_env->weapons[i].name = ft_strdup((char*)names[i])))
			return (-1);
		cmp_env->weapons[i].index = (int)i;
		i++;
	}
	return (0);
}

// Assigne tous les premiers meshs des objs d'armes aux t_weapon
static void		assign_meshs(t_env *env, t_camp_env	*cmp_env)
{
	cmp_env->weapons[W_FAMAS].mesh = (t_mesh*)env->maps[SCENE_FAMAS].meshs.c;
	printf("%s\n", cmp_env->weapons[W_FAMAS].mesh->name);
	cmp_env->weapons[W_AK47].mesh = (t_mesh*)env->maps[SCENE_AK47].meshs.c;
	printf("%s\n", cmp_env->weapons[W_AK47].mesh->name);
	cmp_env->weapons[W_SAWED_OFF].mesh = (t_mesh*)env->maps[SCENE_SAWED_OFF].meshs.c;
	printf("%s\n", cmp_env->weapons[W_SAWED_OFF].mesh->name);
	cmp_env->weapons[W_GLOCK_18].mesh = (t_mesh*)env->maps[SCENE_GLOCK_18].meshs.c;
	printf("%s\n", cmp_env->weapons[W_GLOCK_18].mesh->name);
	cmp_env->weapons[W_AUG].mesh = (t_mesh*)env->maps[SCENE_AUG].meshs.c;
	printf("%s\n", cmp_env->weapons[W_AUG].mesh->name);
	cmp_env->weapons[W_UMP45].mesh = (t_mesh*)env->maps[SCENE_UMP45].meshs.c;
	printf("%s\n", cmp_env->weapons[W_UMP45].mesh->name);
}

static void		assign_weapons_stats(t_camp_env *cmp_env)
{
	cmp_env->weapons[W_FAMAS].damages = 30;
	cmp_env->weapons[W_AK47].damages = 50;
	cmp_env->weapons[W_SAWED_OFF].damages = 90;
	cmp_env->weapons[W_GLOCK_18].damages = 30;
	cmp_env->weapons[W_AUG].damages = 40;
	cmp_env->weapons[W_UMP45].damages = 20;

	cmp_env->weapons[W_FAMAS].accuracy = 0.8f;
	cmp_env->weapons[W_AK47].accuracy = 0.6f;
	cmp_env->weapons[W_SAWED_OFF].accuracy = 0.3f;
	cmp_env->weapons[W_GLOCK_18].accuracy = 0.5f;
	cmp_env->weapons[W_AUG].accuracy = 0.8f;
	cmp_env->weapons[W_UMP45].accuracy = 0.5;

	cmp_env->weapons[W_FAMAS].magazine = 25;
	cmp_env->weapons[W_AK47].magazine = 30;
	cmp_env->weapons[W_SAWED_OFF].magazine = 6;
	cmp_env->weapons[W_GLOCK_18].magazine = 18;
	cmp_env->weapons[W_AUG].magazine = 30;
	cmp_env->weapons[W_UMP45].magazine = 32;

	cmp_env->weapons[W_FAMAS].reticle = 20;
	cmp_env->weapons[W_AK47].reticle = 24;
	cmp_env->weapons[W_SAWED_OFF].reticle = 32;
	cmp_env->weapons[W_GLOCK_18].reticle = 16;
	cmp_env->weapons[W_AUG].reticle = 20;
	cmp_env->weapons[W_UMP45].reticle = 22;
}

static void	assign_weapons_offsets(t_camp_env *cmp_env)
{
	(void)cmp_env;
/*	cmp_env->weapons[W_FAMAS].p_offset = (t_vec3d){};
	cmp_env->weapons[W_AK47].p_offset = (t_vec3d){};
	cmp_env->weapons[W_SAWED_OFF].p_offset = (t_vec3d){};
	cmp_env->weapons[W_GLOCK_18].p_offset = (t_vec3d){};
	cmp_env->weapons[W_AUG].p_offset = (t_vec3d){};
	cmp_env->weapons[W_UMP45].p_offset = (t_vec3d){};
	
	cmp_env->weapons[W_FAMAS].p_angle = (t_vec3d){};
	cmp_env->weapons[W_AK47].p_angle = (t_vec3d){};
	cmp_env->weapons[W_SAWED_OFF].p_angle = (t_vec3d){};
	cmp_env->weapons[W_GLOCK_18].p_angle = (t_vec3d){};
	cmp_env->weapons[W_AUG].p_angle = (t_vec3d){};
	cmp_env->weapons[W_UMP45].p_angle = (t_vec3d){};*/
}

int		init_weapons(t_env *env)
{
	t_camp_env	*cmp_env;

	cmp_env = &env->cmp_env;
	if (dup_names(cmp_env))
		return (-1);
	assign_meshs(env, cmp_env);
	assign_weapons_stats(cmp_env);
	assign_weapons_offsets(cmp_env);
	if (init_dynarray(&cmp_env->player.weapons, sizeof(t_weapon), 0))
		return (-1);
	return (0);
}
