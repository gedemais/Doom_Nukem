/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   phy.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 03:01:19 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/27 19:59:43 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHY_H
# define PHY_H

# define INERTIE 0.01f
# define DIFCAMFLOOR 3

struct	s_corp
{
	t_vec3d		acc;
	t_vec3d		vo;
	t_vec3d		v;
	t_vec3d		v_cpy; //pause
	t_vec3d		pos;
	t_vec3d		o;
	t_vec3d		norm;
	t_vec3d		dims;
};

struct	s_collide
{
	t_mesh	*a;
	t_mesh	*b;
	unsigned int i_a;
	unsigned int i_b;
	unsigned int cloth_face;
	t_vec3d		diffwall;
	float dot;
};

// struct s_collde

struct	s_physics
{
	t_dynarray		collides;
	t_dynarray		collides_cam;
	bool			type_move;
	double			time;
	double			prev_time;
	unsigned int	tps;
	float			gravity;
	t_vec3d			gravitax;
	t_vec3d			f;
	t_vec3d			r;
	t_vec3d			diff_camfloor;
	unsigned int	squat;
};

void	phy_gravitax_cam(t_env *env, t_mesh *m, t_cam_stats *stats);
int		physic_engine(t_env *env, t_map *maps);
int		init_physic_engine(t_env *env);
int		init_bounding_box(t_mesh *m);
int		report_collisions(t_env *env);
int		report_cam_collisions(t_env *env, t_map *maps);
int		init_map_physics(t_map *map);

void	translate_mesh(t_map *map, t_mesh *m, t_vec3d t);
void	rotate_mesh(t_mesh *mesh, t_vec3d mesh_center, float angle,
			void (*rotation)(t_vec3d *v, t_vec3d m, float fcos, float fsin));
void	rotate_x(t_vec3d *v, t_vec3d m, float fcos, float fsin);
void	rotate_y(t_vec3d *v, t_vec3d m, float fcos, float fsin);
void	rotate_z(t_vec3d *v, t_vec3d m, float fcos, float fsin);

void	tp_mesh(t_map *map, t_mesh *m, t_vec3d t);
void	print_mesh_corp(t_mesh m);
void	print_collide(t_collide c);
void	tp_mesh_print(t_mesh *m);
/*			phy_gravity		*/
void	phy_gravitax_cam(t_env *env, t_mesh *m, t_cam_stats *stats);
void	phy_gravitax(t_env *env, t_mesh *m, int i);
/*			phy_update.c	*/
t_vec3d	update_angle(t_env *env, int index);
void	update_speeds_collide(t_env *env);
void	update_speeds_collide_cam(t_env *env, t_mesh *cam, t_map *map);
void	update_positions_gravity(t_env *env); 
void	update_positions_cam(t_env *env, t_map *map, t_mesh *cam);
/*			color_collides	*/
void	color_collides(t_env *env);
void	color_collides_cam(t_env *env);
/*			phy_move.c		*/
void	phy_move(t_env *env, bool keys[NB_KEYS], t_map *maps);
/*			phy_tool.c		*/
void	type_of_plan(t_env *env, t_collide *c, t_map *map);
t_vec3d	set_y_dir(t_env *env, t_map *map);
t_vec3d	phy_move_collide(t_env *env, t_collide *c, t_vec3d dir);
t_vec3d *coefdir_plan(t_env *env, t_mesh *m, t_mesh *cam, t_vec3d *dir);
t_vec3d test_dist_wall(t_env *env, t_collide *c, t_vec3d f);
void	print_info_phy(t_env *env, t_mesh *cam);
/*			phy_tool2.c		*/
void	stop_position_cam(t_env *env, t_map *maps, t_mesh *cam);
bool	key_move(bool keys[NB_KEYS]);
#endif
