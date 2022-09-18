/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signed_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:40:59 by mcerquei          #+#    #+#             */
/*   Updated: 2022/06/03 16:22:18 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_signed_int(int n)
{
	char	*s;
	int		bytes;

	s = ft_itoa(n);
	bytes = ft_printf_str(s);
	free(s);
	return (bytes);
}
