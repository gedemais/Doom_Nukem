/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:37:38 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/02 23:25:44 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdbool.h>
# include <stdio.h>
# include <time.h>
# include <math.h>
# include <limits.h>
# include <assert.h>

# include "libft.h"
# include "mlx.h"

# include "errors.h"
# include "keys.h"
# include "sound.h"
# include "raster.h"

# define WDT 800
# define HGT 600
# define WINDOW_NAME "Doom Nukem"

# define BUFF_READ 16384

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			s_l;
	int			endian;
	int			pad;
	int			half_hgt;
	int			half_wdt;
}				t_mlx;

# define NB_BUTTONS 5

typedef struct	s_events
{
	bool		keys[NB_KEYS];
	bool		buttons[NB_BUTTONS];
	char		pad[3];
	int			mouse_x;
	int			mouse_y;
}				t_events;

# define NB_SPRITES 1

typedef struct	s_sprite
{
	char		*img_data;
	int			hgt;
	int			wdt;
	int			alpha;
	int			pad;
}				t_sprite;
/*
typedef struct	s_player
{
}				t_player;
*/
typedef struct	s_env
{
	t_mlx		mlx;
	t_events	events;
	int			pad;
	t_sound		sound;
	t_sprite	*sprites;
	t_cam		cam;
	int			pada;
}				t_env;

int		setup(t_env *env);

/*
** Setup
*/
int				init_mlx(t_env *env);
t_sprite		*load_sprites(t_mlx mlx);
char			*bmp_read(char *path, int *wdt, int *hgt);
int				init_openal(t_sound *env);
int				init_camera(t_cam *cam);
char			*read_file(int fd);

/*
** MLX
*/
void			mlx_hooks(t_env *env);
int				key_press(int key, void *param);
int				key_release(int key, void *param);
int				mouse_press(int key, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_position(int x, int y, void *param);
bool			*mouse_freedom(void);
void			draw_pixel(char *img, int x, int y, int color);
void			draw_line(t_mlx *mlx, t_point f, t_point s, int color);

/*
** Player
*/
void			rasterizer(t_env *env);

/*
** Sprites
*/
char			*sprites_paths(unsigned int index);
char			*blit_sprite(char *img, t_sprite sprite, int x_y[2], float sc);

/*
** OpenAl
*/
char			*samples_paths(unsigned int index);
void			play_ambience(t_sample sample, bool play, bool stop);

/*
** Main Loop
*/
int				render(void *param);
void			handle_events(t_env *env);

double			mesure_time(bool end);
#endif
