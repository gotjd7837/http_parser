#include "list.h"
#include "utils.h"

void   list_append_value(t_list *node, char *value)
{
    char *new_value;

    new_value = (char *)malloc(strlen(node->value) + strlen(value) + 2);
    if (new_value == NULL)
        print_error("Error: malloc failed");
    strcpy(new_value, node->value);
    strcat(new_value, ",");
    strcat(new_value, value);
    free(node->value);
    node->value = new_value;
}