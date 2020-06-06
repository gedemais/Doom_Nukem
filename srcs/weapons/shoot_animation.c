#include "main.h"

void	shoot_animation(t_env *env, t_weapon *w)
{
	float	progress;

	w->shooting -= env->data.spent;
	progress = 1 - (w->shooting / (60 / w->cadency));
	printf("progress : %f\n", progress);
}
