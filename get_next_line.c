#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i;
    char *buff;
    static char *line;

    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while(read(fd, buff, BUFFER_SIZE) > 0)
    {
        
    }





}
