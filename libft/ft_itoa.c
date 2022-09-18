/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 04:11:15 by mcerquei          #+#    #+#             */
/*   Updated: 2022/04/29 14:37:54 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_count(int n)
{
	unsigned long	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa_zero(void)
{
	char	*num;

	num = (char *)malloc(2 * sizeof(char));
	if (!num)
		return (NULL);
	num[0] = '0';
	num[1] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	char				*num;
	unsigned long		size;
	long				long_n;

	long_n = n;
	if (n == 0)
		return (ft_itoa_zero());
	size = ft_num_count(n);
	num = (char *)malloc((size + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[size] = '\0';
	if (n < 0)
	{
		num[0] = '-';
		long_n *= -1;
	}
	while (long_n != 0)
	{
		num[size - 1] = (long_n % 10) + '0';
		long_n /= 10;
		size--;
	}
	return (num);
}
