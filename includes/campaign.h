/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   campaign.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 01:54:42 by gedemais          #+#    #+#             */
/*   Updated: 2020/05/25 15:43:17 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMPAIGN_H
# define CAMPAIGN_H

enum	e_cmp_sub_contexts
{
	CMP_SC_MENU,
	CMP_SC_GAME,
	CMP_SC_MAX
};

enum	e_cmp_menu_buttons_id
{
	CMP_BUTTON_MAIN_MENU,
	CMP_BUTTON_NEW_GAME,
	CMP_BUTTON_MAX
};

enum	e_sector_id
{
	SECTOR_FAMAS,
	SECTOR_AK47,
	SECTOR_SAWED_OFF,
	SECTOR_GLOCK_18,
	SECTOR_AUG,
	SECTOR_UMP45,
	SECTOR_MAG7,
	SECTOR_GALIL,
	SECTOR_NEGEV,
	SECTOR_TEC9,
	SECTOR_CUBE,
	SECTOR_AXIS,
	SECTOR_TEST,
	SECTOR_SLENDER,
	SECTOR_MAX
};

struct			s_door
{
	t_vec3d	pos;
	int		from;
	int		to;
	float	max_dist;
};

struct			s_sector
{
	t_door		doors[SECTOR_MAX];
	bool		accesses[SECTOR_MAX];
	int			map;
};

struct			s_player
{
	t_dynarray	weapons;
	t_weapon	*current;
	t_mesh		*body;
	int			hp;
};

struct			s_camp_env
{
	t_env		*env;
	t_button	buttons[CMP_BUTTON_MAX];
	t_point		pos[CMP_BUTTON_MAX];		
	t_sector	sectors[SECTOR_MAX];
	int			sector;
	int			sub_context;
};

int					setup_cmp(t_env *env);

int					key_press_camp(int key, void *param);
int					key_release_camp(int key, void *param);
int					mouse_press_camp(int button, int x, int y, void *param);
int					mouse_release_camp(int button, int x, int y, void *param);
int					mouse_position_camp(int x, int y, void *param);
int					render_camp(void *param);

/*
** Sectors
*/
void				init_sectors(t_env *env);
void				check_doors(t_env *env, t_camp_env *cmp_env);

/*
** Sub_contexts functions
*/
int					switch_campaign_subcontext(t_env *env, unsigned int i);
int					cmp_menu(void *param);
int					cmp_game(void *param);

/*
** Routines
*/
void				cmp_menu_to_game(t_env *env);
void				cmp_game_to_menu(t_env *env);

#endif
