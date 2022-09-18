/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:15:58 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/19 01:47:47 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char	*ft_strchr(const char *s, int c);

char	*ft_strjoin(char *s1, char const *s2);

size_t	ft_strlen(const char *s);

char	*get_next_line(int fd, int buffer_size);

char	*get_line(char *str);

char	*get_remainder(char *str);

char	*new_buffer(int buffer_size);

int	ft_printf(const char *str_format, ...);

int	ft_printf_str(char *s);

int	ft_printf_char(char c);

int	ft_printf_signed_int(int n);

char	*ft_itoa(int n);

size_t	ft_strlen(const char *s);

void	*ft_calloc(size_t nmemb, size_t size);

#endif
