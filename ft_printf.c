/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:49:07 by junheeki          #+#    #+#             */
/*   Updated: 2023/01/02 13:43:17 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(int c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_putstring(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_putpointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_putunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%');
		print_length += ft_putpercent();
	return (print_length);
	// %c - Prints a single character
	// %s - Prints a string
	// %p - The void * pointer argument has to be printed in hexaecimal format
	// %d - Prints a decimal(base 10) number
	// %i - Prints an integer in base 10
	// %u - Prints and unsigned decimal(base 10) number
	// %x - Prints a number in hexadeciaml(base 16) lowercase format
	// %X - Prints a number in hexadeciam(base 16) uppercase format
	// %% - Prints a percent sign
}

int ft_printf(const char* format, ...)
{
	int	i;
	va_list	args;
	int	print_length;

	i = 0;
	print_length = 0;
	va_start(args, format);

	while(format[i])
	{
		if (format[i] == '%')
		{
			print_length += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			print_length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

