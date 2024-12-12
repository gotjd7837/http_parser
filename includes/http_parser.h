#ifndef HTTP_PARSER_H
# define HTTP_PARSER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "list.h"

typedef struct
{
    char    *method;
    char    *http_version;
    char    *path;
    t_list  *query;
    char    *fragment;
    t_list  *headers;
    char    *garbage;
}   t_http_request;

t_http_request *http_parser(char *file);
t_http_request *http_parser_init(void);

void            http_parser_load(t_http_request *data, char *file);
void            http_parser_load_start_line(t_http_request *data, int fd);
void            http_parser_load_headers(t_http_request *data, int fd);

#endif