#include "main.h"
/*
int		init_custom_scroll_file(t_env *env)
{
	char		**list;
	t_scroll	*s;

	s = &env->edit_env.scroll;

	if (!(list = listpath(MAPED_SAVE_PATH, ".map")))
		return (-1);

	*s = (t_scroll){.d = (t_point){400, 800}, .o = (t_point){100, 100},
		.max = ft_tablen(list), .color = 0xaaaaaa, .font = SCROLL_FILE_FONT,
		.case_size = 50, .mouse_index = -1};

	s->list = list;
	s->nb_case = s->d.y / s->case_size - 1;

	if (s->case_size > s->max)
		s->nb_case = s->max;
	return (0);
}*/

int		init_maped_scroll_file(t_env *env)
{
	char		**list;
	t_scroll	*s;

	s = &env->edit_env.scroll;

	if (!(list = listpath(MAPED_SAVE_PATH, ".map")))
		return (-1);

	*s = (t_scroll){.d = (t_point){400, 800}, .o = (t_point){100, 100},
		.max = ft_tablen(list), .color = 0xaaaaaa, .font = SCROLL_FILE_FONT,
		.case_size = 50, .mouse_index = -1};

	s->list = list;
	s->nb_case = s->d.y / s->case_size - 1;

	if (s->case_size > s->max)
		s->nb_case = s->max;
	return (0);
}

static void		display_str(t_env *env, t_point police, int i)
{
	t_scroll		*s;
	int				pos;
	int				size;
	t_ttf_config	*conf;

	s = &env->edit_env.scroll;
	conf = ttf_config();
	ft_bzero(conf->s, sizeof(unsigned char) * 1024);
	if (s->max == 0)
		ft_strlcpy((char *)conf->s, "no file found", 13);
	else
	{
		size = s->d.x / (conf->size + 10);
		pos = s->current + i;
		if (pos > s->max - 1)
			pos = pos - s->max;
		ft_strlcpy((char *)conf->s, s->list[pos], size);
		if (s->mouse_index == i)
		{
			ft_strdel(&s->s_path);
			s->s_path = ft_strdup(s->list[pos]);
		}
	}
	my_string_put(env, env->mlx.img_data, police, s->font);
}

static void		get_mouse_index(t_env *env, t_point pos, t_point rect_d, int i)
{
	int		mouse_x;
	int		mouse_y;

	mouse_x = env->events.mouse_pos.x;
	mouse_y = env->events.mouse_pos.y;

	if (env->events.buttons[BUTTON_SCROLL_UP])
		++env->edit_env.scroll.current;
	else if (env->events.buttons[BUTTON_SCROLL_DOWN])
		--env->edit_env.scroll.current;
	else if (env->events.buttons[BUTTON_LCLIC])
		printf("selected path: %s\n", env->edit_env.scroll.s_path);

	if (mouse_x > pos.x && mouse_x < pos.x + rect_d.x
	&& mouse_y > pos.y && mouse_y < pos.y + rect_d.y)
		env->edit_env.scroll.mouse_index = i;
	else
		env->edit_env.scroll.mouse_index = -1;
}

void		display_file(t_env *env)
{
	t_scroll		*s;
	t_point			pos;
	t_point			police;
	int				color;
	int				i;

	i = -1;
	s = &env->edit_env.scroll;
	if (s->list == NULL)
		return ;
	(s->current < 0) ? (s->current = s->max) : 0;
	(s->current > s->max) ? (s->current = 0) : 0;
	while (++i < s->nb_case)
	{
		pos = (t_point){s->o.x, s->o.y + i * s->case_size + i};
		get_mouse_index(env, pos, (t_point){s->d.x, s->case_size}, i);
		if (s->mouse_index == i)
			color = 0x00ffff;
		else
			color = s->color;
		draw_rectangle(env->mlx.img_data, pos, (t_point){s->d.x, s->case_size}, color);
		police.x = pos.x + 10;
		police.y = pos.y + s->case_size - 10;
		display_str(env, police, i);
	}
}

