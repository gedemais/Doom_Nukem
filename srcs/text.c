#include "main.h"

static void	map_letter(char *img, FT_Bitmap bmp, t_point o)
{
	int				x;
	unsigned int	y;
	unsigned int	z;
	unsigned int	i;
	unsigned char	*dst;
	int				pos;

	i = 0;
	y = 0;
	while (y < bmp.rows && !(x = 0))
	{
		z = 0;
		pos = ((o.y + (y - 1)) * WDT + o.x) * 4;
		if (pos < 0 && (++y))
			continue ;
		dst = (unsigned char*)&img[pos];
		while (x < bmp.pitch - 3)
		{
			if ((!bmp.buffer[i + x] && !bmp.buffer[i + x + 1]
				&& !bmp.buffer[i + x + 2]))
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

static void	get_glyph_pads(float *left, float *right, FT_Bitmap bmp)
{
	int				x;
	unsigned int	y;
	unsigned int	z;
	unsigned int	i;

	i = 0;
	y = 0;
	while (y < bmp.rows && !(x = 0))
	{
		z = 0;
		while (x < bmp.pitch - 3)
		{
			if (!bmp.buffer[i + x] && !bmp.buffer[i + x + 1]
				&& !bmp.buffer[i + x + 2])
			{
				x += 3;
				z += 4;
				continue;
			}
			if ((float)(x / 3) < *left)
				*left = (float)(x / 3);
			else if ((float)(x / 3) > *right)
				*right = (float)(x / 3);
			x += 3;
			z += 4;
		}
		i += bmp.pitch;
		y++;
	}
	*right /= bmp.width;
	*left /= bmp.width;
}

static int	compute_kernings(t_ttf *ttf, FT_Face face, int font)
{
	FT_GlyphSlot	slot;
	char			c = ' ';

	FT_Set_Char_Size(face, 50 * 96, 50 * 64, 160, 80);
	if (!(ttf->kernings[font].left_pad = (float*)malloc(sizeof(float) * 127))
		|| !(ttf->kernings[font].right_pad = (float*)malloc(sizeof(float) * 127)))
		return (-1);
	while (c < 127)
	{
		if (FT_Load_Char(face, c, FT_LOAD_RENDER) && ++c)
			continue ;
		slot = face->glyph;
		ttf->kernings[font].left_pad[(int)c] = INFINITY;
		ttf->kernings[font].right_pad[(int)c] = -INFINITY;
		get_glyph_pads(&ttf->kernings[font].left_pad[(int)c],
			&ttf->kernings[font].right_pad[(int)c], slot->bitmap);
		c++;
	}
	return (0);
}

void		my_string_put(t_env *env, char *img, t_point o, int font)
{
	FT_GlyphSlot	slot;
	t_ttf_config	*conf;
	t_ttf			*ttf;
	int				i;

	i = 0;
	conf = ttf_config();
	ttf = &env->ttfs;
	FT_Set_Char_Size(ttf->faces[font], conf->size * 96, conf->size * 64, 160, 80);
	while (conf->s[i])
	{
		if (i == 0 || conf->s[i - 1] != conf->s[i])
			if (FT_Load_Char(ttf->faces[font], conf->s[i], FT_LOAD_RENDER) && ++i)
				continue ;
		slot = ttf->faces[font]->glyph;
		if (conf->s[i] == 'j')
			o.x += conf->size / 2;
		map_letter(img, slot->bitmap,
			(t_point){o.x + slot->bitmap_left, o.y - slot->bitmap_top});
		if (conf->s[i] == ' ')
			o.x += conf->size;
		else
			o.x += slot->bitmap.width * ttf->kernings[font].right_pad[(int)conf->s[i]] + conf->size / 3;
		o.y += slot->advance.y >> 6;
		i++;
	}
}

void		textual_hint(t_env *env, char button, char *action)
{
	t_ttf_config	*conf;
	t_point			o;
	int				x_offset; // Centrer le texte

	conf = ttf_config();
	conf->size = 20;
	ft_strcpy((char*)conf->s, "Press [");
	ft_strncat((char*)conf->s, &button, 1);
	ft_strcat((char*)conf->s, "] to ");
	ft_strcat((char*)conf->s, action);

	x_offset = (ft_strlen((char*)conf->s)) / 2 * conf->size;
	o.x = env->data.half_wdt - x_offset;
	o.y = HGT / 3;

	my_string_put(env, env->mlx.img_data, o, FONT_TXT_HINT);
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
	while (i < FONT_MAX - 1)
	{
		if ((err = FT_New_Face(ttf->fontlib,
			fonts_paths(i), 0, &ttf->faces[i])))
		{
			ft_putstr_fd(fonts_paths(i), 2);
			ft_putendl_fd(NSFD_ERR, 2);
			return (-1);
		}
		if (compute_kernings(ttf, ttf->faces[i], i))
			return (-1);
		i++;
	}
	return (0);
}
