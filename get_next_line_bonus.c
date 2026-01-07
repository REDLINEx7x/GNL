/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:34:38 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/06 22:29:00 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*free_str(char *str)
{
	free(str);
	return (NULL);
}

static char	*fill_line(char *line, int fd)
{
	char	*buff;
	int		b;
	char	*tmp;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	b = 1;
	while (b > 0 && !ft_strchr(line, '\n'))
	{
		b = read(fd, buff, BUFFER_SIZE);
		if (b == -1)
			return (free(line), free(buff), NULL);
		if (b == 0)
			break ;
		buff[b] = '\0';
		tmp = line;
		line = ft_strjoin(tmp, buff);
		if (!line)
			return (free_str(line));
	}
	free(buff);
	return (line);
}

static char	*extract_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	return (ft_substr(line, 0, i));
}

static char	*leftovers(char *line)
{
	char	*left;
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	if (!line || *line == '\0')
		return (free_str(line));
	left = ft_strdup(line + i);
	free(line);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*result;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	line[fd] = fill_line(line[fd], fd);
	if (!line[fd] || *line[fd] == '\0')
	{
		free(line[fd]);
		line[fd] = NULL;
		return (NULL);
	}
	result = extract_line(line[fd]);
	line[fd] = leftovers(line[fd]);
	return (result);
}
