#include "main.h"

static bool	is_door(t_custom_env *c, t_event_block *block)
{
	t_dynarray	*door;
	int			*pos;
	int			i;
	int			j;

	i = 0;
	while (i < c->doors.nb_cells)
	{
		j = 0;
		door = dyacc(&c->doors, i);
		while (j < door->nb_cells)
		{
			pos = dyacc(door, j);
			if (!ft_memcmp(pos, block, sizeof(int) * 3))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	check_pos_dynarray(t_dynarray *pos, int p[4])
{
	int		*index;
	int		i;

	i = 0;
	while (i < pos->nb_cells)
	{
		index = dyacc(pos, i);
		if (!ft_memcmp(index, p, sizeof(int) * 3))
			return (true);
		i++;
	}
	return (false);
}

static int	get_door_recursive(t_dynarray *pos, unsigned char ***map, int p[4])
{
	if (map[p[0]][p[1]][p[2]] == 160 + BE_DOOR
		&& !check_pos_dynarray(pos, p))
	{
		if (push_dynarray(pos, p, false))
			return (-1);
		if (get_door_recursive(pos, map, (int[4]){p[0] + 1, p[1], p[2]})
			|| get_door_recursive(pos, map, (int[4]){p[0], p[1] + 1, p[2]})
			|| get_door_recursive(pos, map, (int[4]){p[0], p[1], p[2] + 1})
			|| get_door_recursive(pos, map, (int[4]){p[0] - 1, p[1], p[2]})
			|| get_door_recursive(pos, map, (int[4]){p[0], p[1] - 1, p[2]})
			|| get_door_recursive(pos, map, (int[4]){p[0], p[1], p[2] - 1}))
			return (-1);
	}
	return (0);
}

static int	new_door(t_custom_env *c, t_event_block *block)
{
	t_dynarray	p;
	int			pos[4];

	ft_memcpy(pos, block, sizeof(int) * 4);
	if (init_dynarray(&p, sizeof(int[4]), 0))
		return (-1);
	if (get_door_recursive(&p, c->env->edit_env.new_map.map, pos)
		|| push_dynarray(&c->doors, &p, false))
		return (-1);
	return (0);
}

int			init_custom_door(t_custom_env *c, t_event_block *block)
{
	if (c->doors.byte_size == 0
		&& init_dynarray(&c->doors, sizeof(t_dynarray), 0))
		return (-1);
	if (!is_door(c, block) && new_door(c, block))
		return (-1);
	block->param.door = c->doors.nb_cells - 1;
	return (0);
}
