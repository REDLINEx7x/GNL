/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:13:46 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/01 18:52:43 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void *free_str(char *str)
{
    free(str);
    return (NULL);
}

static char *fill_line(char *line, int fd)
{
    char *buff;
    int b;
    char *tmp;

    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    b = 1;
    while(b > 0 && !ft_strchr(line, '\n'))
    {
        b = read(fd, buff, BUFFER_SIZE);
        if (b < 0)
            return(free_str(buff));
        if(b == 0)
            break;
        buff[b] = '\0';
        tmp = line;
        line = ft_strjoin(tmp, buff);
        if(!line)
            return(free_str(line));
    }
    free(buff);
    return (line);
}

static char *extract_line(char *line)
{
    int i;

    i = 0;
    while(line[i] && line[i] != '\n')
        i++;
    if(line[i] == '\n')
        i++;
    return (ft_substr(line, 0, i));
}

static char *leftovers(char *line)
{
    char *left;
    int i;
    i = 0;
    while(line[i] && line[i] != '\n')
        i++;
    if(line[i] == '\n')
        i++;
    if(!line || *line == '\0')
        return(free_str(line));
    left = ft_strdup(line + i);
    free(line);
    return(left);
    //return (ft_substr(line, i + 1, (ft_strlen(line) - i + 1)));
}

char *get_next_line(int fd)
{
    static char *line;
    char *result;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    line = fill_line(line, fd);;
    if(!line || *line == '\0')
    {
        free(line);
        line = NULL;
        return (NULL);
    }
    result = extract_line(line);
    line = leftovers(line);
    return (result);
}
//int main()
//{
//    int     fd;
//    char    *line;

//    fd = open("re.txt", O_RDONLY);
//    if (fd < 0)
//        return (1);
//    line = get_next_line(fd);
//    printf("%s", line);
//    free(line);
//    line = get_next_line(fd);
//    printf("%s", line);
//    free(line);
//    line = get_next_line(fd);
//    printf("%s", line);

//    free(line);

//    close(fd);
//    return (0);
//}

