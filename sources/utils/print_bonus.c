#include "utils.h"
#include "http_parser.h"

void print_bonus(void *print_data)
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
        printf("\n");
        for (int i = 1; query; i++)
        {
            printf("%d. ", i);
            if (strcmp(query->key, ""))
                printf("name = \"%s\", ", query->key);
            else
                printf("name = none, ");
            
            if (query->value)
                printf("value = \"%s\"\n", query->value);
            else
                printf("value = none\n");
            
            query = query->next;
        }
    }
    printf("fragment : ");
    if (data->fragment == NULL)
        printf("none\n");
    else
        printf("%s\n", data->fragment);
    
    printf("version : %s\n", data->http_version);
    printf("headers : \n");
    for (int i = 1; headers; i++)
    {
        printf("%d. ", i);
        printf("name = \"%s\", ", headers->key);
        
        if (headers->value)
            printf("value = \"%s\"\n", headers->value);
        else
            printf("value = none\n");
        
        headers = headers->next;
    }

    printf("\ngarbage : ");
    if (data->garbage == NULL)
        printf("none\n");
    else
        printf("%s\n", data->garbage);
}