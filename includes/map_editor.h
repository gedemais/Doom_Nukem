#ifndef MAP_EDITOR_H
# define MAP_EDITOR_H

# define MAX_NAME_LENGTH 64

enum	e_maped_sc_id
{
	MAPED_SC_MENU,
	MAPED_SC_NEW_MAP,
	MAPED_SC_CREATIVE,
	MAPED_SC_MAX
};

enum	e_maped_menu_button_id
{
	MAPED_MENU_BUTTON_NEW_MAP,
	MAPED_MENU_BUTTON_MAIN_MENU,
	MAPED_MENU_BUTTON_MAX
};

enum	e_input_fields_id
{
	FIELD_MAP_WIDTH,
	FIELD_MAP_HEIGHT,
	FIELD_MAP_DEPTH,
	FIELD_MAX
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
	t_button		buttons[MAPED_MENU_BUTTON_MAX];
	t_point			pos[MAPED_MENU_BUTTON_MAX];
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
int					switch_mecontext(t_env *env, unsigned int i);
int					maped_menu(t_env *env);
int					maped_new_map(t_env *env);

// Routines
int					me_menu_to_new_map(t_env *env);
int					me_menu_to_creative(t_env *env);
int					me_new_map_to_creative(t_env *env);
int					me_new_map_to_menu(t_env *env);
int					me_creative_to_menu(t_env *env);

int					input_field(t_env *env, t_point o, int nfield, char **ret);
void				draw_rectangle(char *img, t_point o, t_point dims, int color);

// Saves
int					write_infile(char *f_path, char *str, int len, bool token);
char				**listpath(char *d_path, char *format);
#endif
