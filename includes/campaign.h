/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   campaign.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 01:54:42 by gedemais          #+#    #+#             */
/*   Updated: 2020/01/30 01:57:36 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMPAIGN_H
# define CAMPAIGN_H


int					key_press_camp(int key, void *param);
int					key_release_camp(int key, void *param);
int					mouse_press_camp(int button, int x, int y, void *param);
int					mouse_release_camp(int button, int x, int y, void *param);
int					mouse_position_camp(int x, int y, void *param);
int					render_camp(void *param);

#endif
