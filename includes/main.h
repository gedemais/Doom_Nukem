#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "mlx.h"

typedef struct	s_mlx
{
	
}				t_mlx;

typedef struct	s_env
{
	void				*mlx_ptr;
	void				*mlx_win;
	void				*img_ptr;
	char				*img_data;
	int					bpp;
	int					s_l;
	int					endian;
}				t_env;

#endif
