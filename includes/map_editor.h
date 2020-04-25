#ifndef MAP_EDITOR_H
# define MAP_EDITOR_H

# define MAX_NAME_LENGTH 64

enum	e_maped_sc_id
{
	MAPED_SC_MENU,
	MAPED_NEW_MAP,
	MAPED_CREA,
	MAPED_SC_MAX
};

enum	e_maped_cmp_button_id
{
	EDT_BUTTON_MAX
};

struct				s_ed_map
{
	t_sprite	*textures[256];
	char		***map;
	t_sprite	*skybox;
	char		name[MAX_NAME_LENGTH];
	int			width;
	int			height;
	int			depth;
};

struct				s_edit_env
{
	t_env			*env;
	t_button		buttons[EDT_BUTTON_MAX];
	t_point			pos[EDT_BUTTON_MAX];
	t_dynarray		maps;
	t_ed_map		new_map;
	int				sub_context;
};


int					setup_medit(t_env *env);
int					key_press_maped(int key, void *param);
int					key_release_maped(int key, void *param);
int					mouse_press_maped(int button, int x, int y, void *param);
int					mouse_release_maped(int button, int x, int y, void *param);
int					mouse_position_maped(int x, int y, void *param);
int					render_maped(void *param);

/*          sous contextes du mode editeur            */
int					maped_menu(t_env *env);

int					input_field(t_env *env, t_point o, char **ret);
void				draw_rectangle(char *img, t_point o, t_point dims, int color);

#endif
