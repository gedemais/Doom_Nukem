#include "main.h"

int		key_press_ts(int key, void *param)
{
	t_env	*env;

	env = ((t_env*)param); // Pointeur pour eviter le cast de merde a chaque acces

	env->events.keys[key] = true;// Set la case correspondance du tableau de keys a vrai
	(void)key;
	return (0);
}

int		key_release_ts(int key, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	
	env->events.keys[key] = false;
	(void)key;
	return (0);
}

int		mouse_press_ts(int button, int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	
	env->events.buttons[button] = true;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_release_ts(int button, int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	
	env->events.buttons[button] = false;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_position_ts(int x, int y, void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	env->events.mouse_pos = (t_point){x, y};
	(void)x;
	(void)y;
	return (0);
}
