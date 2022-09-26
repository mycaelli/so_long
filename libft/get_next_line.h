/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:23:33 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/26 02:25:32 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(const char *s, int c);

char	*ft_strjoin(char *s1, char const *s2);

size_t	ft_strlen(const char *s);

char	*get_next_line(int fd, int buffer_size);

char	*get_line(char *str);

char	*get_remainder(char *str);

char	*new_buffer(int buffer_size);

#endif
