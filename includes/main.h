/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:37:38 by gedemais          #+#    #+#             */
/*   Updated: 2020/01/29 04:56:58 by gedemais         ###   ########.fr       */
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
# include "obj_parser.h"
# include "title_screen.h"

# define NB_THREADS 8
# define WDT 1080
# define HGT 720
# define WINDOW_NAME "Doom Nukem"

# define SENSI 0.1f
# define WALK_SPEED 0.1f

enum			e_context_id
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

typedef struct	s_data
{
	float		half_wdt;
	float		half_hgt;
	int			data_size;
}				t_data;

typedef struct	s_env
{
	t_mlx		mlx;
	t_events	events;
	t_sound		sound;
	t_sprite	*sprites;
	t_map		maps[SCENE_MAX];
	t_data		data;
	t_cam		cam;
	t_ts_env	ts_env;
	int			context;
	int			scene;
}				t_env;

int				setup(t_env *env);

/*
** Setup
*/
int				init_mlx(t_env *env);
t_sprite		*load_sprites(t_mlx *mlx);
int				init_openal(t_sound *env);
int				init_camera(t_cam *cam);
int				load_maps(t_env *env);
int				load_object(int fd, char *line);
int				setup_ts(t_env *env);

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
int				shade_color(int color, float scale);
void			draw_pixel(char *img, int x, int y, int color);
void			draw_line(t_mlx *mlx, t_point f, t_point s, int color);


/*
** Rasterization
*/
void			rasterizer(t_env *env, int scene);
void			fill_triangle_unit(t_env *env, t_triangle t, int color);

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
void			dev_handle_events(t_env *env);

double			mesure_time(bool end);

int		key_press_dev(int key, void *param);
int		key_release_dev(int key, void *param);
int		mouse_press_dev(int button, int x, int y, void *param);
int		mouse_release_dev(int button, int x, int y, void *param);
int		mouse_position_dev(int x, int y, void *param);
int		render_dev(void *param);


#endif
