#include "main.h"

void	switch_bit(t_buzzer *b)
{
	t_triangle	*t;
	int			i;

	i = 0;
	b->on = !b->on;
	while (i < b->start->tris.nb_cells)
	{
		t = dyacc(&b->start->tris, i);
		t->color = b->on ? 0x00ff00 : 0xff0000;
		i++;
	}
	i = 0;
	while (i < b->buzzer->tris.nb_cells)
	{
		t = dyacc(&b->buzzer->tris, i);
		t->color = b->on ? 0x00ff00 : 0xff0000;
		i++;
	}
}

int		handle_switches(t_env *env)
{
	t_buzzer	*buzz;

	if (!(buzz = get_closest_switch(env)))
		return (0);
	if (buzz->)
	return (0);
}
