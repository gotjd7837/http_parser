#include "list.h"
#include "utils.h"

t_list *list_new_node(char *key, char *value)
{
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);

    if (key)
        new_node->key = strdup(key);
    else
        new_node->key = NULL;
    if (value)
        new_node->value = strdup(value);
    else
        new_node->value = NULL;
    new_node->next = NULL;

    return (new_node);
}
