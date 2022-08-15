/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 04:43:22 by coder             #+#    #+#             */
/*   Updated: 2022/08/03 21:02:43 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd, int buffer_size)
{	
	char		*buffer;
	char		*line;
	static char	*accumulator;	
	int			validation;

	if (fd < 0 || buffer_size <= 0)
		return (NULL);
	validation = 1;
	buffer = new_buffer(buffer_size);
	while ((!ft_strchr(accumulator, '\n')) && validation > 0)
	{
		validation = read(fd, buffer, buffer_size);
		if (validation == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[validation] = '\0';
		accumulator = ft_strjoin(accumulator, buffer);
	}
	free(buffer);
	line = get_line(accumulator);
	accumulator = get_remainder(accumulator);
	return (line);
}

char	*new_buffer(int buffer_size)
{
	char	*buffer;

	buffer = malloc((buffer_size + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[len] != '\n' && str[len])
		len++;
	if (str[len] == '\n')
		len++;
	line = (char *) malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_remainder(char *str)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !str[i])
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	remainder = (char *)malloc((sizeof(char) * (ft_strlen(str) - i + 1)));
	if (!remainder)
		return (NULL);
	while (str[i])
		remainder[j++] = str[i++];
	remainder[j] = '\0';
	free(str);
	return (remainder);
}
