/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:23:23 by zamohame          #+#    #+#             */
/*   Updated: 2024/12/06 17:14:12 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest1;
	const char	*src1;

	i = 0;
	dest1 = dest;
	src1 = src;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}

static char	*read_until_newline(int fd, char **saved_str)
{
	char	*buffer;
	char	*temp;
	char	*newline_pos;

	while (1)
	{
		buffer = read_from_file(fd);
		if (!buffer)
			break ;
		if (*saved_str)
		{
			temp = ft_strjoin(*saved_str, buffer);
			free(*saved_str);
			free(buffer);
			*saved_str = temp;
		}
		else
			*saved_str = buffer;
		newline_pos = ft_strchr(*saved_str, '\n');
		if (newline_pos)
			break ;
	}
	return (*saved_str);
}

char	*handle_newline(char **saved_str)
{
	char	*line;
	char	*temp;

	if ((*saved_str)[0] == '\n')
	{
		line = ft_strdup("\n");
		temp = ft_strdup(*saved_str + 1);
		free(*saved_str);
		*saved_str = temp;
		return (line);
	}
	return (NULL);
}

char	*extract_line(char **saved_str)
{
	char	*newline_pos;
	char	*line;
	char	*temp;

	newline_pos = ft_strchr(*saved_str, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		line = ft_strdup(*saved_str);
		temp = ft_strdup(newline_pos + 1);
		free(*saved_str);
		*saved_str = temp;
	}
	else
	{
		line = ft_strdup(*saved_str);
		free(*saved_str);
		*saved_str = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_until_newline(fd, &saved_str) || !*saved_str)
		return (free(saved_str), NULL);
	line = handle_newline(&saved_str);
	if (line)
		return (line);
	return (extract_line(&saved_str));
}
/*
int	main(void)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erroooooorrrrrrrrrrrr no file found :()");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	free(line);
	return (0);
}
*/
