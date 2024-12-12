#include "utils.h"

char *parse_value_header(char *header)
{
    char *value;
    int idx;

    if (strchr(header, ':') == NULL)
        print_error("Error: header is not valid");
    
    idx = 0;
    while (header[idx] != ':')
        idx++;
    idx++;
    
    while (header[idx] == ' ' || header[idx] == '\t')
        idx++;
    
    value = strdup(header + idx);
    return (value);
}

char *parse_value_query(char *query)
{
    char    *value;
    int     idx;

    if (strchr(query, '=') == NULL)
        return (NULL);
    
    idx = 0;
    while (query[idx] != '=')
        idx++;
    idx++;

    if (query[idx] == '\0')
        return (NULL);
    
    value = strdup(query + idx);
    return (value);
}