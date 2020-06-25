/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 16:13:21 by grudler           #+#    #+#             */
/*   Updated: 2020/06/25 18:54:50 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include "main.h"
# define HP_MAX 100
# define DARK_GREY 0x293133
# define LIGHT_GREY 0x9C9C9C
# define NORMAL_RED 0xFF0000
# define RED_HEALTH 0xA50016
# define GREEN_HEALTH 0x009242
# define ORA_HEALTH 0xF88F23

int		draw_hud(t_env *env);
int		draw_health(t_env *env);
void	draw_compass(t_env *env);



#endif
