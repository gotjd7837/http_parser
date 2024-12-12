#include "utils.h"

char *parse_key_header(char *header)
{
    char *key;
    int idx;

    if (strchr(header, ':') == NULL)
        print_error("Error: Header is not valid");   
    
    idx = 0;
    while (header[idx] != ':')
        idx++;
    
    key = strndup(header, idx);
    return (key);
}

char *parse_key_query(char *query)
{
    char    *key;
    int     idx;

    idx = 0;
    while (query[idx] && query[idx] != '=')
        idx++;

    key = strndup(query, idx);
    return (key);
}