/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:34:38 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/04 10:30:51 by moamhouc         ###   ########.fr       */
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
		if (b < 0)
			return (free_str(buff));
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

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
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
//#include "get_next_line.h"
//#include <fcntl.h>
//#include <stdio.h>
//#include <unistd.h>

//int	main(void)
//{
//	int		fd;
//	char	*line;

//	// 1. Create a dummy file
//	fd = open("test.txt", O_RDWR | O_CREAT, 0644);
//	write(fd, "Hello World\n", 12);
//	close(fd);
//	// 2. Open it for reading
//	fd = open("test.txt", O_RDONLY);
//	// 3. FORCE A READ ERROR
//	// We close the file descriptor right before calling GNL
//	close(fd);
//	line = get_next_line(fd);
//	if (line == NULL)
//		printf("Success: GNL returned NULL on read error.\n");
//	else
//	{
//		printf("Fail: GNL returned a string even though read failed.\n");
//		free(line);
//	}
//	// 4. Test with a completely fake FD
//	line = get_next_line(42);
//	if (line == NULL)
//		printf("Success: GNL returned NULL on invalid FD.\n");
//	return (0);
//}
