/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:37:38 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/06 19:36:20 by gedemais         ###   ########.fr       */
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
# include "bmp.h"

# include "title_screen.h"

# define WDT 800
# define HGT 600
# define WINDOW_NAME "Doom Nukem"
# define BUFF_READ 16384

enum			s_context_id
{
	C_DEV,
	C_TITLE_SCREEN,
	C_MAX
};

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
}				t_mlx;

typedef struct	s_events
{
	bool		keys[NB_KEYS];
	bool		buttons[NB_BUTTONS];
	char		pad[3];
	t_point		mouse_pos;
	int			padb;
}				t_events;

typedef struct	s_env
{
	t_mlx		mlx;
	t_events	events;
	t_sound		sound;
	t_sprite	*sprites;
	t_cam		cam;
	int			context;
}				t_env;

int				setup(t_env *env);

/*
** Setup
*/
int				init_mlx(t_env *env);
t_sprite		*load_sprites(t_mlx *mlx);
int				init_openal(t_sound *env);
void			init_camera(t_cam *cam);
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
** Rasterization
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


int		key_press_dev(int key, void *param);
int		key_release_dev(int key, void *param);
int		mouse_press_dev(int button, int x, int y, void *param);
int		mouse_release_dev(int button, int x, int y, void *param);
int		mouse_position_dev(int x, int y, void *param);
int		render_dev(void *param);


#endif
