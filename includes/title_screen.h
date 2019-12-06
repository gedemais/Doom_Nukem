#ifndef TITLE_SCREEN_H
# define TITLE_SCREEN_H

typedef struct		s_button
{
	int				pourpakcasoividetacapte;
}					t_button;

typedef struct		s_ts_env
{
	int				pourpakcasoividetacapte;
}					t_ts_env;

int					key_press_ts(int key, void *param);
int					key_release_ts(int key, void *param);
int					mouse_press_ts(int button, int x, int y, void *param);
int					mouse_release_ts(int button, int x, int y, void *param);
int					mouse_position_ts(int x, int y, void *param);
int					render_ts(void *param);

#endif
