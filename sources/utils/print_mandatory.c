#include "utils.h"
#include "http_parser.h"

void print_mandatory(void *print_data)
{
    t_http_request  *data = (t_http_request *)print_data;
    t_list  *query = data->query;
    t_list  *headers = data->headers;

    printf("method : %s\n", data->method);
    printf("path : %s\n", data->path);
    printf("query : ");
    if (query == NULL)
        printf("none\n");
    else
    {
        while (query)
        {
            if (query->key)
                printf("%s", query->key);
            if (query->value)
                printf("=%s", query->value);
            query = query->next;
            if (query == NULL)
                break ;
            printf("&");
        }
        printf("\n");
    }
    printf("fragment : ");
    if (data->fragment == NULL)
        printf("none\n");
    else
        printf("%s\n", data->fragment);
    
    printf("version : %s\n", data->http_version);
    printf("headers : \n");
    while (headers)
    {
        printf("%s: ", headers->key);
        if (headers->value)
            printf("%s\n", headers->value);
        else
            printf("\n");
        headers = headers->next;
    }

    printf("\ngarbage : ");
    if (data->garbage == NULL)
        printf("none\n");
    else
        printf("%s\n", data->garbage);
}