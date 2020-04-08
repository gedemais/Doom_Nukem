#ifndef TEXT_H
# define TEXT_H

enum	e_font_id
{
	FONT_AMAZDOOM,
	FONT_MAX
};

struct	s_ttf
{
	FT_Library	fontlib;
	FT_Face		faces[FONT_MAX - 1];
};

char	*fonts_paths(unsigned int index);

#endif
