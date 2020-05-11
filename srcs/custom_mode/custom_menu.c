#include "main.h"

static int	select_map(t_env *env)
{
	t_scroll	*s;

	s = &env->edit_env.scroll;
	display_file(env);
	if (s->s_path)
	{
		if (import_maped_map(&env->edit_env, s->s_path))
		{
			printf("Parsing Failed for map |%s|\n", s->s_path);
			exit(0);
			return (-1);
		}
		if (map_to_scene(env))
			return (-1);
	}
	ft_strdel(&s->s_path);
	return (0);
}

int			custom_menu(t_env *env)
{
	if (select_map(env))
		return (-1);
	return (0);
}