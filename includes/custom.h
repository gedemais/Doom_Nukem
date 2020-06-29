/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:38:37 by gedemais          #+#    #+#             */
/*   Updated: 2020/06/29 17:24:14 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_H
# define CUSTOM_H

# define CUSTOM_WALK_SPEED 0.05f
# define MAX_CUSTOM_MOBS 1
# define EVENT_DIST 4

# define MOB_PEACE_TIME 30

# define START_HP 100
# define HEAL_SPEED 10

# define HIT_REWARD 10
# define KILL_REWARD 60
# define KILL_DELAY 120

# define NB_STARS 100
# define STARS_SPREAD 25
# define STARS_MAX_HEIGHT 10
# define STARS_MIN_HEIGHT 7
# define MOON_SCALE 1.8f

# define LAVA_DELAY 2

enum				e_custom_sc_id
{
	CUSTOM_SC_MENU,
	CUSTOM_SC_PLAY,
	CUSTOM_SC_GAME_OVER,
	CUSTOM_SC_MAX
};

enum				e_music_tracks
{
	MT_FIRST,
	MT_SECOND,
	MT_MAX
};

enum				e_block_events
{
	BE_NONE,
	BE_JUKEBOX,
	BE_CHEST,
	BE_DOOR,
	BE_LAVA,
	BE_SPAWNER,
	BE_MOB_SPAWNER,
	BE_MAX
};

union				u_bep
{
	char		c;
	int			door;
};

struct				s_event_block
{
	int		x;
	int		y;
	int		z;
	int		index;
	int		price;
	t_bep	param;
	char	id;
};

struct				s_custom_game
{
	int			nb_spawners;
	int			wave; // index de la vague en cours
	int			player_pv; // PVs du joueur / 100
	int			mobs_pv; // PV des mobs qui spawnent pdt cette vague
	int			current_lmob; // Nombre de mobs a faire spawn avant la prochaine vague
	int			moula;
	int 		kill_count;
	int 		kill_delay;
	char		music; // ID (sound.h) de la musique jouee (-1 si aucune)
};

struct				s_custom_env
{
	t_custom_game	game;
	t_dynarray		mobs;
	t_map			scene;
	t_scroll		scroll;
	t_dynarray		events;
	t_mesh			*moon;
	t_node          *start;
    t_node          *end;
	t_env			*env;
	float			spawner;
	int				sub_context;
};

int					custom_game_over(t_env *env);
int					init_custom_door(t_custom_env *c, t_event_block *block);

int					copy_triangles(t_map *map, t_map *mob, t_mesh *m, t_mesh *new);
t_mesh				*copy_to_scene(t_map *dest, t_map *src, t_vec3d pos);

t_vec3d				get_block_center(t_event_block *block);
int					handle_block_events(t_env *env);
int					parse_events_blocks(t_env *env);

void				handle_player(t_env *env);

int					init_sky(t_env *env);
void				handle_moon(t_env *env);

int					handle_jukeboxs(t_env *env, t_event_block *block, int index);
int					handle_mystery_boxs(t_env *env, t_event_block *block, int index);
int					handle_doors(t_env *env, t_event_block *block, int index);
int					handle_lavas(t_env *env, t_event_block *block, int index);

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
