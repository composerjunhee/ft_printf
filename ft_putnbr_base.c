/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:47:20 by junheeki          #+#    #+#             */
/*   Updated: 2023/01/04 14:36:47 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	printNbr(int n, int baseValue, char *symbols)
{
	long	nLong;

	nLong = n;
	if (nLong < 0)
	{
		nLong = -nLong;
		ft_putchar('-');
	}
	if (nLong >= baseValue)
		printNbr(nLong / baseValue, baseValue, symbols);
	ft_putchar(symbols[nLong % baseValue]);
}

int	doubleChar(char *symbols)
{
	int	i;
	int	j;

	i = 0;
	while (*(symbols + i))
	{
		j = i + 1;
		while (*(symbols + j))
		{
			if (*(symbols + i) == *(symbols + j))
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	baseValue;

	baseValue = 0;
	while (base[baseValue])
	{
		if (base[baseValue] == '+' || base[baseValue] == '-')
			return ;
		++baseValue;
	}
	if (baseValue < 2)
		return ;
	if (doubleChar(base))
		return ;
	printNbr(nbr, baseValue, base);
}
