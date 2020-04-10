#ifndef TEXT_H
# define TEXT_H

enum	e_font_id
{
	FONT_AMAZDOOM,
	FONT_AMMOS,
	FONT_MAX
};

struct	s_ttf
{
	FT_Library	fontlib;
	FT_Face		faces[FONT_MAX - 1];
};

char			*fonts_paths(unsigned int index);
int				load_fonts(t_env *env);
void			my_string_put(t_env *env, t_point o, int font, unsigned char *s);
t_ttf_config	*ttf_config();

#endif
