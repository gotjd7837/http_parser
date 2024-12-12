#include "list.h"
#include "utils.h"

void    list_add_back(t_list **head, t_list *new_node)
{
    t_list *node;

    node = *head;
    if (head == NULL || new_node == NULL)
        print_error("Error: malloc failed");
    if (*head == NULL)
        *head = new_node;
    else
    {
        while (node->next != NULL)
            node = node->next;
        node->next = new_node;
    }
}