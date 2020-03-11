#include "main.h"

int		switch_mecontext(t_env *env, unsigned int i)
{
	static bool		first = true;
	static bool		gates[C_MAX][C_MAX] = {};
	static void		(*routines[C_MAX][C_MAX])(t_env*) = {};

	if (first)
	{
		open_gates(gates);
		init_routines(routines);
	}
	if (i >= C_MAX || !gates[env->context][i])
	{
		ft_putstr_fd(ICS_ERR, 2);
		return (-1);
	}
	if (routines[env->context][i])
		routines[env->context][i](env);
	env->context = i;
	first = false;
	return (0);
}
