/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:18:59 by junheeki          #+#    #+#             */
/*   Updated: 2023/01/09 12:20:00 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int	ft_print_hex(unsigned int nbr, const char format)
{
	size_t len;

	if (format == 'X')
		len = ft_putnbr_base(nbr, "0123456789ABCDEF");
	else
		len = ft_putnbr_base(nbr, "0123456789abcdef");
	return (len);
}
