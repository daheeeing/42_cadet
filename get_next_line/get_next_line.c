/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:26:03 by dapark            #+#    #+#             */
/*   Updated: 2022/09/11 18:47:20 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		length;
	int		i;

	length = 0;
	i = 0;
	while (s1[length] != '\0')
		length++;
	tmp = (char *)malloc(sizeof(char) * length + 1);
	if (!tmp)
		return (0);
	while (s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	*read_oneline(int fd, char *buffer, char *store)
{
	int		size;
	char	*temp_free;

	size = 1;
	while (size)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (0);
		else if (size == 0)
			break ;
		buffer[size] = '\0';
		if (!store)
			store = ft_strdup("");
		temp_free = store;
		store = ft_strjoin(temp_free, buffer);
		if (!store)
			return (NULL);
		free(temp_free);
		temp_free = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (store);
}

static char	*line_out(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	result = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!result)
		return (NULL);
	if (result[0] == '\0')
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	char		*one_line;
	char		*buffer;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	one_line = read_oneline(fd, buffer, store);
	free(buffer);
	buffer = NULL;
	if (!one_line)
		return (NULL);
	store = line_out(one_line);
	return (one_line);
}
