#include "http_parser.h"
#include "utils.h"

static void http_parser_load_garbage(t_http_request *data, int fd)
{
    char *garbage_data;
    char *line;

    garbage_data = NULL;
    while (1)
    {
        line = get_next_line_crlf(fd);
        if (!line)
            break;
        if (strcmp(line, "") == 0)
            continue;

        if (garbage_data == NULL)
            garbage_data = strdup(line);
        else
        {
            garbage_data = realloc(garbage_data, strlen(garbage_data) + strlen(line) + 3);
            strcat(garbage_data, "\r\n");
            strcat(garbage_data, line);
        }

        free(line);
    }
    data->garbage = garbage_data;
}

void http_parser_load(t_http_request *data, char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        print_error("Error: open failed");

    http_parser_load_start_line(data, fd);
    http_parser_load_headers(data, fd);
    http_parser_load_garbage(data, fd);
}