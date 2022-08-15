/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:22:46 by mcerquei          #+#    #+#             */
/*   Updated: 2022/05/13 02:45:56 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*concat;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	concat = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	while (s1[++i])
		concat[i] = s1[i];
	while (s2[++j])
		concat[i + j] = s2[j];
	concat[i + j] = '\0';
	free(s1);
	return (concat);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if (c == 0 && *s == 0)
		return ((char *) s);
	return (NULL);
}
