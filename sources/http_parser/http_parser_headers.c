#include "http_parser.h"
#include "utils.h"

/*
** header를 key, value로 나누어 저장
*/
void http_parser_load_headers(t_http_request *data, int fd)
{
    char    *line;
    char    *key;
    char    *value;
    t_list  *node;

    while (1)
    {
        line = get_next_line_crlf(fd);
        if (!line)
            print_error("Error: header must end with CRLF");
        if (strcmp(line, "") == 0) // 헤더 끝 CRLF
        {
            free(line);
            break;
        }
        
        key = parse_key_header(line);
        value = parse_value_header(line);
        if (key == NULL)
            print_error("Error: hearder key is NULL");

        node = list_find_key(data->headers, key);
        if (node == NULL)
            list_add_back(&data->headers, list_new_node(key, value));
        else // 중복 key 처리
            list_append_value(node, value);

        if (key)
            free(key);
        if (value)
            free(value);
        free(line);
    }
}