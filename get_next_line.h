/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:19:14 by zamohame          #+#    #+#             */
/*   Updated: 2024/12/09 13:43:20 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int a);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*save_remainder(char *buffer);
char	*extract_line(char *buffer);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);

#endif
