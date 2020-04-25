#ifndef BMP_H
# define BMP_H

# define ALPHA -16777216

# define BLACK "\033[22;30m"
# define BLUE "\033[22;34m"
# define RED "\033[22;31m"
# define L_RED "\033[01;31m"
# define L_GREEN "\033[01;32m"
# define GRA "\033[1m"
# define STOP "\033[0m"

enum	e_sprite_id
{
/*
** Title screen
*/
	SP_TS_BUTTON_1C,
	SP_TS_BUTTON_1H,
	SP_TS_BUTTON_1O,
	SP_TS_BUTTON_2C,
	SP_TS_BUTTON_2H,
	SP_TS_BUTTON_2O,
	SP_TS_BUTTON_3C,
	SP_TS_BUTTON_3H,
	SP_TS_BUTTON_3O,
	SP_TS_BUTTON_5C,
	SP_TS_BUTTON_5H,
	SP_TS_BUTTON_5O,
	SP_TS_LOGO,
	SP_TXT_LOADER_CMP,
	SP_BD_BUTTON_CMP,
	SP_CP_BUTTON_1C,
	SP_CP_BUTTON_1H,
	SP_CP_BUTTON_1O,
	SP_CP_BUTTON_2C,
	SP_CP_BUTTON_2H,
	SP_CP_BUTTON_2O,
	SP_CP_BUTTON_3C,
	SP_CP_BUTTON_3H,
	SP_CP_BUTTON_3O,
	SP_TS_BACKGROUND,
	SP_CMP_TS_BACKGROUND,
	SP_ME_BACKGROUND,
	SP_MAX
};

struct	s_sprite
{
	void			*img_ptr;
	char			*img_data;
	int				hgt;
	int				wdt;
	int				alpha;
	int				pad;
};

char		*sprites_paths(unsigned int index);
char		*blit_sprite(char *img, t_sprite sprite, t_point o, float scale);
void		map_sprite(char *img, t_sprite sprite, t_point o);
t_sprite	*load_sprites(t_mlx *mlx);
int			load_texture(t_mlx *mlx, char *path, t_sprite *txt);
void		reverse_texture(t_sprite *txt);
char		*alpha_val(void);

#endif
