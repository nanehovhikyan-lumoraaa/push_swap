/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:46:45 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/03/19 15:46:28 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_split_leftover(char *leftover)
{
	size_t	i;

	if (!leftover || !leftover[0])
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\n')
		i++;
	return (ft_substr(leftover, 0, i));
}

char	*ft_save_remainder(char *leftover)
{
	size_t	i;
	char	*remainder;

	if (!leftover)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
	{
		free(leftover);
		return (NULL);
	}
	remainder = ft_substr(leftover, i + 1, ft_strlen(leftover) - i - 1);
	free(leftover);
	return (remainder);
}

char	*handle_read_error(char *buffer, char **leftover)
{
	free(buffer);
	free(*leftover);
	*leftover = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*leftover;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while ((!leftover || !ft_strchr(leftover, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (handle_read_error(buffer, &leftover));
		buffer[bytes_read] = '\0';
		leftover = ft_strjoin(leftover, buffer);
	}
	free(buffer);
	line = ft_split_leftover(leftover);
	leftover = ft_save_remainder(leftover);
	return (line);
}
