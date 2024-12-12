#include "http_parser.h"
#include "utils.h"

/*
** query를 key, value로 나누어 저장
*/
static t_list  *http_parser_load_query(char *query)
{
    t_list  *query_list;
    char    **tokens;
    char    *key;
    char    *value;

    if (!query)
        print_error("Error: malloc failed");

    query_list = NULL;
    tokens = split(query, '&');
    if (!tokens)
        print_error("Error: split failed");

    for (int i = 0; tokens[i]; i++)
    {
        key = parse_key_query(tokens[i]);
        value = parse_value_query(tokens[i]);

        list_add_back(&query_list, list_new_node(key, value));

        if (key)
            free(key);
        if (value)
            free(value);
    }
    free_split(tokens);
    free(query);

    return (query_list);
}

/*
** uri를 path, query, fragment로 나누어 저장
*/
static void http_parser_load_uri(t_http_request *data, char *uri)
{
    char *path_start;
    char *query_start;
    char *fragment_start;

    path_start = uri;
    query_start = strchr(uri, '?');
    fragment_start = strchr(uri, '#');

    // query, fragment 둘 다 있는 경우
    if (query_start && fragment_start && query_start < fragment_start)
    {
        data->path = strndup(path_start, query_start - path_start);
        data->query = http_parser_load_query(strndup(query_start + 1, fragment_start - query_start - 1));
        data->fragment = strdup(fragment_start + 1);
    }
    // fragment에 '?'가 있는 경우
    else if (query_start && fragment_start && fragment_start < query_start)
    {
        data->path = strndup(path_start, fragment_start - path_start);
        data->fragment = strdup(fragment_start + 1);
    }
    // only query
    else if (query_start)
    {
        data->path = strndup(path_start, query_start - path_start);
        data->query = http_parser_load_query(strdup(query_start + 1));
    }
    // only fragment
    else if (fragment_start)
    {
        data->path = strndup(path_start, fragment_start - path_start);
        data->fragment = strdup(fragment_start + 1);
    }
    // only path
    else
        data->path = strdup(path_start);
}

/*
** start line을 parsing하여 저장
*/
void http_parser_load_start_line(t_http_request *data, int fd)
{
    char *line;
    char **tokens;

    // get start line
    line = get_next_line_crlf(fd);
    if (!line)
        print_error("Error: get_next_line_crlf failed");

    // SP 기준으로 split
    tokens = split(line, ' ');
    if (!tokens)
        print_error("Error: split failed");
    
    data->method = strdup(tokens[0]);
    http_parser_load_uri(data, tokens[1]);
    data->http_version = strdup(tokens[2]);

    free_split(tokens);
    free(line);
}