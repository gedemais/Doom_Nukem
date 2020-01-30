/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:59:03 by gedemais          #+#    #+#             */
/*   Updated: 2020/01/30 03:06:08 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

int					key_press_opt(int key, void *param);
int					key_release_opt(int key, void *param);
int					mouse_press_opt(int button, int x, int y, void *param);
int					mouse_release_opt(int button, int x, int y, void *param);
int					mouse_position_opt(int x, int y, void *param);
int					render_opt(void *param);

#endif
