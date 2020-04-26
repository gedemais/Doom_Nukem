#include "main.h"

static void	open_me_gates(bool gates[MAPED_SC_MAX][MAPED_SC_MAX])
{
	gates[MAPED_SC_MENU][MAPED_SC_NEW_MAP] = true;
	gates[MAPED_SC_MENU][MAPED_SC_CREATIVE] = true;

	gates[MAPED_SC_NEW_MAP][MAPED_SC_CREATIVE] = true;
	gates[MAPED_SC_NEW_MAP][MAPED_SC_MENU] = true;

	gates[MAPED_SC_CREATIVE][MAPED_SC_NEW_MAP] = false;
	gates[MAPED_SC_CREATIVE][MAPED_SC_MENU] = true;
}

static void	init_me_routines(int (*routines[C_MAX][C_MAX])(t_env*))
{
	routines[MAPED_SC_MENU][MAPED_SC_NEW_MAP] = me_menu_to_new_map;
	routines[MAPED_SC_MENU][MAPED_SC_CREATIVE] = me_menu_to_creative;

	routines[MAPED_SC_NEW_MAP][MAPED_SC_CREATIVE] = me_new_map_to_creative;
	routines[MAPED_SC_NEW_MAP][MAPED_SC_MENU] = me_new_map_to_menu;

	routines[MAPED_SC_CREATIVE][MAPED_SC_NEW_MAP] = NULL;
	routines[MAPED_SC_CREATIVE][MAPED_SC_MENU] = me_creative_to_menu;
}

int			switch_mecontext(t_env *env, unsigned int i)
{
	t_edit_env		*edit_env;
	static bool		first = true;
	static bool		gates[MAPED_SC_MAX][MAPED_SC_MAX] = {};
	static int		(*routines[C_MAX][C_MAX])(t_env*) = {};

	edit_env = &env->edit_env;
	if (first)
	{
		open_me_gates(gates);
		init_me_routines(routines);
	}
	if (i >= MAPED_SC_MAX || !gates[edit_env->sub_context][i])
	{
		ft_putendl_fd(ICS_ERR, 2);
		return (-1);
	}
	if (routines[edit_env->sub_context][i])
		routines[edit_env->sub_context][i](env);
	edit_env->sub_context = i;
	first = false;
	return (0);
}
