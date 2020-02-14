#ifndef TITLE_SCREEN_H
# define TITLE_SCREEN_H

enum	e_ts_button_id
{
	TS_BUTTON_CAMPAIGN,
	TS_BUTTON_CUSTOM,
	TS_BUTTON_MAP_EDITOR,
	TS_BUTTON_QUIT,
	TS_BUTTON_MAX
};

struct	s_button
{
	t_point			l_up;
	t_point			r_up;
	t_point			l_down;
	t_point			r_down;
	t_sprite		*on;
	t_sprite		*off;
	t_sprite		*hover;
	bool			is_hover;
	bool			in_place;
};

struct	s_ts_env
{
	void			*env;
	t_button		buttons[TS_BUTTON_MAX];
};

int					key_press_ts(int key, void *param);
int					key_release_ts(int key, void *param);
int					mouse_press_ts(int button, int x, int y, void *param);
int					mouse_release_ts(int button, int x, int y, void *param);
int					mouse_position_ts(int x, int y, void *param);
int					render_ts(void *param);

void				init_button(t_button *button, t_point o, t_sprite *sp[3]);
bool				is_on_button(t_point mouse, t_button button);
void				render_button(void *param, t_button button, unsigned int index);

void				animation(void *env);

#endif
