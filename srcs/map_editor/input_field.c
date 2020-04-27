#include "main.h"

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
}

static int	inside(t_env *env, t_dynarray *txt, t_point o)
{
	t_ttf_config	*conf;
	t_point	insert_o;
	int		offset;
	//enter : 36
	//backspace : 51

	conf = ttf_config();
	offset = (txt->nb_cells * conf->size) + (txt->nb_cells ? -5 : 5);
	insert_o = (t_point){o.x + offset, o.y + 2};
	draw_rectangle(env->mlx.img_data, insert_o, (t_point){2, 26}, 0x888888);
	if (add_char(txt, env->events.keys))
		return (-1);
	return (0);
}

static void	write_text(t_env *env, t_point o, unsigned char *s, int len)
{
	t_ttf_config	*conf;

	conf = ttf_config();
	conf->size = 24;
	s[len] = 0;
	my_string_put(env, (t_point){o.x, o.y + conf->size + 2}, FONT_AMMOS, s);
}

static t_dynarray	*init_fields(void)
{
	t_dynarray		*fields;
	unsigned int	i;

	i = 0;
	if (!(fields = (t_dynarray*)malloc(sizeof(t_dynarray) * FIELD_MAX)))
		return (NULL);
	while (i < FIELD_MAX)
	{
		fields[i].byte_size = 0;
		fields[i].nb_cells = 0;
		i++;
	}
	return (fields);
}

int			input_field(t_env *env, t_point o, int nfield, char **ret)
{
	static t_dynarray	*fields = NULL;
	static bool			in = false;
	t_dynarray			*field;

	(void)ret;
	if (!(fields = init_fields()))
		return (-1);
	field = &fields[nfield];
	if (field->byte_size == 0 && (init_dynarray(field, sizeof(unsigned char), 0)))
		return (-1);
	draw_rectangle(env->mlx.img_data, o, (t_point){200, 30}, 0x333333);
	write_text(env, o, field->c, field->nb_cells);

	if (env->events.buttons[BUTTON_LCLIC])
	{
		if (ft_inbounds(env->events.mouse_pos.x, o.x, o.x + 200)
			&& ft_inbounds(env->events.mouse_pos.y, o.y, o.y + 30))
			in = true;
		else
			in = false;
	}
	if (in && inside(env, field, o)) // Si on est focus sur le field, on dessine la barre d'insertion
		return (-1);
	return (0);
}
