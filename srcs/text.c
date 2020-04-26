#include "main.h"

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
			if (!bmp.buffer[i + x] && !bmp.buffer[i + x + 1]
				&& !bmp.buffer[i + x + 2])
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

void		my_string_put(t_env *env, t_point o, int font, unsigned char *s)
{
	FT_GlyphSlot	slot;
	t_ttf_config	*conf;
	t_ttf			*ttf;
	int				i;

	i = 0;
	conf = ttf_config();
	ttf = &env->ttfs;
	FT_Set_Char_Size(ttf->faces[font], conf->size * 96, conf->size * 64, 160, 80);
	while (s[i])
	{
		if (i == 0 || s[i - 1] != s[i])
			if (FT_Load_Char(ttf->faces[font], s[i], FT_LOAD_RENDER) && ++i)
				continue ;
		slot = ttf->faces[font]->glyph;
		map_letter(env, ttf->faces[font]->glyph->bitmap,
			(t_point){o.x + slot->bitmap_left, o.y - slot->bitmap_top});
		o.x += (slot->lsb_delta + conf->size);
		o.y += slot->advance.y >> 6;
		i++;
	}
}

void		textual_hint(t_env *env, char button, char *action)
{
	t_ttf_config	*conf;
	t_point			o;
	int				x_offset; // Centrer le texte
	char			s[1024];

	conf = ttf_config();
	conf->size = 20;
	ft_strcpy(s, "Press [");
	ft_strncat(s, &button, 1);
	ft_strcat(s, "] to ");
	ft_strcat(s, action);

	x_offset = (ft_strlen(s)) / 2 * conf->size;
	o.x = env->data.half_wdt - x_offset;
	o.y = HGT / 3;

	my_string_put(env, o, FONT_TXT_HINT, (unsigned char*)s);
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
