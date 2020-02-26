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
	SP_TS_BACKGROUND,
	SP_TS_LOGO,
	TXT_BLOC_GRASS,
	SP_TXT_LOADER_CMP,
	SP_BGD_LOADER_CMP,
	SP_CP_BUTTON_1C,
	SP_CP_BUTTON_1H,
	SP_CP_BUTTON_1O,
	SP_MAX
	//cree un titre
};

struct	s_sprite
{
	void			*img_ptr; //
	char			*img_data;
	int				hgt;
	int				wdt;
	int				alpha;
	int				pad;
};

char	*sprites_paths(unsigned int index);
char	*blit_sprite(char *img, t_sprite sprite, t_point o, float scale);
char	*alpha_val(void);

#endif
