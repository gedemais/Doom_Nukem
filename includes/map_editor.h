#ifndef MAP_EDITOR_H
# define MAP_EDITOR_H

# define MAX_CHUNKS 200000

# define MAPED_WALK_SPEED 0.07f

# define CROSSHAIR_SIZE 16
# define CROSSHAIR_THICKNESS 2
# define CROSSHAIR_COLOR 0xffffff
# define MAP_MAGIC_NUMBER 0x12ff8969
# define PUT_BLOCK_DELAY 10

# define SCROLL_FILE_FONT FONT_ARIAL
# define MAX_MAP_PATH_LEN 128
# define MAPED_SAVE_PATH "./resources/custom_maps/"
# define MAPED_ICONE_PATH "./resources/sprites/icones/"

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
	CM_ERR_INVALID_DIM,
	CM_ERR_INVALID_NAME,
	CM_ERR_MAX
};

enum	e_maped_menu_button_id
{
	MAPED_MENU_BUTTON_NEW_MAP,
	MAPED_MENU_BUTTON_MAIN_MENU,
	MAPED_NM_BUTTON_CREATE,
	MAPED_NM_BUTTON_MAPED,
	MAPED_MENU_BUTTON_MAX
};

enum	e_bloc_faces_id
{
	FACE_NORD,
	FACE_SUD,
	FACE_EST,
	FACE_OUEST,
	FACE_UP,
	FACE_BOTTOM,
	FACE_MAX
};

enum	e_blocs_textures_ids
{
	BTXT_NONE,
	BTXT_BRICK,
	BTXT_DARK_BRICK,
	BTXT_CLEAN_STONE,
	BTXT_DIRT,
	BTXT_DIRT_GRASS,
	BTXT_DIRT_SNOW,
	BTXT_ICE,
	BTXT_GOLD,
	BTXT_IRON,
	BTXT_LIBRARY,
	BTXT_LIGHT,
	BTXT_OBSIDIENNE,
	BTXT_SAND,
	BTXT_STONE,
	BTXT_WOOD_A,
	BTXT_WOOD_A_CUT,
	BTXT_WOOD_B,
	BTXT_WOOD_B_CUT,
	BTXT_WOOD_C,
	BTXT_WOOD_C_CUT,
	BTXT_WOOD_D,
	BTXT_WOOD_D_CUT,
	BTXT_JUKEBOX,
	BTXT_MAX
};

enum	e_bloc_type
{
	BC_CUBE,
	BC_SLOPE,
	BC_OBJ,
	BC_MAX
};

struct				s_scroll
{
	char	**list;
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

struct				s_cube_pallet
{
	t_sprite		sprite;
	bool			cube;
	bool			slope;
	bool			obj;
};

struct				s_ed_map
{
	t_sprite	*textures[256];
	char		***map;
	char		*flat;
	char		*name;
	int			width;
	int			height;
	int			depth;
};

struct				s_edit_env
{
	t_env			*env;
	t_cube_pallet	pallet[BTXT_MAX];
	t_sprite		btxts[BTXT_MAX];
	t_button		buttons[MAPED_MENU_BUTTON_MAX];
	t_point			pos[MAPED_MENU_BUTTON_MAX];
	t_ed_map		new_map;
	t_map			map;
	t_scroll		scroll;
	char			current_bc;
	char			current_bt;
	int				error;
	int				sub_context;
};


int					setup_medit(t_env *env);
char				*blocs_txt_paths(unsigned int index);

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
int					build_map(t_env *env, t_ed_map *new);
int					map_to_scene(t_env *env);
int					init_matrice(t_ed_map *env);
void				free_matrice(t_ed_map *env);
int					export_maped_map(t_edit_env *env);
int					import_maped_map(t_edit_env *env, char *path);
int					flat_map(t_ed_map *env, int *len);
int					flat_to_matrice(t_ed_map *env, int offset);

// Pallet
int					init_cubes_pallet(t_env *env, t_edit_env *edit_env);
int					render_pallet(t_env *env);

// Scroll
int					init_maped_scroll_file(t_env *env);
void				display_file(t_env *env);

// Events
void				maped_crosshair(t_env *env);
int					put_block(t_env *env);
int					del_block(t_env *env);
void				del_door(t_env *env);
void				attribute_mesh(t_map *scene, int index);

// Saves
int					write_infile(char *f_path, char *str, int len, bool token);
char				**listpath(char *d_path, char *format);
#endif
