/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_face.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 03:53:16 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/04 05:01:45 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	check_format(char **toks)
{
	unsigned int	i;

	i = 0;
	while (toks[i])
	{
		
		i++;
	}
	return (false);
}

int			load_face(char **toks, t_face face)
{
	(void)face;
	if (check_format(toks))
	{
		printf("Wrong format\n");
		return (-1);
	}
	return (0);
}
