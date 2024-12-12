#include "http_parser.h"
#include "utils.h"

t_http_request *http_parser_init(void)
{
    t_http_request *data;

    data = (t_http_request *)malloc(sizeof(t_http_request));
    if (data == NULL)
        print_error("Error: malloc failed");

    data->method = NULL;
    data->http_version = NULL;
    data->path = NULL;
    data->query = NULL;
    data->fragment = NULL;
    data->headers = NULL;
    data->garbage = NULL;

    return (data);
}