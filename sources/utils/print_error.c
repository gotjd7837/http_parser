#include "utils.h"

int print_error(char *msg)
{
    printf(YELLOW "%s\n" RESET, msg);
    exit(1);
    return (1);
}