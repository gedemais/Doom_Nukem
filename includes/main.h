/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:37:38 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/14 02:44:24 by gedemais         ###   ########.fr       */
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
# include <pthread.h>

# include "libft.h"
# include "mlx.h"

# include "typedefs.h"
# include "vectors.h"
# include "errors.h"
# include "keys.h"
# include "sound.h"
# include "raster.h"
# include "bmp.h"
# include "obj_parser.h"

# include "title_screen.h"
# include "campaign.h"
# include "custom.h"
# include "map_editor.h"


# define NB_THREADS 16
# define WDT 1080
# define HGT 720
# define WINDOW_NAME "Doom Nukem"

# define SENSI 0.1f
# define WALK_SPEED 0.1f

enum		e_context_id
{
	C_DEV,
	C_TITLE_SCREEN,
	C_CAMPAIGN,
	C_CUSTOM,
	C_MAP_EDITOR,
	C_MAX
};

struct		s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			s_l;
	int			endian;
	int			pad;
};

struct			s_events
{
	bool		keys[NB_KEYS];
	bool		buttons[NB_BUTTONS];
	t_point		mouse_pos;
};

struct			s_data
{
	float		half_wdt;
	float		half_hgt;
	int			data_size;
};

struct			s_env
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
};

int				setup(t_env *env);
int				free_env(t_env *env);

/*
** Setup
*/
int				init_mlx(t_env *env);
t_sprite		*load_sprites(t_mlx *mlx);
void			loading_bar(unsigned int i, unsigned int max, bool last);
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
int				pixloc(int x, int y, bool free);
void			draw_pixel(char *img, int x, int y, int color);
void			draw_line(t_mlx *mlx, t_point f, t_point s, int color);
int				sample_pixel(char *img, t_point size, t_vec2d point);

/*
** Rasterization
*/
void			rasterizer(t_env *env, int scene);
void			fill_triangle_unit(t_env *env, t_triangle t, int color); //
void			fill_triangle_texture(t_env *env, t_triangle t); // a bouger dans raster.h

/*
** Contexts
*/
int				switch_context(t_env *env, unsigned int i);
void			ts_to_dev(t_env *env);
void			ts_to_campaign(t_env *env);
void			ts_to_custom(t_env *env);
void			ts_to_map_editor(t_env *env);
void			campaign_to_ts(t_env *env);
void			custom_to_ts(t_env *env);
void			map_editor_to_ts(t_env *env);

/*
** Main Loop
*/
int				render(void *param);
void			dev_handle_events(t_env *env);

double			mesure_time(bool end);

int				key_press_dev(int key, void *param);
int				key_release_dev(int key, void *param);
int				mouse_press_dev(int button, int x, int y, void *param);
int				mouse_release_dev(int button, int x, int y, void *param);
int				mouse_position_dev(int x, int y, void *param);
int				render_dev(void *param);


#endif
