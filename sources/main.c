#include "http_parser.h"
#include "utils.h"

int main(int ac, char **av)
{
    t_http_request *data;

    if (ac != 2)
        print_error("Usage: ./http_parser <http_request>");
    data = http_parser(av[1]);

    printf(GREEN "\nMandatory part\n" RESET);
    
    print_mandatory(data);

    printf(GREEN "\nBonus part\n" RESET);

    print_bonus(data);
    
    return 0;
}
