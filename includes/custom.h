/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:38:37 by gedemais          #+#    #+#             */
/*   Updated: 2020/05/27 12:12:40 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_H
# define CUSTOM_H

# define CUSTOM_WALK_SPEED 0.05f

# define MAX_CUSTOM_MOBS 1

enum				e_custom_sc_id
{
	CUSTOM_SC_MENU,
	CUSTOM_SC_PLAY,
	CUSTOM_SC_MAX
};

struct				s_custom_game
{
	int			wave; // index de la vague en cours
	int			player_pv; // PVs du joueur / 100
	int			mobs_pv; // PV des mobs qui spawnent pdt cette vague
	int			current_lmob; // Nombre de mobs a faire spawn avant la prochaine vague
	int			current_nmob; // Nombre de mobs presents sur la map
	char		music; // ID (sound.h) de la musique jouee (-1 si aucune)
};

struct				s_custom_env
{
	t_env			*env;
	t_scroll		scroll;
	t_ed_map		map;
	t_map			scene;
	t_custom_game	game;
	int				sub_context;
};

int					key_press_custom(int key, void *param);
int					key_release_custom(int key, void *param);
int					mouse_press_custom(int button, int x, int y, void *param);
int					mouse_release_custom(int button, int x, int y, void *param);
int					mouse_position_custom(int x, int y, void *param);
int					render_custom(void *param);

// Subcontexts functions
int					custom_menu(t_env *env);
int					custom_play(t_env *env);

int					init_custom_scroll_file(t_env *env);
int					setup_custom(t_env *env);
int					switch_custom_context(t_env *env, unsigned int i);

// Routines
int					custom_menu_to_play(t_env *env);
int					custom_play_to_menu(t_env *env);

#endif
