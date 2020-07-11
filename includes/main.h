/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:37:38 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/11 18:05:20 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include <sys/resource.h>

# include <sys/time.h>
# include <time.h>
# include <math.h>
# include <limits.h>
# include <assert.h>
# include <pthread.h>
# include <ft2build.h>
# include FT_FREETYPE_H

# include "libft.h"
# include "mlx.h"
# include "errno.h"

# include "typedefs.h"
# include "vectors.h"
# include "errors.h"
# include "enemies.h"
# include "keys.h"
# include "sound.h"
# include "phy.h"
# include "sprites.h"
# include "obj_parser.h"
# include "raster.h"
# include "text.h"
# include "weapons.h"
# include "astar.h"

# include "title_screen.h"
# include "campaign.h"
# include "map_editor.h"
# include "custom.h"

# include "archive.h"

# include "hud.h"

// TMP
#define PUT ft_putstr("There\n"); fflush(stdout);
#define PUT1 ft_putstr("There1\n"); fflush(stdout);
#define PUT2 ft_putstr("There2\n"); fflush(stdout);
#define PUT3 ft_putstr("There3\n"); fflush(stdout);
#define PUT4 ft_putstr("There4\n"); fflush(stdout);
#define PUT5 ft_putstr("There5\n"); fflush(stdout);
#define PUT6 ft_putstr("There6\n"); fflush(stdout);
#define PUT7 ft_putstr("There7\n"); fflush(stdout);
#define PUT8 ft_putstr("There8\n"); fflush(stdout);
#define PUT9 ft_putstr("There9\n"); fflush(stdout);

# define BREAKPOINT printf("%s at line %d in %s\n", __FUNCTION__, __LINE__, __FILE__); fflush(stdout);


# define NB_THREADS 8
# define WDT 1080
# define HGT 720
# define WINDOW_NAME "Doom Nukem"

# define SENSI 0.1f
# define WALK_SPEED 0.3f
# define WSPEED 3.0f
# define PLAYER_SIZE 3.0f

enum		e_context_id
{
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
	bool		buttons[BUTTON_MAX];
	t_point		mouse_pos;
};

struct			s_data
{
	struct timeval		time;
	float		spent;
	float		half_wdt;
	float		third_wdt;
	float		half_hgt;
	int			data_size;
};

struct			s_env
{
	t_mlx			mlx;
	t_ts_env		ts_env;
	t_camp_env		cmp_env;
	t_custom_env	custom_env;
	t_edit_env		edit_env;
	t_events		events;
	t_sound			sound;
	t_sprite		*sprites;
	t_triangle		mid;
	t_map			maps[SCENE_MAX];
	t_data			data;
	t_physics		phy_env;
	t_player		player;
	t_weapon		weapons[W_MAX];
	t_cam			cam;
	t_scroll		scroll;
	t_ttf			ttfs;
	t_pf			astar;
	int				context;
	int				scene;
	float			volume;
};

void	free_mesh(t_mesh *m);

void	print_mem_usage(void);

void			print_camera_stats(t_cam *cam, char *title);

int				exit_doom(t_env *env, char *msg, int fd, int code);
int				setup(t_env *env);
int				free_env(t_env *env);

/*
** Setup
*/
int				init_mlx(t_env *env);
void			loading_bar(unsigned int i, unsigned int max, bool last);
int				init_openal(t_sound *env);
int				load_maps(t_env *env);

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
int				sample_pixel(int *img, t_point size, t_vec2d point);

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
void			test_distance_camplan(t_collide c, t_vec3d *cam_vec);
double			mesure_time(bool end);

int				key_press_dev(int key, void *param);
int				key_release_dev(int key, void *param);
int				mouse_press_dev(int button, int x, int y, void *param);
int				mouse_release_dev(int button, int x, int y, void *param);
int				mouse_position_dev(int x, int y, void *param);
int				render_dev(void *param);

/*
** GUI
*/
int				init_scroll_file(t_env *env, char *path, char *extension);

/*
** Singletons
*/
bool			*init_parser(void);

#endif
