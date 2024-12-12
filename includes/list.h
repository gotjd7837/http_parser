#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
    char                *key;
    char                *value;
    struct s_list       *next;
}   t_list;

t_list  *list_new_node(char *key, char *value);
void    list_add_back(t_list **head, t_list *new_node);
t_list  *list_find_key(t_list *list, char *key);
void    list_append_value(t_list *node, char *value);

#endif