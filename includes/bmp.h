#ifndef BMP_H
# define BMP_H

# define BMP_HSIZE 54

enum				e_sprite_id
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
	SP_BLOC_GRASS,
	SP_MAX
};

typedef struct		s_sprite
{
	void			*img_ptr;
	char			*img_data;
	int				hgt;
	int				wdt;
	int				alpha;
	int				pad;
}					t_sprite;

char	*blit_sprite(char *img, t_sprite sprite, t_point o, float scale);
#endif
