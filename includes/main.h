/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:37:38 by gedemais          #+#    #+#             */
/*   Updated: 2019/11/29 06:22:00 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdbool.h>
# include <stdio.h>

# include "libft.h"
# include "mlx.h"

# include "errors.h"
# include "keys.h"

# define WDT 800
# define HGT 600
# define WINDOW_NAME "Doom Nukem"
# define NB_HOOKS 3
# define NB_BUTTONS 5

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

typedef struct	s_events
{
	bool		keys[NB_KEYS];
	bool		buttons[NB_BUTTONS];
	char		pad[3];
	int			mouse_x;
	int			mouse_y;
}				t_events;

typedef struct	s_env
{
	t_mlx		mlx;
	t_events	events;
	int			pad;
}				t_env;

int		setup(t_env *env);

/*
** MLX
*/
int				init_mlx(t_mlx *mlx);
void			mlx_hooks(t_env *env);
int				key_press(int key, void *param);
int				key_release(int key, void *param);
int				mouse_press(int key, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_position(int x, int y, void *param);
bool			*mouse_freedom(void);

/*
** Main Loop
*/
int				render(void *param);
void			handle_events(t_env *env);

#endif
