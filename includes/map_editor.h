#ifndef MAP_EDITOR_H
# define MAP_EDITOR_H

# define MAX_NAME_LENGTH 64
# define MAX_CHUNKS 200000

enum	e_maped_sc_id
{
	MAPED_SC_MENU,
	MAPED_SC_NEW_MAP,
	MAPED_SC_CREATIVE,
	MAPED_SC_MAX
};

enum	e_create_map_error_id
{
	CM_ERR_NONE,
	CM_ERR_TOO_MANY_CHUNKS,
	CM_ERR_INVALID_SCALE,
	CM_ERR_INVALID_DIM,
	CM_ERR_MAX
};

enum	e_maped_menu_button_id
{
	MAPED_MENU_BUTTON_NEW_MAP,
	MAPED_MENU_BUTTON_MAIN_MENU,
	MAPED_NM_BUTTON_CREATE,
	MAPED_MENU_BUTTON_MAX
};

struct				s_scroll
{
	int		case_size;
	int		color;
	int		current;
	int		font;
	int		max;
	int		mouse_index;
	int		nb_case;
	char	*s_path;
	t_point	d;
	t_point	o;
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
	t_scroll			scroll;
	int				error;
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
int					maped_creative(t_env *env);

// Routines
int					me_menu_to_new_map(t_env *env);
int					me_menu_to_creative(t_env *env);
int					me_new_map_to_creative(t_env *env);
int					me_new_map_to_menu(t_env *env);
int					me_creative_to_menu(t_env *env);

int					input_field(t_env *env, t_point o, int nfield, char **ret);
void				draw_rectangle(char *img, t_point o, t_point dims, int color);

// Map
int					create_me_map(t_env *env);

// Saves
int					write_infile(char *f_path, char *str, int len, bool token);
char				**listpath(char *d_path, char *format);
#endif
