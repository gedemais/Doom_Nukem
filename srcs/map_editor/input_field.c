#include "main.h"

int		input_field(t_env *env)
{
	static t_dynarray	field = {};
	static bool			in = true;
	t_point				o;

	o.x = 300;
	o.y = 300;
	if (field.byte_size == 0 && init_dynarray(&field, sizeof(char), 0))
		return (-1);
	draw_rectangle(env->mlx.img_data, o, (t_point){150, 25}, 0xffffff);
	if (in)
		draw_rectangle(env->mlx.img_data, (t_point){o.x + 5, o.y + 2}, (t_point){1, 20}, 0);
	return (0);
}
