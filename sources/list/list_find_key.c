#include "list.h"
#include "utils.h"

t_list *list_find_key(t_list *list, char *key)
{
    t_list *node;

    node = list;
    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
            return (node);
        node = node->next;
    }
    return (NULL);
}