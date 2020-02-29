/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 04:02:00 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/20 00:24:21 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_button(t_button *button, t_point o, t_sprite *sp[3])
{
	button->l_up.x = o.x;
	button->l_up.y = o.y;

	button->r_up.x = o.x + sp[0]->wdt;
	button->r_up.y = o.y;

	button->l_down.x = o.x;
	button->l_down.y = o.y + sp[0]->hgt;

	button->r_down.x = o.x + sp[0]->wdt;
	button->r_down.y = o.y + sp[0]->hgt;

	button->on = sp[0];
	button->hover = sp[1];
	button->off = sp[2];
	
	button->is_hover = false;
}

bool	is_on_button(t_point mouse, t_button button)
{
	if (mouse.x >= button.l_up.x && mouse.x <= button.r_up.x
		&& mouse.y >= button.r_up.y && mouse.y <= button.r_down.y)
		return (true);
	return (false);
}

void	render_button(void *param, t_button button, unsigned int index)
{
	t_env		*env;
	t_sprite	*sprite;
	bool		clic;

	env = (t_env*)param;
	clic = false;
	(void)index;
	if (button.is_hover)
	{
		if (env->events.buttons[BUTTON_LCLIC])
		{
			sprite = button.on;
			blit_sprite(env->mlx.img_data, *sprite, (t_point){button.l_up.x, button.l_up.y}, 1.0f);
			clic = true;
		}
		else
			sprite = button.hover;
	}
	else
		sprite = button.off;
	if (!clic)
		blit_sprite(env->mlx.img_data, *sprite, (t_point){button.l_up.x, button.l_up.y}, 1.0f);
}
