/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 01:42:21 by mcerquei          #+#    #+#             */
/*   Updated: 2022/08/05 19:06:44 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_specifier(char c, va_list args)
{
	if (c == 'c')
		return (ft_printf_char(va_arg(args, int)));
	if (c == 's')
		return (ft_printf_str(va_arg(args, char *)));
	return (-1);
}

int	ft_printf(const char *str_format, ...)
{
	va_list	args;
	int		printed_bytes;
	int		i;

	va_start(args, str_format);
	i = 0;
	printed_bytes = 0;
	while (str_format[i])
	{
		if (str_format[i] != '%')
		{
			printed_bytes += write(1, &str_format[i], 1);
			i++;
		}
		else
		{
			printed_bytes += format_specifier(str_format[i + 1], args);
			i += 2;
		}
	}
	va_end(args);
	return (printed_bytes);
}
