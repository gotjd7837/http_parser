#include "utils.h"

static char *save_update(char *save, char *buf)
{
    char *tmp;
    size_t new_len;

    new_len = strlen(save) + strlen(buf);
    tmp = (char *)malloc(new_len + 1);
    if (!tmp)
        return (NULL);
    
    strcpy(tmp, save);
    strcat(tmp, buf);
    
    free(save);
    return (tmp);
}

static char *get_next_save(char *save)
{
    char *new_save;
    int i;

    i = 0;
    while (save[i] && !(save[i] == '\r' && save[i + 1] == '\n'))
        i++;
    if (!save[i])
    {
        free(save);
        return (NULL);
    }
    new_save = strdup(save + i + 2);
    free(save);
    return (new_save);
}

static char *get_line(char *save)
{
    char *line;
    int i;

    i = 0;
    if (!save[i])
        return (NULL);
    while (save[i] && !(save[i] == '\r' && save[i + 1] == '\n'))
        i++;
    if (!save[i])
        line = strdup(save);
    else
        line = strndup(save, i);
    return (line);
}

static char *get_save(int fd, char *save)
{
    char *buf;
    ssize_t read_len;

    buf = (char *)malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    
    while (1)
    {
        read_len = read(fd, buf, BUFFER_SIZE);
        if (read_len < 0)
        {
            free(buf);
            free(save);
            return (NULL);
        }
        if (read_len == 0)
            break;

        buf[read_len] = '\0';
        if (!save)
            save = strdup("");
        save = save_update(save, buf);
        if (strstr(save, "\r\n")) // CRLF를 찾으면 중지
            break;
    }

    free(buf);
    return (save);
}

char    *get_next_line_crlf(int fd)
{
    static char *save;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    save = get_save(fd, save);
    if (!save)
        return (NULL);

    line = get_line(save);
    save = get_next_save(save);

    return (line);
}