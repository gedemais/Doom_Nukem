#include "main.h"
/*
int		init_custom_scroll_file(t_env *env)
{
	t_scroll	*s;

	s = &env->edit_env.scroll;
	if (!(s->list = listpath(MAPED_SAVE_PATH, ".map")))
		return (-1);
	s->max = ft_tablen(s->list);
	s->d = (t_point){400, 800};
	s->o = (t_point){100, 100};
	s->color = 0xaaaaaa;
	s->font = SCROLL_FILE_FONT;
	s->case_size = 50;
	s->mouse_index = -1;
	s->nb_case = s->d.y / s->case_size - 1;
	if (s->case_size > s->max)
		s->nb_case = s->max;
	return (0);
}*/

int		init_maped_scroll_file(t_env *env)
{
	t_scroll	*s;

	s = &env->edit_env.scroll;
	if (!(s->list = listpath(MAPED_SAVE_PATH, ".map")))
		return (-1);
	s->max = ft_tablen(s->list);
	s->d = (t_point){400, 800};
	s->o = (t_point){100, 100};
	s->color = 0xaaaaaa;
	s->font = SCROLL_FILE_FONT;
	s->case_size = 50;
	s->mouse_index = -1;
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

	if (mouse_x > pos.x && mouse_x < pos.x + rect_d.x
	&& mouse_y > pos.y && mouse_y < pos.y + rect_d.y)
		env->edit_env.scroll.mouse_index = i;
}

void		display_file(t_env *env)
{
	int				i;
	t_point			pos;
	t_scroll		*s;

	i = -1;
	s = &env->edit_env.scroll;
	if (s->list == NULL)
		return ;
	s->current = s->current < 0 ? s->max : s->current;
	s->current = s->current > s->max ? 0 : s->current;
	while (++i < s->nb_case)
	{
		pos = (t_point){s->o.x, s->o.y + i * s->case_size + i};
		get_mouse_index(env, pos, (t_point){s->d.x, s->case_size}, i);
		draw_rectangle(env->mlx.img_data, pos, (t_point){s->d.x, s->case_size},
			s->mouse_index == i ? 0x00ffff : s->color);
		display_str(env, (t_point){pos.x + 10, pos.y + s->case_size - 10}, i);
	}
	if (s->mouse_index == -1)
		ft_strdel(&s->s_path);
}

