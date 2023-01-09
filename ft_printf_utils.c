/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:39:30 by junheeki          #+#    #+#             */
/*   Updated: 2023/01/09 12:20:01 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(n);
	len = ft_printstr(str);
	free(str);
	return (len);
}

int	ft_printpercent(void)
{
	write(1, '%', 1);
	return (1);
}

int	ft_print_unsigned(unsigned int nbr)
{
	size_t len;

	len = ft_putnbr_base(nbr, "0123456789");
	return (len);
}

int	ft_print_hex(unsigned int nbr, const char format)
{
	size_t len;

	if (format == 'X')
		len = ft_putnbr_base(nbr, "0123456789ABCDEF");
	else
		len = ft_putnbr_base(nbr, "0123456789abcdef");
	return (len);
}

static void	ft_putptr(unsigned long long ptr, size_t *len)
{

}

int	ft_print_ptr(unsigned long long ptr)
{

}
