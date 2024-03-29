/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:56:03 by mrattez           #+#    #+#             */
/*   Updated: 2021/11/03 13:55:20 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_nl_eof(int fd, char *buffer, char *next_content)
{
	char	*temp_content;
	int		read_size;

	read_size = 1;
	while (read_size)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		if (read_size == 0)
			break ;
		buffer[read_size] = 0;
		if (!next_content)
			next_content = ft_strdup("");
		temp_content = next_content;
		next_content = ft_strjoin(temp_content, buffer);
		free(temp_content);
		temp_content = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (next_content);
}

char	*update_line(char *line)
{
	int		nl_index;
	char	*remains;

	nl_index = 0;
	while (line[nl_index] && line[nl_index] != '\n')
		nl_index++;
	if (!line[nl_index])
		return (NULL);
	remains = ft_substr(line, nl_index + 1, ft_strlen(line) - nl_index);
	if (!remains[0])
	{
		free(remains);
		remains = NULL;
	}
	line[nl_index + 1] = 0;
	return (remains);
}

char	*get_next_line(int fd)
{
	static char	*next_content;
	char		*buffer;
	char		*line;

	if (read(fd, NULL, 0))
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = read_until_nl_eof(fd, buffer, next_content);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	next_content = update_line(line);
	return (line);
}
