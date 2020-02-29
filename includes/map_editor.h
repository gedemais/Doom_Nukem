#ifndef MAP_EDITOR_H
# define MAP_EDITOR_H

enum	e_EDIT_button_id
{
	EDT_BTN_LOAD,
	EDT_BTN_NEW,
	EDT_BTN_TXT,
	EDT_BTN_OBJ,
	EDT_BTN_MMENU,
	//	EDT_QUIT,
	EDT_BUTTON_MAX
};

//t_env	
struct				s_edit_env
{
	t_env			*env;
	t_button		buttons[EDT_BUTTON_MAX];
	t_point			pos[EDT_BUTTON_MAX];		
};

int					setup_medit(t_env *env);
int					key_press_maped(int key, void *param);
int					key_release_maped(int key, void *param);
int					mouse_press_maped(int button, int x, int y, void *param);
int					mouse_release_maped(int button, int x, int y, void *param);
int					mouse_position_maped(int x, int y, void *param);
int					render_maped(void *param);

#endif
