#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define BUFFER_SIZE 10
# define RESET   "\033[0m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"

int     print_error(char *msg);
void    print_mandatory(void *print_data);
void    print_bonus(void *print_data);

char    *get_next_line_crlf(int fd);

char    **split(char *str, char c);
void    free_split(char **split);

char    *parse_key_query(char *query);
char    *parse_value_query(char *query);
char    *parse_key_header(char *header);
char    *parse_value_header(char *header);

#endif