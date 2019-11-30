/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:37:38 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/30 00:55:58 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdbool.h>
# include <stdio.h>
# include <time.h>

# include "libft.h"
# include "mlx.h"

# include "errors.h"
# include "keys.h"
# include "sound.h"

# define WDT 800
# define HGT 600
# define WINDOW_NAME "Doom Nukem"

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
	void		*img_ptr;
	char		*img_data;
	int			hgt;
	int			wdt;
	int			alpha;
	int			pad;
}				t_sprite;

typedef struct	s_env
{
	t_mlx		mlx;
	t_events	events;
	int			pad;
	t_sound		sound;
	t_sprite	*sprites;
}				t_env;

int		setup(t_env *env);

/*
** MLX
*/
int				init_mlx(t_mlx *mlx);
t_sprite		*load_sprites(t_mlx mlx);
void			mlx_hooks(t_env *env);
int				key_press(int key, void *param);
int				key_release(int key, void *param);
int				mouse_press(int key, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_position(int x, int y, void *param);
bool			*mouse_freedom(void);

void			draw_pixel(char *img, int x, int y, int color);
char			*blit_sprite(char *img, t_sprite sprite, int x_y[2], float sc);

/*
** OpenAl
*/
int				init_openal(t_sound *env);

/*
** Main Loop
*/
int				render(void *param);
void			handle_events(t_env *env);

double			mesure_time(bool end);
#endif
