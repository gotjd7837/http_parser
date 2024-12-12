#include "http_parser.h"

t_http_request *http_parser(char *file)
{
    t_http_request  *data;

    data = http_parser_init();
    http_parser_load(data, file);
    return (data);
}