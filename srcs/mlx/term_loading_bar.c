/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_loading_bar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 03:46:37 by gedemais          #+#    #+#             */
/*   Updated: 2020/02/11 04:30:43 by gedemais         ###   ########.fr       */
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
	ft_putstr(L_GREEN);
	while (j < i)
	{
		ft_putchar('-');
		j++;
	}
	ft_putstr(L_RED);
	ft_putchar('>');
	ft_putstr(STOP);
	while (j < max - 1)
	{
		ft_putchar(' ');
		j++;
	}
	ft_putstr(L_GREEN);
	ft_putchar(']');
	ft_putstr(STOP);
}
