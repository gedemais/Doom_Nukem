/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:15:32 by gedemais          #+#    #+#             */
/*   Updated: 2020/04/28 13:56:09 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool			*init_parser(void)
{
	static bool		val = false;

	return (&val);
}

t_map			**current_map(void)
{
	static t_map	*map = NULL;

	return (&map);
}

t_ttf_config	*ttf_config(void)
{
	static t_ttf_config	conf = {"", 24};

	return (&conf);
}
