#include "main.h"
/*
static char	dec_to_hex(char c)
{
	static char	hex[127] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
							15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, ' ',
							'!', '"', '#', '$', '%', '&', 39, '(', ')', '*',
							'+', ',', '-', '.', '/', '0', '1', '2', '3', '4',
							'5', '6', '7', '8', '9', ':',  ';', '<', '=', '>',
							'?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\',
							']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v','w', 'x', 'y', 'z',
							'{', '|', '}', '~'};

	return (hex[(int)c]);
}*/

static void	map_letter(t_env *env, FT_Bitmap bmp, t_point o)
{
	int				x;
	unsigned int	y;
	unsigned int	z;
	unsigned int	i;
	unsigned char	*dst;

	i = 0;
	y = 0;
	while (y < bmp.rows && !(x = 0))
	{
		z = 0;
		dst = (unsigned char*)&env->mlx.img_data[((o.y + (y - 1)) * WDT + o.x) * 4];
		while (x < bmp.pitch - 3)
		{
			if (bmp.buffer[i + x] == 0 && bmp.buffer[i + x + 1] == 0
				&& bmp.buffer[i + x + 2] == 0)
			{
				x += 3;
				z += 4;
				continue;
			}
			dst[z] = bmp.buffer[i + x];
			dst[z + 1] = bmp.buffer[i + x + 1];
			dst[z + 2] = bmp.buffer[i + x + 2];
			x += 3;
			z += 4;
		}
		i += bmp.pitch;
		y++;
	}
}

void		my_string_put(t_env *env, t_point o, int font, char *s)
{
	FT_UInt	glyph_index;
	t_ttf	*ttf;
	int		i;

	i = 0;
	ttf = &env->ttfs;
	FT_Set_Char_Size(ttf->faces[font], 0, 6*64, 300, 120);
	while (s[i])
	{
		if (!(glyph_index = FT_Get_Char_Index(ttf->faces[font], s[i] - 5)))
			return ;
		if (FT_Load_Char(ttf->faces[font], glyph_index, FT_LOAD_RENDER))
			return ;
		map_letter(env, ttf->faces[font]->glyph->bitmap, o);
		o.x += ttf->faces[font]->glyph->advance.x >> 6;
		o.y += ttf->faces[font]->glyph->advance.y >> 6;
		i++;
	}
}

int		load_fonts(t_env *env)
{
	t_ttf			*ttf;
	unsigned int	i;
	int				err;

	i = 0;
	ttf = &env->ttfs;
	if (FT_Init_FreeType(&env->ttfs.fontlib)
		&& write(2, FT_LIB, ft_strlen(FT_LIB)))
		return (-1);
	while (i < FONT_MAX)
	{
		if ((err = FT_New_Face(ttf->fontlib,
			fonts_paths(i), 0, &ttf->faces[i])))
		{
			ft_putstr_fd(fonts_paths(i), 2);
			ft_putendl_fd(NSFD_ERR, 2);
			return (-1);
		}
		i++;
	}
	return (0);
}
