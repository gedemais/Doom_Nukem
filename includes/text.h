#ifndef TEXT_H
# define TEXT_H

# define FONT_NB_CHARS 96

enum	e_font_id
{
	FONT_ARIAL,
	FONT_AMMOS,
	FONT_TXT_HINT,
	FONT_MAX
};

struct	s_kerning
{
	float	*left_pad;
	float	*right_pad;
};

struct	s_ttf
{
	FT_Library	fontlib;
	FT_Face		faces[FONT_MAX - 1];
	t_kerning	kernings[FONT_MAX - 1];
};

char			*fonts_paths(unsigned int index);
int				load_fonts(t_env *env);
void			my_string_put(t_env *env, t_point o, int font, unsigned char *s);
void			textual_hint(t_env *env, char button, char *action);
t_ttf_config	*ttf_config();

#endif
