#include "get_next_line.h"

char *line_buffer(int fd, char *sbuff, char *buff)
{
    ssize_t bytes_read;
    char    *tmp;

    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buff, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(sbuff);
            return(NULL);
        }
        else if (bytes_read == 0)
            break;
        buff[bytes_read] = '\0';
        if (!sbuff)
            sbuff = ft_strdup("");
        tmp = sbuff;
        sbuff = ft_strjoin(tmp,buff);
        free(tmp);
        tmp = NULL;
        if (ft_strchr(buff, '\n'))
            break;
    }
    return (sbuff);
}

static  char *line_set(char *buff)
{
    char *ch_left;
    ssize_t i;

    i = 0;
    while (buff[i] != '\n' && buff[i] != '\0')
        i++;
    if (buff[i] == 0 || buff[1] == 0)
            return(NULL);
    ch_left = ft_substr(buff, i + 1, ft_strlen(buff) - 1);
    if (*ch_left == 0)
    {
        free(ch_left);
        ch_left = NULL;
    }
    buff[i + 1] = 0;
    return (ch_left);
}
char *get_next_line(int fd)
{
    static char *sbuff;
    char    *line;
    char    *buff;

    buff =(char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(sbuff);
        free(buff);
        sbuff = NULL;
        buff = NULL;
        return (NULL);
    }
    if (!buff)
        return(NULL);
     line = line_buffer(fd, sbuff, buff);
     free(buff);
     buff = NULL;
if (!line || *line == '\0')
        return (NULL);
    sbuff = line_set(line);
    return (line);
}
// int main()
// {
//     int fd;

//     fd = open("test.txt",O_RDWR);
//     char * str = get_next_line(fd);
//     ft_printf("%s\n", str);
//     free(str);

// }
