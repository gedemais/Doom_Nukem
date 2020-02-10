/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_loading_bar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 03:46:37 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/10 04:01:42 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	loading_bar(unsigned int i, unsigned int max, bool last)
{
	unsigned int	j;

	j = 0;
	if (last)
	{
		ft_putchar('\n');
		return ;
	}
	ft_putchar('[');
	while (j < i)
	{
		ft_putchar('-');
		j++;
	}
	ft_putchar('>');
	while (j < max - 1)
	{
		ft_putchar(' ');
		j++;
	}
	ft_putchar(']');
}
