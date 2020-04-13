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

void	assign_meshs(t_env *env, t_camp_env	*cmp_env)
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

int		init_weapons(t_env *env)
{
	t_camp_env	*cmp_env;

	cmp_env = &env->cmp_env;
	if (dup_names(cmp_env))
		return (-1);
	assign_meshs(env, cmp_env);
	if (init_dynarray(&cmp_env->player.weapons, sizeof(t_weapon), 0))
		return (-1);
	return (0);
}
