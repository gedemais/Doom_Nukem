#include "main.h"
/*
static char	matcher(int key_id)
{
	static char	chars[NB_KEYS] = {'a', 's', 'd', 'f', 'h', 'g', 'z', 'x', 'c',
									'v', 0, 'b', 'q', 'w', 'e', 'r', 'y', 't',
									'1', '2', '3', '4', '6', '5', '=', '9', '7',
									'-', '8', '0', 0, 'o', 'u', 0, 'i', 'p', 0,
									'l', 'j', 0, 'k', 0, 0, 0, 0, 'n', 'm', 0,
									0, ' '};
	
	return (key_id > KEY_SPACE ? 0 : chars[key_id]);
}

static int	add_char(t_dynarray *txt, bool keys[NB_KEYS])
{
	static int	last = 0;
	char		c;
	int			i;

	i = 0;
	if (last)
	{
		last--;
		return (0);
	}
	while (i < NB_KEYS)
	{
		if (keys[i] && i == KEY_BACKSPACE)
		{
			last = 8;
			pop_dynarray(txt, false);
		}
		if (keys[i] && (c = matcher(i)))
		{
			last = 8;
			if (push_dynarray(txt, &c, false))
				return (-1);
		}
		i++;
	}
	return (0);
}*/

static int	get_boxs(t_ttf *ttfs, t_dynarray *boxs)
{
	void			*tmp;
	unsigned int	i;

	i = 0;
	if (init_dynarray(boxs, sizeof(void*), 0))
		return (-1);
	while (i < FIELD_MAX)
	{
		tmp = &ttfs->fields[i];
		if (ttfs->fields[i].rendered)
			if (push_dynarray(boxs, &tmp, false))
				return (-1);
		i++;
	}
	return (0);
}

static void			render_field(t_env *env, void *addr)
{
	t_ttf_config	*conf;
	t_point			box_pos;
	t_point			name_pos;
	t_text_box		*box;

	ft_memcpy(&box, addr, sizeof(void*));
	conf = ttf_config();
	conf->size = 20;
	ft_strcpy((char*)conf->s, box->name);
	name_pos = (t_point){box->o.x + 50, box->o.y};
	my_string_put(env, env->mlx.img_data, name_pos, FONT_COOLVETICA);

	box_pos = (t_point){box->o.x, box->o.y + conf->size};
	draw_rectangle(env->mlx.img_data, box_pos, TEXT_BOX_DIMS, TEXT_BOX_COLOR);
}

int					input_fields(t_env *env, bool refresh)
{
	static t_dynarray	boxs;
	static bool			first = true;
	int					i;

	i = 0;
	if ((refresh || first) && get_boxs(&env->ttfs, &boxs))
		return (-1);
	while (i < boxs.nb_cells)
	{
		render_field(env, dyacc(&boxs, i));
		i++;
	}
	first = false;
	return (0);
}
