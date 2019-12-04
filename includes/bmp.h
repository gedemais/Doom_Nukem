#ifndef BMP_H
# define BMP_H

# define BMP_HSIZE 54

enum			e_sprite_id
{
	SP_MONKEY,
	SP_MAX
};

typedef struct	s_sprite
{
	char		*img_data;
	int			hgt;
	int			wdt;
	int			alpha;
	int			pad;
}				t_sprite;

char			*bmp_read(char *path, int *wdt, int *hgt);

#endif
